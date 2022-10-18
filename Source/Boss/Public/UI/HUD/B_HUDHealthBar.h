// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "B_HUDHealthBar.generated.h"

/**
 * 
 */
UCLASS()
class BOSS_API UB_HUDHealthBar : public UUserWidget
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
	void InitializeWidget(AB_Character* Character);

	UFUNCTION()
	void UpdateHealth(float CurrentHealth, float MaxHealth);

};
