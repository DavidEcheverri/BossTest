// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/B_EnemyHealthBar.h"
#include "Enemys/B_Troll.h"
#include "Components/B_HealthComponent.h"

void UB_EnemyHealthBar::InitializeWidget(AB_Troll* Enemy)
{

	if (IsValid(Enemy))
	{
		UB_HealthComponent* HealthComponent = Enemy->GetHealthComponent();
		if (IsValid(HealthComponent))
		{
			HealthComponent->OnHealthUpdateDelegate.AddDynamic(this, &UB_EnemyHealthBar::UpdateHealth);
		}
	}
}

void UB_EnemyHealthBar::UpdateHealth(float CurrentHealth, float MaxHealth)
{
	HealthPercent = CurrentHealth / MaxHealth;
	HealthColor = FMath::Lerp(EmptyHealthColor, FullHealthColor, HealthPercent);
}
