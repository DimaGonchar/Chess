// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

AMainPlayerController::AMainPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

 void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	m_mainPlayerRef=Cast<AMainPlayer>(GetPawn());

	bShowMouseCursor=true;
}

 void AMainPlayerController::Tick(float DeltaTime)
 {
	 Super::Tick(DeltaTime);

 }

 //void AMainPlayerController::SetupPlayerInputComponent()
 //{
	// Super::SetupPlayerInputComponent();

	// InputComponent->BindAction(TEXT("Up"), EInputEvent::IE_Pressed, this, &AMainPlayerController::MoveUp);
	// InputComponent->BindAction(TEXT("Down"), EInputEvent::IE_Pressed, this, &AMainPlayerController::MoveDown);
	// InputComponent->BindAction(TEXT("Right"), EInputEvent::IE_Pressed, this, &AMainPlayerController::MoveRight);
	// InputComponent->BindAction(TEXT("Left"), EInputEvent::IE_Pressed, this, &AMainPlayerController::MoveLeft);
 //}

 //void AMainPlayerController::MoveUp()
 //{

 //}

 //void AMainPlayerController::MoveDown()
 //{

 //}

 //void AMainPlayerController::MoveRight()
 //{

 //}

 //void AMainPlayerController::MoveLeft()
 //{

 //}
