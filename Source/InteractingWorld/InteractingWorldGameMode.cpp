// Copyright Epic Games, Inc. All Rights Reserved.

#include "InteractingWorldGameMode.h"
#include "InteractingWorldCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInteractingWorldGameMode::AInteractingWorldGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
