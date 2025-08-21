// Copyright Epic Games, Inc. All Rights Reserved.

#include "BigLittlePlanetGameMode.h"
#include "BigLittlePlanetCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABigLittlePlanetGameMode::ABigLittlePlanetGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
