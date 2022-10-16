// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "B_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOSS_API AB_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:

	UFUNCTION()
	void Victory();

	UFUNCTION()
	void GameOver();
};
