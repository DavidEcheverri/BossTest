// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "B_Weapon.generated.h"

class UCapsuleComponent;
class AB_Character;

UCLASS()
class BOSS_API AB_Weapon : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UCapsuleComponent* AttackDetector;

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	float Attack;

private:

	AB_Character* CharacterUser;
private:

	void InitializeReferences();

	UFUNCTION()
	void MakeDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Sets default values for this actor's properties
	AB_Weapon();

	void SetDetectorCollision(ECollisionEnabled::Type NewCollisionState);

	void SetUser(AB_Character* Character);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
