// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Chess/Square.h>
#include "Shape.generated.h"

UENUM(BlueprintType)
enum class EShapeUniqueId : uint8
{
	Id_None		UMETA(DisplayName="None"),
	Id_Pawn		UMETA(DisplayName="Pawn"),
	Id_Rook		UMETA(DisplayName="Rook"),
	Id_Horse	UMETA(DisplayName="Horse"),
	Id_Officer	UMETA(DisplayName="Officer"),
	Id_Queen	UMETA(DisplayName="Queen"),
	Id_King		UMETA(DisplayName="King"),
};

UCLASS()
class CHESS_API AShape : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShape();

protected:

	UPROPERTY(EditDefaultsOnly, meta=(DisplayName="Root"), Category = "Root Component")
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, meta=(DisplayName="Figure Static Mesh"), Category="Static Mesh")
	UStaticMeshComponent* m_figureStaticMesh;

	UPROPERTY(EditDefaultsOnly, meta=(DisplayName="Color"), Category="Color")
	EColor m_color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Default Start Possition on Board"), Category="Default Start Possition on Board")
	FPosition m_defaultStartPossition;

	UPROPERTY(EditDefaultsOnly, Category="Unique Id")
	EShapeUniqueId m_uniqueId=EShapeUniqueId::Id_None;

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

};
