// Fill out your copyright notice in the Description page of Project Settings.


#include "SquareComponent.h"

const TMap<uint32, EColor> USquareComponent::mapOfIndexAndColorCorrespondence
{
	{0,		EColor::C_White},	{1,		EColor::C_Black},
	{2,		EColor::C_White},	{3,		EColor::C_Black},
	{4,		EColor::C_White},	{5,		EColor::C_Black},
	{6,		EColor::C_White},	{7,		EColor::C_Black},															
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

USquareComponent::USquareComponent()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	m_squareStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Square Static Mesh"));
	m_squareStaticMesh->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetIncludingScale);

	AddTickPrerequisiteComponent(this);
}

const EColor USquareComponent::GetColorAssociateWithIndex(const uint32 SquareIndex)
{
	return mapOfIndexAndColorCorrespondence.FindChecked(SquareIndex);
}

void USquareComponent::SetIndex(const int index)
{
	m_indexOnBoard = static_cast<uint32>(index);
}

const int USquareComponent::GetIndex() const
{
	return static_cast<int>(m_indexOnBoard);
}

void USquareComponent::SetLocationOnBoard(const FPosition Pos)
{
	m_locationOnBoard = Pos;
}

const FPosition& USquareComponent::GetLocationOnBoard() const
{
	return m_locationOnBoard;
}

void USquareComponent::SetColor(const EColor Color)
{
	m_color = Color;
}

const EColor USquareComponent::GetColor() const
{
	return m_color;
}

const EVerticales USquareComponent::GetVerticalValue() const
{
	return m_locationOnBoard.verticalPos;
}

const EHorisontales USquareComponent::GetHorisontalValue() const
{
	return m_locationOnBoard.horisontalPos;
}

const FVector USquareComponent::GetLocationInWorld() 
{
	return this->GetComponentLocation();
}


void USquareComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USquareComponent::AddTickPrerequisiteComponent(UActorComponent* PrerequisiteComponent)
{
	Super::AddTickPrerequisiteComponent(PrerequisiteComponent);
}

FPosition::FPosition()
{
}
