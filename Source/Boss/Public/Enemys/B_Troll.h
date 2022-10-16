// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "B_Troll.generated.h"

class UB_HealthComponent;
class AB_GameMode;
class AB_Weapon;

UCLASS()
class BOSS_API AB_Troll : public ACharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UB_HealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* MeleeMontage;

	UAnimInstance* MyAnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<AB_Weapon> InitialWeaponClass;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
	AB_Weapon* CurrentWeapon;

	AB_GameMode* GameModeReference;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Anims")
	bool bAttacking;

public:

	UFUNCTION()
	void OnHealthChange(UB_HealthComponent* MyHealthComponent);

	UFUNCTION(BlueprintCallable)
	void Attack();

	void ActiveColliderAttack();

	void EndAttack();

	void CreateInitialWeapon();

public:
	// Sets default values for this character's properties
	AB_Troll();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
