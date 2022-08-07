// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Chess/SquareComponent.h"
#include "Shape.generated.h"

UENUM(BlueprintType)
enum class EShapeUniqueId : uint8
{
	Id_None		UMETA(DisplayName="None"),
	Id_Pawn		UMETA(DisplayName="Pawn"),
	Id_Rook		UMETA(DisplayName="Rook"),
	Id_Knight	UMETA(DisplayName="Knight"),
	Id_Bishop	UMETA(DisplayName="Bishop"),
	Id_Queen	UMETA(DisplayName="Queen"),
	Id_King		UMETA(DisplayName="King"),
};

UCLASS()
class CHESS_API AShape : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShape();

protected:

	UPROPERTY(EditDefaultsOnly, meta=(DisplayName="Root"), Category = "Root Component")
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, meta=(DisplayName="Figure Static Mesh"), Category="Static Mesh")
	UStaticMeshComponent* m_shapeStaticMesh;

	UPROPERTY(EditDefaultsOnly, meta=(DisplayName="Color"), Category="Color")
	EColor m_color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Default Start Possition on Board"), Category="Default Start Possition on Board")
	FPosition m_defaultStartPossition;

	UPROPERTY(EditDefaultsOnly, Category="Unique Id")
	EShapeUniqueId m_uniqueId=EShapeUniqueId::Id_None;

	//Default square indexes where shape can be placement on start game
	UPROPERTY(EditAnywhere, meta=(DisplayName="Default square indexes"))
	TArray<uint32> m_defaultSquares;
public:

	UFUNCTION(BlueprintPure)
	const EShapeUniqueId GetUniqueId() const;

	UFUNCTION(BlueprintPure)
	const EColor GetColor() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);
};
