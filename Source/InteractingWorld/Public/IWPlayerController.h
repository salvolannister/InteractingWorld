// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
// Generated header
#include "IWPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTINGWORLD_API AIWPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	const class UInputMappingContext* GetUIMappingContext() const;

	const class UInputAction* GetInventoryAction() const;

protected:

	UPROPERTY(EditAnywhere, Category = "Interactable World | Input")
	TObjectPtr<class UInputMappingContext> InventoryMappingContext;

	UPROPERTY(EditAnywhere, Category = "Interactable World | Input")
	TObjectPtr<class UInputAction> InventoryInputAction;

	void SetupInputComponent() override;

	// Called when the game starts
	virtual void BeginPlay() override;
};
