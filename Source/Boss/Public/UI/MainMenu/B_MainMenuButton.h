// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "B_MainMenuButton.generated.h"


UENUM()
enum class EB_ButtonStyleType : uint8 
{
	ButtonStyleType_Mouse			UMETA(DisplayName = "Selected by Mouse"),
	ButtonStyleType_KeySelected		UMETA(DisplayName = "Selected by Keyboard"),
	ButtonStyleType_KeyNotSelected	UMETA(DisplayName = "Not Selected by Keyboard")
};

UCLASS()
class BOSS_API UB_MainMenuButton : public UButton
{
	GENERATED_BODY()

public: 

	UB_MainMenuButton();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Main Menu Button")
	float CheckFocusRate;

	FTimerHandle TimerHandler_CheckFocus;

protected:

	UFUNCTION(BlueprintCallable, Category = "Main Menu Button")
	void Start();

	void CheckFocus();

	void SetButtonStyle(EB_ButtonStyleType NewStyleType);

	UFUNCTION(BlueprintImplementableEvent, Category = "Main Menu Button")
	void BP_SetButtonStyle(EB_ButtonStyleType NewStyleType);
};
