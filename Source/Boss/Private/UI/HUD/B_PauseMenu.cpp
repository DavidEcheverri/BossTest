// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/B_PauseMenu.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void UB_PauseMenu::Init()
{
	BP_Initialize();
	bIsInited = true;
}

void UB_PauseMenu::ContinueGame()
{
	BP_ContinueGame();
}

void UB_PauseMenu::PauseActivate()
{
	BP_PauseActivate();
}

void UB_PauseMenu::Quit()
{
	BP_Quit();
	UGameplayStatics::OpenLevel(GetWorld(), MainMenuName);
}
