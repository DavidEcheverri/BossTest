// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenu/B_MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"


void UB_MainMenuWidget::Quit()
{
	BP_Quit();
	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
}

void UB_MainMenuWidget::StartGameplay()
{
	BP_StartGameplay();
	UGameplayStatics::OpenLevel(GetWorld(), GameplayLevelName);
}
