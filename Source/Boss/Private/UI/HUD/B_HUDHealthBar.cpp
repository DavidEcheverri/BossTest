// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/B_HUDHealthBar.h"
#include "Character/Public/B_Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/B_HealthComponent.h"

void UB_HUDHealthBar::InitializeWidget(AB_Character* Character)
{
	if (IsValid(Character))
	{
		UB_HealthComponent* PlayerHealthComponent = Character->GetHealthComponent();
		if (IsValid(PlayerHealthComponent))
		{
			PlayerHealthComponent->OnHealthUpdateDelegate.AddDynamic(this, &UB_HUDHealthBar::UpdateHealth);
		}
	}
}

void UB_HUDHealthBar::UpdateHealth(float CurrentHealth, float MaxHealth)
{
	HealthPercent = CurrentHealth / MaxHealth;
	HealthColor = FMath::Lerp(EmptyHealthColor, FullHealthColor, HealthPercent);
}
