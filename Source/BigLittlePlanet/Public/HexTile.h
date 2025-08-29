// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexNode.h"
#include "HexTile.generated.h"

UENUM(BlueprintType)
enum class ETileEdge : uint8
{
	Empty UMETA(DisplayName = "Empty"),
	Road UMETA(DisplayName = "Road"),
	Water UMETA(DisplayName = "Water")
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ETileEdge> tileEdges;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh;

	HexNode* node;
};
