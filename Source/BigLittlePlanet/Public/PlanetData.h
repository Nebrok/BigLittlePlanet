// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class BIGLITTLEPLANET_API PlanetData
{

public:
	PlanetData(int distance, int ironResource, int woodResource, int dangerRating0to100, int richRating0to100);
	~PlanetData();

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
