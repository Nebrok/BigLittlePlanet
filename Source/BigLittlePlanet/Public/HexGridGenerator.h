// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.h"
#include "HexGridGenerator.generated.h"

UCLASS()
class BIGLITTLEPLANET_API AHexGridGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHexGridGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GenerateTiles();

	TArray<HexNode*> nodes;

	UPROPERTY(EditAnywhere)
	int rangeToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<class AHexTile>> allTiles;
};
