// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryMenu.h"

#include <Animation/WidgetAnimation.h>
#include <Animation/WidgetAnimationEvents.h>
#include <Logging/LogVerbosity.h>

void UInventoryMenuWidget::NativeConstruct()
{
	Super::Construct();

	if (IsValid(BlendIn))
	{
		UE_LOG(LogTemp, Verbose, TEXT("Going to play animation blend in"));
		PlayAnimation(BlendIn, 0.f);
	}
}

void UInventoryMenuWidget::PlayClosingAnimation()
{
	if (IsValid(BlendOut))
	{
		PlayAnimation(BlendOut, 0.f);
	}
}

void UInventoryMenuWidget::RegisterToBlendOutAnimFinished( FWidgetAnimationDynamicEvent& Delegate)
{
	if (!IsValid(BlendOut))
	{
		UE_LOG(LogTemp, Verbose, TEXT("[Anim] blend out animation is null"));
		return;
	}

	this->BindToAnimationFinished(BlendOut, Delegate);
}

void UInventoryMenuWidget::UnregisterFromBlendOutAnimFinished( FWidgetAnimationDynamicEvent& Delegate)
{
	if (!IsValid(BlendOut))
	{
		UE_LOG(LogTemp, Verbose, TEXT("[Anim] blend out animation is null"));
		return;
	}

	UnbindFromAnimationFinished(BlendOut, Delegate);
}