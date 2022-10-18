// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "B_MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSS_API UB_MainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main Menu")
	FName GameplayLevelName;

protected:

	UFUNCTION(BlueprintCallable, Category = "Main Menu")
	void StartGameplay();

	UFUNCTION(BlueprintCallable, Category = "Main Menu")
	void Quit();

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu")
	void BP_StartGameplay();

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu")
	void BP_Quit();

};
