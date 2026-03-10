// Fill out your copyright notice in the Description page of Project Settings.

// File include
#include "IWPlayerController.h"

// Engine includes
#include "EnhancedInputComponent.h"
#include "GameFramework/PlayerController.h"

// Game include
#include "IWHud.h"

void AIWPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	
}

void AIWPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (InventoryInputAction)
		{
			AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
			if (!GameMode)
			{
				return;
			}

			AIWHud* iwHud = GetHUD<AIWHud>();
			if (IsValid(iwHud))
			{
				EnhancedInput->BindAction(InventoryInputAction, ETriggerEvent::Started, iwHud, &AIWHud::OpenInventory);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to get IW Hud"));
			}
		}
	}
}