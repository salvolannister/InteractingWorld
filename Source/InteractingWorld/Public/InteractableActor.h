// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Engine include
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/ObjectPtr.h"

// Game include
#include "InteractingWorld/Interactable.h"

#include "InteractableActor.generated.h"

UCLASS()
class INTERACTINGWORLD_API AInteractableActor : public AActor, public IInteractable
{
	GENERATED_BODY()

//#pragma region IInteractable Interface
//public:
//
//	virtual bool CanInteract(const AActor* Interactor) const;
//
//	virtual void Interact(AActor* Interactor);
//
//#pragma endregion

public:
	// Sets default values for this actor's properties
	AInteractableActor();

protected:

	UPROPERTY(EditAnywhere, meta = (Units = "cm"))
	float InteractionRadius = 200.0f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> InteractorWidget;

	UPROPERTY(Transient)
	TObjectPtr<class UUserWidget> CachedWidgetComponent;

	UPROPERTY(EditAnywhere)
	bool bDrawInteractionGizmo = false;

	UPROPERTY(Transient)
	TObjectPtr<class USphereComponent> CachedSphereCollider;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
