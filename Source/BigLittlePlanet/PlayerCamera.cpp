// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCamera.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCamera::MoveCamera(float DeltaTime)
{
	float mouseX;
	float mouseY;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mouseX, mouseY);

	upAngleAxis += DeltaTime * multiplier * (mouseX - lastFrameMousePos.X);
	rightAngleAxis += DeltaTime * multiplier * (lastFrameMousePos.Y - mouseY);

	if (rightAngleAxis > 60)
	{
		rightAngleAxis = 60;
	}
	else if (rightAngleAxis < -60)
	{
		rightAngleAxis = -60;
	}

	FRotator newRotation = FRotator(rightAngleAxis, upAngleAxis, 0);

	FQuat quatRot = FQuat(newRotation);

	SetActorRotation(quatRot);
}

// Called every frame
void APlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float mouseX;
	float mouseY;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mouseX, mouseY);
	
	lastFrameMousePos = FVector2f(mouseX, mouseY);

}

// Called to bind functionality to input
void APlayerCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

