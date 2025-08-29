// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGridGenerator.h"

// Sets default values
AHexGridGenerator::AHexGridGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHexGridGenerator::BeginPlay()
{
	Super::BeginPlay();
	
	GenerateTiles();
}

// Called every frame
void AHexGridGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHexGridGenerator::GenerateTiles()
{
	for (int i = 0; i < rangeToSpawn; i++) 
	{
		for (int j = 0; j < rangeToSpawn; j++)
		{
			nodes.Add(new HexNode);

			int randomTileIndex = rand() % allTiles.Num();

			FActorSpawnParameters spawnInfo;
			GetWorld()->SpawnActor<AHexTile>(allTiles[randomTileIndex], FVector(i * hexHeight + (j % 2) * hexHeight / 2, 
																				j * hexWidth, 
																				0), FRotator(0, 0, 0), spawnInfo);
		}
	}
}

