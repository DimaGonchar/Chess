// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if(m_bMoveForvard)
	//{
	//	SetActorLocation(GetActorLocation()+DeltaTime*100*m_movementDirection);
	//}
}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//InputComponent->BindAxis(TEXT("MoveCameraForward"), this,	&AMainPlayer::MoveCameraForward);
	//InputComponent->BindAxis(TEXT("MoveCameraBack"),	this,	&AMainPlayer::MoveCameraBack);
	//InputComponent->BindAxis(TEXT("MoveCameraRight"),	this,	&AMainPlayer::MoveCameraRight);
	//InputComponent->BindAxis(TEXT("MoveCameraLeft"),	this,	&AMainPlayer::MoveCameraLeft);
}

 void AMainPlayer::MoveCameraForward(float Value)
{
		m_bMoveForvard=true;
		m_movementDirection= GetActorForwardVector();
}

void AMainPlayer::MoveCameraBack(float Value)
 {
	m_bMoveForvard=false;
	m_movementDirection = GetActorForwardVector();

 }

void AMainPlayer::MoveCameraRight(float Value)
{
	m_movementDirection= GetActorRightVector();
}

void AMainPlayer::MoveCameraLeft(float Value)
{
	m_movementDirection = GetActorRightVector();
}

