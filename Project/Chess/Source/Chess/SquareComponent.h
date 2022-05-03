// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Square.h"
#include "SquareComponent.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API USquareComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	
	USquareComponent();

	UPROPERTY(EditAnywhere, meta=(DisplayName="Root Component"), Category="Root Component")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Square Static Mesh"), Category = "Static Mesh")
	UStaticMeshComponent* m_squareStaticMesh;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Position on Board"), Category = "Position")
		FPosition m_positionOnBoard;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Color"), Category = "Color")
		EColor m_color = EColor::C_None;

	UPROPERTY(EditAnywhere, Category = "Index on board")
		uint32 m_indexOnBoard = 0;

public:

	const static TMap<uint32, EColor> mapOfIndexAndColorCorrespondence;

	const static EColor GetColorAssociateWithIndex(const uint32 SquareIndex);

	UFUNCTION(BlueprintCallable)
		void SetIndex(const int index);

	UFUNCTION(BlueprintCallable)
		const int GetIndex() const;

	UFUNCTION(BlueprintCallable)
		void SetPosition(const FPosition Pos);

	UFUNCTION(BlueprintPure)
		const FPosition& GetPositionOnBoard() const;

	UFUNCTION(BlueprintCallable)
		void SetColor(const EColor Color);

	UFUNCTION(BlueprintPure)
		const EColor GetColor()const;

	UFUNCTION(BlueprintPure)
		const EVerticales GetVertical() const;

	UFUNCTION(BlueprintPure)
		const EHorisontales GetHorisontal() const;

	UFUNCTION(BlueprintPure)
		const FVector GetSquareLocationInWorld();

	FORCEINLINE bool operator < (const USquareComponent& OtherSquare) const
	{
		return this->GetIndex() < OtherSquare.GetIndex();
	}

	virtual void BeginPlay() override;

	virtual void AddTickPrerequisiteComponent(UActorComponent* PrerequisiteComponent);
};
