// Fill out your copyright notice in the Description page of Project Settings.

// File include
#include "IWCharacter.h"

#include <Animation/AnimMontage.h>
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>



void AIWCharacter::Attack()
{
	UE_LOG(LogTemp, Verbose, TEXT("IW: Attack"));

	if (IsValid(AttackPrimaryAnimation))
	{
		PlayAnimMontage(AttackPrimaryAnimation);
	}
}


#pragma region "ACharacter Interface"
// Sets default values
AIWCharacter::AIWCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIWCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIWCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIWCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enanchedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (enanchedInput)
	{
		if (IsValid(AttackInput))
		{
			enanchedInput->BindAction(AttackInput, ETriggerEvent::Triggered, this, &AIWCharacter::Attack);
		}

	}
	else
	{
		UE_LOG(LogTemp, Verbose, TEXT("Enanched input not working in PlayerController"))
	}

}

#pragma endregion
