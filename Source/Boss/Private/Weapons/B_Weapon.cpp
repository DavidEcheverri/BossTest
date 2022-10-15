// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/B_Weapon.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AB_Weapon::AB_Weapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	AttackDetector = CreateDefaultSubobject<UCapsuleComponent>(TEXT("AttackDetector"));
	AttackDetector->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AB_Weapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AB_Weapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

