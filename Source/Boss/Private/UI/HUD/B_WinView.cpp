// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/B_WinView.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void UB_WinView::Initialize(APlayerController* PlayerController)
{
	BP_Initialize();
}

void UB_WinView::BackMainMenu()
{
	BP_BackMainMenu();
	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
}

void UB_WinView::Quit()
{
	BP_Quit();
	UGameplayStatics::OpenLevel(GetWorld(), MainMenuName);
}
