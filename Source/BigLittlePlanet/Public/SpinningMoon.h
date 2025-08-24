// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinningMoon.generated.h"

UCLASS()
class BIGLITTLEPLANET_API ASpinningMoon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinningMoon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float upAngleAxis;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float orbitSpeedMultiplier = 50;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float selfAxisRotSpeedMult = 10;

	FRotator startRot;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
