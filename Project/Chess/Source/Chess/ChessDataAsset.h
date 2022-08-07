// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Shape.h"
#include "ChessDataAsset.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct CHESS_API FDefaultShapesLocationOnStartGame
{
	GENERATED_BODY()

	//Square indices where shapes should location on start game
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<int> Indices;
};

UCLASS()
class CHESS_API UChessDataAsset : public UDataAsset
{
	GENERATED_BODY()

protected:	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Shapes Location on Start Game"))
	TMap<TSubclassOf<AShape>, FDefaultShapesLocationOnStartGame> m_ShapesLocationOnStartGame;

public:
	const TMap<TSubclassOf<AShape>, FDefaultShapesLocationOnStartGame>& GetShapeLocationOnStartGame()
	{
		return m_ShapesLocationOnStartGame;
	}
};
