// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanetData.h"
#include "SpaceShipData.h"
#include "EmbarkManager.generated.h"

class Expedition;

UENUM(BlueprintType)
enum EmbarkState
{
	Idle,
	Embarking,
	Arrived,
	Returning
};

UCLASS()
class BIGLITTLEPLANET_API AEmbarkManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEmbarkManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void EmbarkExpidition(USpaceShipData* spaceShip, int crewmates, int planetIndex);

	void AddFoundPlanet();

	UFUNCTION(BlueprintCallable)
	float GetDistanceToTargetPlanet();

	UFUNCTION(BlueprintCallable)
	FString GetExpeditionStateString();

	TArray<PlanetData*> FoundPlanets;

	Expedition* CurrentExpedition;

	EmbarkState embarkState;
};

class BIGLITTLEPLANET_API Expedition
{

public:

	Expedition(PlanetData* expPlanet, USpaceShipData* expSpaceship, int crewMates)
	{
		CurrentTargetPlanet = expPlanet;
		CurrentSpaceShip = expSpaceship;
		distanceToTarget = expPlanet->distanceToUsLightyears;
		CurrentCrewMates = crewMates;
	}

	PlanetData* CurrentTargetPlanet;

	UPROPERTY()
	USpaceShipData* CurrentSpaceShip;

	UPROPERTY()
	int CurrentCrewMates;

	UPROPERTY()
	float distanceToTarget;
};
