// Fill out your copyright notice in the Description page of Project Settings.


#include "Shape.h"

// Sets default values
AShape::AShape()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = Root;

	m_shapeStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Shape Static Mesh"));
	m_shapeStaticMesh->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetIncludingScale);

}

const EShapeUniqueId AShape::GetUniqueId() const
{
	return m_uniqueId;
}

const EColor AShape::GetColor() const
{
	return m_color;
}

// Called when the game starts or when spawned
void AShape::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShape::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShape::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

