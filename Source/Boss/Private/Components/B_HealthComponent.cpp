// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/B_HealthComponent.h"

// Sets default values for this component's properties
UB_HealthComponent::UB_HealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	MaxHealth = 100.0f;
	Health = MaxHealth;
}


// Called when the game starts
void UB_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

	MyOwner = GetOwner();

	Health = MaxHealth;
	if (IsValid(MyOwner))
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &UB_HealthComponent::TakingDamage);
	}
}

void UB_HealthComponent::TakingDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f) 
	{
		return;
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

	if (Health == 0.0f) 
	{
		bIsDead = true;
	}

	OnHealthChangeDelegate.Broadcast(this);
}


// Called every frame
void UB_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

