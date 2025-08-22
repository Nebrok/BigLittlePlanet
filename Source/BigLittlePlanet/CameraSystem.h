// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "CameraSystem.generated.h"

UCLASS()
class BIGLITTLEPLANET_API ACameraSystem : public APawn
{
	GENERATED_BODY()

public:
	
	ACameraSystem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* gamePlayCamera;

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* focusedPlanet; //change this to planet class
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2f lastFrameMousePos;

public:	
	
	void SetFocusedPlanet(UObject* focus);
	void Tick(float DeltaTime) override;



protected:

	void BeginPlay() override;
};
