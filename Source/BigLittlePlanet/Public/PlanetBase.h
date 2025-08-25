// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanetBase.generated.h"

UCLASS()
class BIGLITTLEPLANET_API APlanetBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlanetBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int distanceToUsLightyears;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ironOnPlanet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int woodOnPlanet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	int dangerRating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	int richesRating;

};
