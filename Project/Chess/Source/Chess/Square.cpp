// Fill out your copyright notice in the Description page of Project Settings.


#include "Square.h"
#include "Components/StaticMeshComponent.h"

const TMap<uint32, EColor> ASquare:: mapOfIndexAndColorCorrespondence
														{
															{0,		EColor::C_White},	{1,		EColor::C_Black},
															{2,		EColor::C_White},	{3,		EColor::C_Black},
															{4,		EColor::C_White},	{5,		EColor::C_Black},
															{6,		EColor::C_White},	{7,		EColor::C_Black},															{8,		EColor::C_Black},
															{8,		EColor::C_Black},	{9,		EColor::C_White},
															{10,	EColor::C_Black},	{11,	EColor::C_White},
															{12,	EColor::C_Black},	{13,	EColor::C_White},
															{14,	EColor::C_Black},	{15,	EColor::C_White},
															{16,	EColor::C_White},	{17,	EColor::C_Black},
															{18,	EColor::C_White},	{19,	EColor::C_Black},
															{20,	EColor::C_White},	{21,	EColor::C_Black},
															{22,	EColor::C_White},	{23,	EColor::C_Black},
															{24,	EColor::C_Black},	{25,	EColor::C_White},
															{26,	EColor::C_Black},	{27,	EColor::C_White},
															{28,	EColor::C_Black},	{29,	EColor::C_White},
															{30,	EColor::C_Black},	{31,	EColor::C_White},
															{32,	EColor::C_White},	{33,	EColor::C_Black},
															{34,	EColor::C_White},	{35,	EColor::C_Black},
															{36,	EColor::C_White},	{37,	EColor::C_Black},
															{38,	EColor::C_White},	{39,	EColor::C_Black},
															{40,	EColor::C_Black},	{41,	EColor::C_White},
															{42,	EColor::C_Black},	{43,	EColor::C_White},
															{44,	EColor::C_Black},	{45,	EColor::C_White},
															{46,	EColor::C_Black},	{47,	EColor::C_White},
															{48,	EColor::C_White},	{49,	EColor::C_Black},
															{50,	EColor::C_White},	{51,	EColor::C_Black},
															{52,	EColor::C_White},	{53,	EColor::C_Black},
															{54,	EColor::C_White},	{55,	EColor::C_Black},
															{56,	EColor::C_Black},	{57,	EColor::C_White},
															{58,	EColor::C_Black},	{59,	EColor::C_White},
															{60,	EColor::C_Black},	{61,	EColor::C_White},
															{62,	EColor::C_Black},	{63,	EColor::C_White}
														};

// Sets default values
ASquare::ASquare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root=CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent=Root;

	m_squareStaticMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Square Static Mesh"));
	m_squareStaticMesh->AttachTo(Root);
}

const EColor ASquare::GetColorAssociateWithIndex(const uint32 SquareIndex)
{
	return mapOfIndexAndColorCorrespondence.FindChecked(SquareIndex);
}

void ASquare::SetIndex(const int index)
{
	m_indexOnBoard = static_cast<uint32>(index);
}

const int ASquare::GetIndex() const
{
	return static_cast<int>(m_indexOnBoard);
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

const FVector ASquare::GetSquareLocationInWorld()
{
	return this->GetActorLocation();
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
