// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SpaceShipData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class BIGLITTLEPLANET_API USpaceShipData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AActor* Ship;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int CrewCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int FoodCapacityKG;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int ItemCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int KilometersPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int ArmorStat;
	
};
