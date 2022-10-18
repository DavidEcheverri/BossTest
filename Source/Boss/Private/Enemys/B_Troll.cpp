// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemys/B_Troll.h"
#include "Components/B_HealthComponent.h"
#include "Core/B_GameMode.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Weapons/B_Weapon.h"
#include "Engine/SkeletalMeshSocket.h"

// Sets default values
AB_Troll::AB_Troll()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UB_HealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void AB_Troll::BeginPlay()
{
	Super::BeginPlay();
	
	HealthComponent->OnHealthChangeDelegate.AddDynamic(this, &AB_Troll::OnHealthChange);
	CreateInitialWeapon();
	InitializeReferences();
}

// Called every frame
void AB_Troll::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AB_Troll::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AB_Troll::OnHealthChange(UB_HealthComponent* MyHealthComponent)
{
	if (HealthComponent->IsDead()) 
	{
		GameModeReference->Victory();
	}
}

void AB_Troll::Attack()
{
	if (IsValid(MyAnimInstance) && IsValid(MeleeMontage) && !bAttacking)
	{
		int32 AttackSelected = FMath::RandRange(1, 2);
		bAttacking = true;
		MyAnimInstance->Montage_Play(MeleeMontage);
		MyAnimInstance->Montage_JumpToSection(FName("Attack_" + FString::FromInt(AttackSelected)), MeleeMontage);
	}
}

void AB_Troll::ActiveColliderAttack()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->SetDetectorCollision(ECollisionEnabled::QueryOnly);
	}
}

void AB_Troll::EndAttack()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->SetDetectorCollision(ECollisionEnabled::NoCollision);
	}
	bAttacking = false;
}

void AB_Troll::CreateInitialWeapon()
{
	if (IsValid(InitialWeaponClass))
	{
		CurrentWeapon = GetWorld()->SpawnActor<AB_Weapon>(InitialWeaponClass, GetActorLocation(), GetActorRotation());
		const USkeletalMeshSocket* LefttHandSocket = GetMesh()->GetSocketByName("b_MF_Weapon_R_Socket");
		LefttHandSocket->AttachActor(CurrentWeapon, GetMesh());
		CurrentWeapon->SetUser(this);
	}
}

void AB_Troll::InitializeReferences()
{
	if (IsValid(GetMesh()))
	{
		MyAnimInstance = GetMesh()->GetAnimInstance();
	}
	GameModeReference = Cast<AB_GameMode>(GetWorld()->GetAuthGameMode());

	if (IsValid(GameModeReference))
	{
		GameModeReference->SetTroll(this);
	}
}
