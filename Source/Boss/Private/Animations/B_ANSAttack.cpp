// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/B_ANSAttack.h"
#include "Character/Public/B_Character.h"
#include "Enemys/B_Troll.h"

void UB_ANSAttack::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	AActor* Actor = MeshComp->GetOwner();

	//TODO Create base class attacker

	if (IsValid(Actor))
	{
		AB_Character* Character = Cast<AB_Character>(Actor);
		if (IsValid(Character))
		{
			Character->ActiveColliderAttack();
		}
		else 
		{
			AB_Troll* Troll = Cast<AB_Troll>(Actor);
			if (IsValid(Troll)) 
			{
				Troll->ActiveColliderAttack();
			}
		}
	}
}

void UB_ANSAttack::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AActor* Actor = MeshComp->GetOwner();

	if (IsValid(Actor)) 
	{
		AB_Character* Character = Cast<AB_Character>(Actor);
		if (IsValid(Character)) 
		{
			Character->EndAttack();
		}
		else
		{
			AB_Troll* Troll = Cast<AB_Troll>(Actor);
			if (IsValid(Troll))
			{
				Troll->EndAttack();
			}
		}
	}
}
