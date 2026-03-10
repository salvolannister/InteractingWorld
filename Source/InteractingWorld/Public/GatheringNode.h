// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine headers
#include "CoreMinimal.h"

// Game headers.
#include "InteractableActor.h"
#include "ItemData.h"

#include "GatheringNode.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTINGWORLD_API AGatheringNode : public AInteractableActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	float Quantity = 1;

	UPROPERTY(EditAnywhere)
	FItemData Item;

};
