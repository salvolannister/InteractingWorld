// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/Character.h>
#include <InteractingWorld/InteractingWorldCharacter.h>
#include <UObject/ObjectPtr.h>

#include "IWCharacter.generated.h"

UCLASS()
class INTERACTINGWORLD_API AIWCharacter : public AInteractingWorldCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AIWCharacter();

	void Attack();

private:

	UPROPERTY(EditAnywhere, Category = "InteractableWorld | Character| Input")
	TObjectPtr<class UInputAction> AttackInput;

	UPROPERTY(EditAnywhere, Category =  "InteractableWorld| Character| Animation")
	TObjectPtr<class UAnimMontage> AttackPrimaryAnimation;

#pragma region "ACharacter Interface"
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

#pragma endregion
};
