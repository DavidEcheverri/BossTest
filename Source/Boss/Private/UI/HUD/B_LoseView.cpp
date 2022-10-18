// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/B_LoseView.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"


void UB_LoseView::RestartLevel()
{
	BP_RestartLevel();
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void UB_LoseView::Quit()
{
	BP_Quit();
	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
}
