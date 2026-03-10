// Fill out your copyright notice in the Description page of Project Settings.


#include "IWCharacter.h"

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

}

