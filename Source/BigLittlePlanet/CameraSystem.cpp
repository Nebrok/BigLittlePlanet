// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraSystem.h"

// Sets default values
ACameraSystem::ACameraSystem()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACameraSystem::BeginPlay()
{
}

void ACameraSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float mouseX;
	float mouseY;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mouseX, mouseY);
	
	lastFrameMousePos = FVector2f(mouseX, mouseY);

	UE_LOG(LogTemp, Display, TEXT("AAAAAAA"));
}

void ACameraSystem::SetFocusedPlanet(UObject* focus)
{
	
}
