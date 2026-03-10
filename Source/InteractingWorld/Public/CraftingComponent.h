// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine compopenet
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "CraftingComponent.generated.h"


UCLASS(DefaultToInstanced, BlueprintType, Blueprintable, meta = (ShortTooltip = "Use it to enable crafting on an Actor"))
class INTERACTINGWORLD_API UCraftingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCraftingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> CraftingWidget;

	UPROPERTY(BlueprintReadWrite, Transient)
	TObjectPtr<class UUserWidget> CachedWidgetInstance;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category ="InteractableWorld|Crafting")
	bool HideShowCraftingMenu();
};
