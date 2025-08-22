// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UDynamicMesh.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "GameFramework/Actor.h"
#include "Isocahedron.generated.h"

const float TAU = ((1 + sqrt(5))/2);

UCLASS()
class BIGLITTLEPLANET_API AIsocahedron : public AActor
{
	GENERATED_BODY()

private:
	float _worldScale = 2000.f;
	float _tauScaled = TAU * _worldScale;

	TArray<FVector> vertexPositions = {
	{-1 * _worldScale, _tauScaled,0},
	{ 1 * _worldScale, _tauScaled,0},
	{-1 * _worldScale,-_tauScaled,0},
	{ 1 * _worldScale,-_tauScaled,0},

	{0,-1 * _worldScale, _tauScaled},
	{0, 1 * _worldScale, _tauScaled},
	{0,-1 * _worldScale,-_tauScaled},
	{0, 1 * _worldScale,-_tauScaled},

	{ _tauScaled,0,-1 * _worldScale},
	{ _tauScaled,0, 1 * _worldScale},
	{-_tauScaled,0,-1 * _worldScale},
	{-_tauScaled,0, 1 * _worldScale},
	};

	TArray<TArray<int>> icoshedronFaces = {
		{0, 11, 5},
		{0, 5, 1},
		{0, 1, 7},
		{0, 7, 10},
		{0, 10, 11},
		
		{1, 5, 9},
		{5, 11, 4},
		{11, 10, 2},
		{10, 7, 6},
		{7, 1, 8},

		{3, 9, 4},
		{3, 4, 2},
		{3, 2, 6},
		{3, 6, 8},
		{3, 8, 9},

		{4, 9, 5},
		{2, 4, 11},
		{6, 2, 10},
		{8, 6, 7},
		{9, 8, 1}
	};

	FDynamicMesh3 _dynamMeshData = FDynamicMesh3();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDynamicMesh* Mesh;

public:	
	// Sets default values for this actor's properties
	AIsocahedron();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector GetMiddle(FVector& vectorA, FVector& vectorB);

	void SubdivideIcosahedron(TArray<FVector>& currentVertices, TArray<TArray<int>>& currentIndexs);



};
