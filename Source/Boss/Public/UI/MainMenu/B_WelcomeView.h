// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "B_WelcomeView.generated.h"

/**
 * 
 */
UCLASS()
class BOSS_API UB_WelcomeView : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void BP_GoToMainMenu();

};
