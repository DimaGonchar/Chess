// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root=CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = Root;

	m_boardStaticMesh =CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Board Static Mesh"));
	m_boardStaticMesh->AttachTo(Root);
}

 void ABoard::Init()
{
	//uint32 currentIndex = 0;
	//uint32 amountSquares = 64;
	//ASquare currentSquare;

	//FPosition pos;
	//uint8 currentHorisontal = 0;

	//while (currentIndex != amountSquares)
	//{
	//	for (uint32 currentVertical = 0; currentVertical < 8; ++currentVertical)
	//	{
	//		pos.horisontalPos = static_cast<EHorisontales>(currentHorisontal);
	//		pos.verticalPos = static_cast<EVerticales>(currentVertical);

	//		currentSquare.SetIndex(currentIndex);
	//		currentSquare.SetPosition(pos);
	//		if (currentHorisontal % 2 == 0)
	//		{
	//			if (currentVertical % 2 == 0)
	//			{
	//				currentSquare.SetColor(EColor::C_White);
	//			}
	//			else
	//			{
	//				currentSquare.SetColor(EColor::C_Black);
	//			}
	//		}
	//		else
	//		{
	//			if (currentVertical % 2 == 0)
	//			{
	//				currentSquare.SetColor(EColor::C_Black);
	//			}
	//			else
	//			{
	//				currentSquare.SetColor(EColor::C_White);
	//			}
	//		}

	//		m_squares.Add(currentSquare);

	//		++currentIndex;
	//	}
	//	++currentHorisontal;
	//}
}

 TArray<ASquare*> ABoard::Sort(const TArray<ASquare*>& Squares)
 {
	TArray<ASquare*> Output=Squares;
	Output.Sort();
	return Output;
 }

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	TArray<AActor*> res;
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),m_squareAssest, res);
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

