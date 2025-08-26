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

}


void AEmbarkManager::AddFoundPlanet()
{
	PlanetData* newPlanet = new PlanetData(10, 10, 10, 10, 50);

	FoundPlanets.Add(newPlanet);
}


void AEmbarkManager::EmbarkExpidition(USpaceShipData* spaceShip, int crewmates, int planetIndex)
{
	AddFoundPlanet();

	PlanetData* targetPlanet = FoundPlanets[planetIndex];

	UE_LOG(LogTemp, Display, TEXT("Embarking"));

}
