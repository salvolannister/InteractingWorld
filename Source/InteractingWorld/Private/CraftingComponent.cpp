// Fill out your copyright notice in the Description page of Project Settings.

// File include
#include "CraftingComponent.h"

#include "Blueprint/UserWidget.h"

// Sets default values for this component's properties
UCraftingComponent::UCraftingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCraftingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCraftingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UCraftingComponent::HideShowCraftingMenu()
{
	if (!IsValid(CachedWidgetInstance))
	{
		UWorld* world = GetWorld();
		if (!IsValid(world))
		{
			return false;
		}

		CachedWidgetInstance = CreateWidget(world, CraftingWidget);

		if (!IsValid(CachedWidgetInstance))
		{
			UE_LOG(LogTemp, Error, TEXT("Something went wrong: Failed to create CraftingWidgetComponent."));
			return false;
		}
	}

	ESlateVisibility currentVisibility = CachedWidgetInstance->GetVisibility();

	APawn* pawn = Cast<APawn>(GetOwner());
	if (pawn)
	{
		APlayerController* playerController = Cast<APlayerController>(pawn->GetController());
		if (playerController)
		{
			if (currentVisibility == ESlateVisibility::Visible)
			{
				CachedWidgetInstance->SetVisibility(ESlateVisibility::Collapsed);

				playerController->bShowMouseCursor = false;
				FInputModeGameOnly inputMode;
				playerController->SetInputMode(inputMode);

				return false;
			}
			else
			{
				CachedWidgetInstance->SetVisibility(ESlateVisibility::Visible);
				CachedWidgetInstance->AddToViewport();

				playerController->bShowMouseCursor = true;
				//FInputModeUIOnly inputMode;
				//inputMode.SetWidgetToFocus(CachedWidgetComponent->TakeWidget());
				//playerController->SetInputMode(inputMode);

				return true;
			}

		}
	}
	return false;
}

