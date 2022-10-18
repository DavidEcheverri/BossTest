// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "B_WinView.generated.h"

/**
 * 
 */
UCLASS()
class BOSS_API UB_WinView : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Win Screen")
	FName MainMenuName;

	UPROPERTY(BlueprintReadOnly, Category = "Win Screen")
	APlayerController* PlayerControllerRef;

protected:

	UFUNCTION(BlueprintCallable, Category = "Win Screen")
	void Initialize(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category = "Win Screen")
	void BackMainMenu();

	UFUNCTION(BlueprintCallable, Category = "Win Screen")
	void Quit();

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Win Screen")
	void BP_BackMainMenu();

	UFUNCTION(BlueprintImplementableEvent, Category = "Win Screen")
	void BP_Quit();

	UFUNCTION(BlueprintImplementableEvent, Category = "Win Screen")
	void BP_Initialize();
};
