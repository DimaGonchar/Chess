// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "MainPlayer.generated.h"

class UCameraComponent;


UCLASS()
class CHESS_API AMainPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	UCameraComponent* CameraRef;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveCameraForward(float Value);

	void MoveCameraBack(float Value);

	void MoveCameraRight(float Value);

	void MoveCameraLeft(float Value);

private:
	FVector m_movementDirection;
	bool m_bMoveForvard=false;

};
