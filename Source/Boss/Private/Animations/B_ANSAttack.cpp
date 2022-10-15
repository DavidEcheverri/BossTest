// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/B_ANSAttack.h"
#include "Character/Public/B_Character.h"

void UB_ANSAttack::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{

}

void UB_ANSAttack::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AActor* CharacterActor = MeshComp->GetOwner();

	if (IsValid(CharacterActor)) 
	{
		AB_Character* Character = Cast<AB_Character>(CharacterActor);
		if (IsValid(Character)) 
		{
			Character->EndAttack();
		}
	}
}
