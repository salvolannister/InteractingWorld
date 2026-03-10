// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Animation/WidgetAnimationEvents.h>
#include <Blueprint/UserWidget.h>
#include <CoreMinimal.h>

#include "InventoryMenu.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTINGWORLD_API UInventoryMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
	TObjectPtr<class UWidgetAnimation> BlendIn;

	UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
	TObjectPtr<class UWidgetAnimation> BlendOut;

public:
	void RegisterToBlendOutAnimFinished( FWidgetAnimationDynamicEvent& Delegate);

	void UnregisterFromBlendOutAnimFinished(FWidgetAnimationDynamicEvent& Delegate);

	void PlayClosingAnimation();
};
