// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexNode.h"
#include "HexTile.generated.h"

UENUM(BlueprintType)
enum TileEdge
{
	Empty,
	Road,
	Water
};

UCLASS()
class BIGLITTLEPLANET_API AHexTile : public AActor
{
	GENERATED_BODY()
	
public:	

	AHexTile();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UStaticMesh* Mesh;
	HexNode* node;
	TArray<TileEdge> tileEdges[6];

};
