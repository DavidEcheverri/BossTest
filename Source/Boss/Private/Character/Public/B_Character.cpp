// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Public/B_Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Weapons/B_Weapon.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Components/B_HealthComponent.h"
#include "Core/B_GameMode.h"

// Sets default values
AB_Character::AB_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.f; // Camera follows at this distance
	CameraBoom->bUsePawnControlRotation = true; // Rotate Arm based on controller

	//Set size for collision capsule
	GetCapsuleComponent()->SetCapsuleSize(40.f, 100.f);

	//Create Follow Camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	//Attach the camera to the end of the boom and let the boom adjust to match
	//the controller orientation
	FollowCamera->bUsePawnControlRotation = false;
	//Set our turn rate for input
	BaseTurnRate = 65.f;
	BaseLookUpRate = 65.f;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; //CharacterMove in the direction input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f, 0.0f); // ... at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 650.f;
	GetCharacterMovement()->AirControl = 0.2f;

	HealthComponent = CreateDefaultSubobject<UB_HealthComponent>(TEXT("HealthComponent"));

}

// Called when the game starts or when spawned
void AB_Character::BeginPlay()
{
	Super::BeginPlay();
	InitializeReferences();
	CreateInitialWeapon();
}

void AB_Character::InitializeReferences()
{
	GameModeReference = Cast<AB_GameMode>(GetWorld()->GetAuthGameMode());
	HealthComponent->OnHealthChangeDelegate.AddDynamic(this, &AB_Character::OnHealthChange);
	if (IsValid(GetMesh())) 
	{
		MyAnimInstance = GetMesh()->GetAnimInstance();
	}
}

// Called every frame
void AB_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AB_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AB_Character::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AB_Character::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AB_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AB_Character::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUP", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AB_Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AB_Character::LookUpAtRate);

	PlayerInputComponent->BindAction("Attack_1", IE_Pressed, this, &AB_Character::FirstAttack);
	PlayerInputComponent->BindAction("Attack_1", IE_Released, this, &AB_Character::FirstAttack);

	PlayerInputComponent->BindAction("Attack_2", IE_Pressed, this, &AB_Character::SecondAttack);
	PlayerInputComponent->BindAction("Attack_2", IE_Released, this, &AB_Character::SecondAttack);
}

void AB_Character::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f) && (!bAttacking))
	{
		//find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AB_Character::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f) && (!bAttacking))
	{
		//find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AB_Character::TurnAtRate(float Rate)
{

}

void AB_Character::LookUpAtRate(float Rate)
{
}

void AB_Character::FirstAttack()
{
	if (IsValid(MyAnimInstance) && IsValid(MeleeMontage) && !bAttacking) 
	{
		bAttacking = true;
		MyAnimInstance->Montage_Play(MeleeMontage);
		MyAnimInstance->Montage_JumpToSection(FName("Attack_1"), MeleeMontage);
	}
}

void AB_Character::SecondAttack()
{
	if (IsValid(MyAnimInstance) && IsValid(MeleeMontage) && !bAttacking)
	{
		bAttacking = true;
		MyAnimInstance->Montage_Play(MeleeMontage);
		MyAnimInstance->Montage_JumpToSection(FName("Attack_2"), MeleeMontage);
	}
}

void AB_Character::ActiveColliderAttack()
{
	if (CurrentWeapon) 
	{
		CurrentWeapon->SetDetectorCollision(ECollisionEnabled::QueryOnly);
	}
}

void AB_Character::EndAttack()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->SetDetectorCollision(ECollisionEnabled::NoCollision);
	}
	bAttacking = false;
}

void AB_Character::CreateInitialWeapon()
{
	if (IsValid(InitialWeaponClass))
	{
		CurrentWeapon = GetWorld()->SpawnActor<AB_Weapon>(InitialWeaponClass, GetActorLocation(), GetActorRotation());
		const USkeletalMeshSocket* LefttHandSocket = GetMesh()->GetSocketByName("hand_rSocket");
		LefttHandSocket->AttachActor(CurrentWeapon, GetMesh());
		CurrentWeapon->SetUser(this);
	}
}

void AB_Character::Jump()
{
	if (!bAttacking)
	{
		Super::Jump();
	}
}

void AB_Character::OnHealthChange(UB_HealthComponent* MyHealthComponent)
{
	if (HealthComponent->IsDead())
	{
		GameModeReference->GameOver();
	}
}

