// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"
#include "Isocahedron.h"

// Sets default values
AIsocahedron::AIsocahedron()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void AIsocahedron::BeginPlay()
{
	Super::BeginPlay();
	SubdivideIcosahedron(vertexPositions, icoshedronFaces);
	SubdivideIcosahedron(vertexPositions, icoshedronFaces);
	SubdivideIcosahedron(vertexPositions, icoshedronFaces);
	
}

// Called every frame
void AIsocahedron::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (auto triangle : icoshedronFaces)
	{
		FVector Point0 = vertexPositions[triangle[0]];
		FVector Point1 = vertexPositions[triangle[1]];
		FVector Point2 = vertexPositions[triangle[2]];

		DrawDebugLine(GetWorld(), Point0, Point1, FColor(255, 255, 255));
		DrawDebugLine(GetWorld(), Point1, Point2, FColor(255, 255, 255));
		DrawDebugLine(GetWorld(), Point2, Point0, FColor(255, 255, 255));

	}

}

FVector AIsocahedron::GetMiddle(FVector& vectorA, FVector& vectorB)
{
	FVector tempVector = { 0,0,0 };
	
	tempVector = (vectorB - vectorA) * 0.5 + vectorA;

	tempVector.Normalize();
	tempVector *= sqrt(TAU*TAU+1)*_worldScale;

	return tempVector;
}

void AIsocahedron::SubdivideIcosahedron(TArray<FVector>& currentVertices, TArray<TArray<int>>& faces)
{
	TArray<FVector> updatedVertices = {};
	TArray<TArray<int>> updatedFaces = {};

	FVector newVector1;
	FVector newVector2;
	FVector newVector3;
	for (int i = 0; i < faces.Num(); i++)
	{
		newVector1 = GetMiddle(currentVertices[faces[i][0]], currentVertices[faces[i][1]]);
		newVector2 = GetMiddle(currentVertices[faces[i][1]], currentVertices[faces[i][2]]);
		newVector3 = GetMiddle(currentVertices[faces[i][2]], currentVertices[faces[i][0]]);

		//new Face 1
		updatedVertices.Add(newVector3);
		updatedVertices.Add(currentVertices[faces[i][0]]);
		updatedVertices.Add(newVector1);

		TArray<int> newFace = { updatedVertices.Num() - 3, updatedVertices.Num() - 2, updatedVertices.Num() - 1 };
		updatedFaces.Add(newFace);

		//new Face 2
		updatedVertices.Add(newVector1);
		updatedVertices.Add(currentVertices[faces[i][1]]);
		updatedVertices.Add(newVector2);

		newFace = { updatedVertices.Num() - 3, updatedVertices.Num() - 2, updatedVertices.Num() - 1 };
		updatedFaces.Add(newFace);

		//new Face 3
		updatedVertices.Add(newVector2);
		updatedVertices.Add(currentVertices[faces[i][2]]);
		updatedVertices.Add(newVector3);

		newFace = { updatedVertices.Num() - 3, updatedVertices.Num() - 2, updatedVertices.Num() - 1 };
		updatedFaces.Add(newFace);

		//new Face 4
		updatedVertices.Add(newVector1);
		updatedVertices.Add(newVector2);
		updatedVertices.Add(newVector3);

		newFace = { updatedVertices.Num() - 3, updatedVertices.Num() - 2, updatedVertices.Num() - 1 };
		updatedFaces.Add(newFace);
	}

	currentVertices = updatedVertices;
	faces = updatedFaces;
}


