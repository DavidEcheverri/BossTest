// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "B_GameMode.generated.h"


class AB_Character;
class AB_Troll;

UCLASS()
class BOSS_API AB_GameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly)
	AB_Character* CharacterRef;


	UPROPERTY(BlueprintReadOnly)
	AB_Troll* TrollRef;

public:

	void SetCharacter(AB_Character* newCharacter);
	void SetTroll(AB_Troll* newTroll);

	UFUNCTION()
	void Victory();

	UFUNCTION()
	void GameOver();

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void BP_Victory();

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void BP_GameOver();

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void BP_SetEnemyToHub();

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void BP_SetPlayerToHub();
};
