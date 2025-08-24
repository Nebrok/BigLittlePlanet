// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinningMoon.h"

// Sets default values
ASpinningMoon::ASpinningMoon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpinningMoon::BeginPlay()
{
	Super::BeginPlay();

	startRot = GetActorRotation();
}

// Called every frame
void ASpinningMoon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	upAngleAxis += DeltaTime * speedMultiplier;
	
	SetActorLocation(GetActorLocation() + FVector(0,0, FMath::Sin(DeltaTime * speedMultiplier) * rotationOffsetMultiplier));

	FRotator newRotation = FRotator(startRot.Pitch, upAngleAxis, startRot.Yaw);

	FQuat quatRot = FQuat(newRotation);

	SetActorRotation(quatRot);

}

