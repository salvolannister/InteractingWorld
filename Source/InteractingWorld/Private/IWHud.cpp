// Subscribe to input mapping
// Fill out your copyright notice in the Description page of Project Settings.

// file include
#include "IWHud.h"

// engine include
#include <Blueprint/UserWidget.h>
#include <Components/WidgetComponent.h>
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <GameFramework/PlayerController.h>
#include <InputAction.h>
#include <InputMappingContext.h>

// Game include
#include "InventoryMenu.h"
#include "IWPlayerController.h"

void AIWHud::BeginPlay()
{
	Super::BeginPlay();
}

void AIWHud::OpenInventory(const FInputActionInstance& Instance)
{
	UUserWidget* CachedInventoryWidgetRaw = CachedInventoryWidget.Get();
	ToogleMenuVisibility(CachedInventoryWidgetRaw, InventoryWidgetClass);

	CachedInventoryWidget = CachedInventoryWidgetRaw;
}

bool AIWHud::ToogleMenuVisibility(UUserWidget*& MenuInstance, const TSubclassOf<UUserWidget>& MenuTemplate)
{
	if (!IsValid(MenuInstance))
	{
		MenuInstance = CreateMenuWidget(MenuTemplate);
	}

	ESlateVisibility currentVisibility = MenuInstance->GetVisibility();

	APlayerController* playerController = Cast<APlayerController>(GetOwner());
	if (!IsValid(playerController))
	{
		UE_LOG(LogTemp, Error, TEXT("Something went wrong: Failed to get player controller"));
		return false;
	}


	if (currentVisibility == ESlateVisibility::Visible)
	{

		UE_LOG(LogTemp, Verbose, TEXT("Setting visibility to collapsed"));


		UInventoryMenuWidget* inventoryWidget = Cast< UInventoryMenuWidget>(MenuInstance);
		if (IsValid(inventoryWidget))
		{
			FWidgetAnimationDynamicEvent delegate;
			delegate.BindDynamic(this, &AIWHud::CloseInventory);
			//inventoryWidget->UnregisterFromBlendOutAnimFinished(delegate);
			inventoryWidget->RegisterToBlendOutAnimFinished(delegate);
			inventoryWidget->PlayClosingAnimation();
		}
		else
		{
		MenuInstance->SetVisibility(ESlateVisibility::Collapsed);
		playerController->bShowMouseCursor = false;

		FInputModeGameOnly inputMode;
		playerController->SetInputMode(inputMode);
		MenuInstance->RemoveFromParent();

		playerController->SetPause(false);

		}

		return true;
	}
	else
	{
		UE_LOG(LogTemp, Verbose, TEXT("Setting visibility to visible"));
		MenuInstance->SetVisibility(ESlateVisibility::Visible);
		MenuInstance->AddToViewport();

		playerController->bShowMouseCursor = true;
		FInputModeGameAndUI inputMode;
		inputMode.SetWidgetToFocus(MenuInstance->TakeWidget());
		playerController->SetInputMode(inputMode);
		playerController->SetPause(true);

		return true;
	}

}

UUserWidget* AIWHud::CreateMenuWidget(const TSubclassOf<UUserWidget>& MenuTemplate)
{
	UWorld* world = GetWorld();
	if (!IsValid(world))
	{
		return nullptr;
	}

	UUserWidget* MenuInstance = CreateWidget(world, MenuTemplate);

	if (!IsValid(MenuInstance))
	{
		UE_LOG(LogTemp, Error, TEXT("Something went wrong: Failed to create the menu"));
		return nullptr;
	}

	return MenuInstance;
}

void AIWHud::CloseInventory()
{
	APlayerController* playerController = Cast<APlayerController>(GetOwner());
	if (!IsValid(playerController))
	{
		UE_LOG(LogTemp, Error, TEXT("Something went wrong: Failed to get player controller"));
		return ;
	}

	UInventoryMenuWidget* inventoryWidget = Cast< UInventoryMenuWidget>(CachedInventoryWidget);
	if (IsValid(inventoryWidget))
	{
		FWidgetAnimationDynamicEvent delegate;
		delegate.BindDynamic(this, &AIWHud::CloseInventory);
		inventoryWidget->UnregisterFromBlendOutAnimFinished(delegate);
	}

	CachedInventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
	playerController->bShowMouseCursor = false;

	FInputModeGameOnly inputMode;
	playerController->SetInputMode(inputMode);
	CachedInventoryWidget->RemoveFromParent();

	playerController->SetPause(false);
}