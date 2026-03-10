// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ObjectPtr.h"

#include "ItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture> ItemTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description = FText::FromString(TEXT("Item Description"));
};
