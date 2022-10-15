// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/B_Weapon.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Boss/Boss.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Public/B_Character.h"

// Sets default values
AB_Weapon::AB_Weapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	AttackDetector = CreateDefaultSubobject<UCapsuleComponent>(TEXT("AttackDetector"));
	AttackDetector->SetupAttachment(RootComponent);
	AttackDetector->SetCollisionResponseToAllChannels(ECR_Ignore);
	AttackDetector->SetCollisionResponseToChannel(COLLISION_ENEMY, ECR_Overlap);
	AttackDetector->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AB_Weapon::SetDetectorCollision(ECollisionEnabled::Type NewCollisionState)
{
	AttackDetector->SetCollisionEnabled(NewCollisionState);
}

void AB_Weapon::SetUser(AB_Character* Character)
{
	CharacterUser = Character;
}

// Called when the game starts or when spawned
void AB_Weapon::BeginPlay()
{
	Super::BeginPlay();
	InitializeReferences();
}

void AB_Weapon::InitializeReferences()
{
	AttackDetector->OnComponentBeginOverlap.AddDynamic(this, &AB_Weapon::MakeDamage);
}

void AB_Weapon::MakeDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(OtherActor)) 
	{
		UGameplayStatics::ApplyDamage(OtherActor, Attack,CharacterUser->GetInstigatorController(),this,nullptr);
	}
}

// Called every frame
void AB_Weapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

