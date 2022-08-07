// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chess/ChessDataAsset.h"
#include "Chess/SquareComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Board.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBoaedInited, const bool, status);

UCLASS()
class CHESS_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoard();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta =(DisplayName="Board Static Mesh"), Category = "Static Mesh")
	UStaticMeshComponent* m_boardStaticMesh;

	UPROPERTY(VisibleAnywhere)
	UChessDataAsset* m_chessDataAsset;

	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION(BlueprintPure)
	const bool GetIsBoardInited() const;

	UFUNCTION(BlueprintPure)
	const TArray<AShape*>& GetShapes() const;

	UFUNCTION(BlueprintPure)
	const TArray<USquareComponent*>& GetSquares() const;

private:

	void InitShapes();
	void InitSquares();

	const USquareComponent* GetSquareByIndex(const int32 squareIndex);

protected:

	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Shapes"))
	TArray<AShape*> m_shapes;

	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Squares"))
	TArray<USquareComponent*> m_squares;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool m_bSquaresInited=false;
	bool m_bShapesInited=false;
};
