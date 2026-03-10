// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableActor.h"

// Engine headers.
#include <Blueprint/UserWidget.h>
#include <Components/SphereComponent.h>
#include <Components/WidgetComponent.h>
#include <DrawDebugHelpers.h>

// Sets default values
AInteractableActor::AInteractableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach a sphere collider with a specific radius
	CachedSphereCollider = CreateDefaultSubobject<USphereComponent>( TEXT("InteractionSphereCollider"));
	if (IsValid(CachedSphereCollider))
	{
		CachedSphereCollider->InitSphereRadius(InteractionRadius);
		CachedSphereCollider->SetupAttachment(RootComponent);
		//CachedSphereCollider->RegisterComponent();
	}


}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();

	// Create and attach a widget component
	if (IsValid(InteractorWidget))
	{
		UWorld* world = GetWorld();
		if (!IsValid(world))
		{
			return;
		}

		CachedWidgetComponent = CreateWidget(world, InteractorWidget);

		if (!IsValid(CachedWidgetComponent))
		{
			UE_LOG(LogTemp, Error, TEXT("Something went wrong: Failed to create CraftingWidgetComponent."));
			return;
		}
	}
}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#if WITH_EDITOR
	if (bDrawInteractionGizmo && IsValid(CachedSphereCollider))
	{
		DrawDebugSphere(
			GetWorld(),
			CachedSphereCollider->GetComponentLocation(),
			CachedSphereCollider->GetUnscaledSphereRadius(),
			24,
			FColor::Green,
			false,
			-1.f,
			0,
			2.f
		);
	}
#endif
}
