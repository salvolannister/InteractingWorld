// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine Headers
#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Interactable.generated.h"

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INTERACTINGWORLD_API IInteractable
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintImplementableEvent)
	bool CanInteract(const AActor* Interactor) const;

	UFUNCTION(BlueprintImplementableEvent)
	void Interact(AActor* Interactor);
};
