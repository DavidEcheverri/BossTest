// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "B_EnemyHealthBar.generated.h"

/**
 * 
 */
class AB_Troll;
UCLASS()
class BOSS_API UB_EnemyHealthBar : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(BlueprintReadOnly, Category = "Setup")
	float HealthPercent;

	UPROPERTY(BlueprintReadOnly, Category = "Setup")
	FLinearColor HealthColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Setup")
	FLinearColor FullHealthColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Setup")
	FLinearColor EmptyHealthColor;

public:

	UFUNCTION(BlueprintCallable)
	void InitializeWidget(AB_Troll* Enemy);

	UFUNCTION()
	void UpdateHealth(float CurrentHealth, float MaxHealth);
};
