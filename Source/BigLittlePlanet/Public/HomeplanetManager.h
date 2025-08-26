// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "HomeplanetManager.generated.h"

/**
 * 
 */


UCLASS()
class BIGLITTLEPLANET_API UHomeplanetManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	int currentDay = 1;

	UPROPERTY(BlueprintReadWrite)
	int totalCrewmates = 3;

	UPROPERTY(BlueprintReadWrite)
	int totalCrewmateCapacity = 10;

	UPROPERTY(BlueprintReadWrite)
	int totalFood = 5;

	UPROPERTY(BlueprintReadWrite)
	int totalMoney = 50000;

	UPROPERTY(BlueprintReadWrite)
	int moneyCostPerDay = 100;
	
	UPROPERTY(BlueprintReadWrite)
	int totalIron = 5;

	UPROPERTY(BlueprintReadWrite)
	int totalWood = 5;

};
