// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "PlayerCamera.generated.h"

UCLASS()
class BIGLITTLEPLANET_API APlayerCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCamera();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* gamePlayCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* focusedPlanet; //change this to planet class

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2f lastFrameMousePos;
	
private:

	float upAngleAxis;

	float rightAngleAxis;

	UPROPERTY(EditAnywhere)
	float multiplier = 50;

	FVector dimensions = FVector(1, 0, 0);

public:	

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UFUNCTION(BlueprintCallable)
	void MoveCamera(float DeltaTime);

};
