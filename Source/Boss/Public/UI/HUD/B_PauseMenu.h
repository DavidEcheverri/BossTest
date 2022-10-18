// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "B_PauseMenu.generated.h"

/**
 * 
 */
class APlayerController;

UCLASS()
class BOSS_API UB_PauseMenu : public UUserWidget
{
	GENERATED_BODY()
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pause Menu")
	FName MainMenuName;

	UPROPERTY(BlueprintReadOnly, Category = "Pause Menu")
	APlayerController* PlayerControllerRef;

protected:

	UFUNCTION(BlueprintCallable, Category = "Pause Menu")
	void Initialize(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category = "Pause Menu")
	void ContinueGame();

	UFUNCTION(BlueprintCallable, Category = "Pause Menu")
	void PauseActivate();

	UFUNCTION(BlueprintCallable, Category = "Pause Menu")
	void Quit();

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Pause Menu")
	void BP_ContinueGame();

	UFUNCTION(BlueprintImplementableEvent, Category = "Pause Menu")
	void BP_Quit();

	UFUNCTION(BlueprintImplementableEvent, Category = "Pause Menu")
	void BP_PauseActivate();

	UFUNCTION(BlueprintImplementableEvent, Category = "Pause Menu")
	void BP_Initialize();
};
