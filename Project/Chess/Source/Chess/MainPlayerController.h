// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayer.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMainPlayerController();

	UPROPERTY(Transient, BlueprintReadWrite, meta=(DisplayName="Main Player Reference"))
	AMainPlayer* m_mainPlayerRef;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/*virtual void SetupPlayerInputComponent();

	void MoveUp();

	void MoveDown();
	
	void MoveRight();

	void MoveLeft();*/

};
