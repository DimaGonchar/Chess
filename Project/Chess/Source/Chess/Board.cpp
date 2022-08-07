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
	m_boardStaticMesh->AttachToComponent(Root,FAttachmentTransformRules::SnapToTargetIncludingScale);

	m_chessDataAsset=LoadObject<UChessDataAsset>(nullptr, TEXT("/Game/Blueprints/BP_ChessDataInfo.BP_ChessDataInfo"));
}

void ABoard::Init()
{
	InitSquares();
	InitShapes();
}

const bool ABoard::GetIsBoardInited() const
{
	return m_bShapesInited && m_bSquaresInited;
}

const TArray<AShape*>& ABoard::GetShapes() const
{
	return m_shapes;
}

const TArray<USquareComponent*>& ABoard::GetSquares() const
{
	return m_squares;
}

void ABoard::InitShapes()
{
	if (m_chessDataAsset == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("[ABoard::PlaceChessOnTheBoard] using nullptr. Chess asset doen`t found"));
		m_bShapesInited = false;
		return;
	}

	TMap<TSubclassOf<AShape>, FDefaultShapesLocationOnStartGame> shapes = m_chessDataAsset->GetShapeLocationOnStartGame();
	for (TPair<TSubclassOf<AShape>, FDefaultShapesLocationOnStartGame>& shape : shapes)
	{
		TArray<int> locations = shape.Value.Indices;
		for (int location : locations)
		{
			const USquareComponent* currentSquare = GetSquareByIndex(location);
			if (currentSquare != nullptr)
			{
				FVector currentSquareLocationInWorld = currentSquare->GetComponentLocation();

				FTransform spawnTransform = UKismetMathLibrary::Conv_VectorToTransform(currentSquareLocationInWorld);
				AShape* currentShape = Cast<AShape>(GetWorld()->SpawnActor(shape.Key, &spawnTransform));
				m_shapes.Add(currentShape);
			}
		}
	}
	m_bShapesInited = true;
}

void ABoard::InitSquares()
{
	TArray<USceneComponent*> squareComponents;
	m_boardStaticMesh->GetChildrenComponents(false, squareComponents);

	for (USceneComponent* currentComponent : squareComponents)
	{
		if (USquareComponent* currentSquare = Cast<USquareComponent>(currentComponent))
		{
			m_squares.Add(currentSquare);
		}
	}
	m_bSquaresInited=true;
}

const USquareComponent* ABoard::GetSquareByIndex(const int32 squareIndex)
{
	USquareComponent* invalidComponent=nullptr;

	for (const USquareComponent* square : m_squares)
	{
		if (square->GetIndex() == squareIndex)
		{
			return square;
		}
	}
	UE_LOG(LogTemp, Error, TEXT("[USquareComponent::GetSquareByIndex] returned nullptr"));
	return invalidComponent;
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
	//Init();
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

