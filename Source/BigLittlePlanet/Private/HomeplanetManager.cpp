// Fill out your copyright notice in the Description page of Project Settings.


#include "HomeplanetManager.h"

void UHomeplanetManager::AddFoundPlanet()
{
	PlanetData* newPlanet = new PlanetData(10, 10, 10, 10, 50);

	FoundPlanets.Add(newPlanet);
}

void UHomeplanetManager::EmbarkExpidition(USpaceShipData* spaceShip, int crewmates, int planetIndex)
{
	AddFoundPlanet();

	PlanetData* targetPlanet = FoundPlanets[planetIndex];

	UE_LOG(LogTemp, Display, TEXT("Embarking"));

}
