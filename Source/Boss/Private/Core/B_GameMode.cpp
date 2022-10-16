// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/B_GameMode.h"

void AB_GameMode::GameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("GameOver"));
}

void AB_GameMode::Victory()
{
	UE_LOG(LogTemp, Warning, TEXT("Victory"));
}