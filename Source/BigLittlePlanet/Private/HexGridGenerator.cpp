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
		//We need a better way to do this
		//FActorSpawnParameters spawnInfo;
		//GetWorld()->SpawnActor<AHexTile>(FVector(i * 100, 0, 0), FRotator(0, 0, 0), spawnInfo);
	}
}

