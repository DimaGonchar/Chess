// Fill out your copyright notice in the Description page of Project Settings.


#include "Square.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASquare::ASquare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root=CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent=Root;

	StaticMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Square Static Mesh"));
	StaticMesh->AttachTo(Root);
}

void ASquare::SetIndex(const uint32 index)
{
	m_indexOnBoard = index;
}

const uint32 ASquare::GetIndex() const
{
	return m_indexOnBoard;
}

void ASquare::SetPosition(const FPosition Pos)
{
	m_positionOnBoard = Pos;
}

const FPosition& ASquare::GetPositionOnBoard() const
{
	return m_positionOnBoard;
}

void ASquare::SetColor(const EColor Color)
{
	m_color = Color;
}

const EColor ASquare::GetColor() const
{
	return m_color;
}

const EVerticales ASquare::GetVertical() const
{
	return m_positionOnBoard.verticalPos;
}

const EHorisontales ASquare::GetHorisontal() const
{
	return m_positionOnBoard.horisontalPos;
}

// Called when the game starts or when spawned
void ASquare::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FPosition::FPosition() {}
