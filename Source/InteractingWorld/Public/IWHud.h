// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <CoreMinimal.h>
#include <GameFramework/HUD.h>

#include "IWHud.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTINGWORLD_API AIWHud : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OpenInventory(const FInputActionInstance& Instance);


private:

	UPROPERTY(EditAnywhere, Category = "Interactable World | UI")
	TSubclassOf<class UUserWidget> InventoryWidgetClass;

	UPROPERTY(Transient)
	TObjectPtr<class UUserWidget> CachedInventoryWidget;

	UPROPERTY(EditAnywhere, meta = (Category = "Interactable World | UI"))
	TSubclassOf<class UUserWidget> CraftingWidgetClass;

	UPROPERTY(Transient)
	TObjectPtr<class UUserWidget> CachedCraftingWidget;


private:
	UPROPERTY(Transient)
	bool bDebugMenuActive = false;

	bool ToogleMenuVisibility(UUserWidget*& MenuInstance, const TSubclassOf<UUserWidget>& MenuTemplate);

	class UUserWidget* CreateMenuWidget(const TSubclassOf<UUserWidget>& MenuTemplate);

	UFUNCTION(BlueprintCallable)
	void CloseInventory();

public:
#pragma region "Unreal Interfaces"
	void BeginPlay() override;

#pragma endregion
};
