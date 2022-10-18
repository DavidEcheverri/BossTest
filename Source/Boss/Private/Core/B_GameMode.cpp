// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/B_GameMode.h"
#include "Enemys/B_Troll.h"
#include "Character/Public/B_Character.h"


void AB_GameMode::SetCharacter(AB_Character* newCharacter)
{
	if (IsValid(newCharacter)) 
	{
		CharacterRef = newCharacter;
		BP_SetPlayerToHub();
	}

}

void AB_GameMode::SetTroll(AB_Troll* newTroll)
{
	if (IsValid(newTroll)) 
	{
		TrollRef = newTroll;
		BP_SetEnemyToHub();
	}
}

void AB_GameMode::Victory()
{
	BP_Victory();
}

void AB_GameMode::GameOver()
{
	BP_GameOver();
}

