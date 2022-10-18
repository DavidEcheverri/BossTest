// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "B_LoseView.generated.h"

/**
 * 
 */
UCLASS()
class BOSS_API UB_LoseView : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lose Screen")
		FName MainMenuName;

protected:

	UFUNCTION(BlueprintCallable, Category = "Lose Screen")
	void RestartLevel();

	UFUNCTION(BlueprintCallable, Category = "Lose Screen")
	void Quit();

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Lose Screen")
		void BP_RestartLevel();

	UFUNCTION(BlueprintImplementableEvent, Category = "Lose Screen")
		void BP_Quit();
};
