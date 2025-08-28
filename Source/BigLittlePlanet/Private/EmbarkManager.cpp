// Fill out your copyright notice in the Description page of Project Settings.


#include "EmbarkManager.h"

// Sets default values
AEmbarkManager::AEmbarkManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEmbarkManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEmbarkManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (embarkState == EmbarkState::Embarking)
	{
		if (CurrentExpedition->distanceToTarget > 0)
		{
			CurrentExpedition->distanceToTarget -= CurrentExpedition->CurrentSpaceShip->LightyearsPerDay * DeltaTime / 10;
		}
		else
		{
			CurrentExpedition->distanceToTarget = 0;
			embarkState = EmbarkState::Arrived;
		}

	}

}


void AEmbarkManager::AddFoundPlanet()
{
	PlanetData* newPlanet = new PlanetData(10, 10, 10, 10, 50);

	FoundPlanets.Add(newPlanet);
}

float AEmbarkManager::GetDistanceToTargetPlanet()
{
	if (!embarkState == EmbarkState::Embarking)
	{
		return 0.0f;
	}

	return CurrentExpedition->distanceToTarget;
}

FString AEmbarkManager::GetExpeditionStateString()
{
	return UEnum::GetValueAsString(embarkState);
}


void AEmbarkManager::EmbarkExpidition(USpaceShipData* spaceShip, int crewmates, int planetIndex)
{
	if (embarkState != EmbarkState::Idle)
	{
		return;
	}

	AddFoundPlanet();

	delete(CurrentExpedition);
	CurrentExpedition = new Expedition(FoundPlanets[planetIndex], spaceShip, crewmates);

	embarkState = EmbarkState::Embarking;

	UE_LOG(LogTemp, Display, TEXT("Embarking"));

}
