// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Square.h"
#include <Chess/Shape.h>
#include "Board.generated.h"


//struct CHESS_API FShapingRule
//{
//	 GENERATED_BODY()
//
//	 FShapingRule(){}
//
//
//};


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

	UPROPERTY(EditAnywhere, meta=(DisplayName="Square Asset"))
	TSubclassOf<ASquare> m_squareAssest;

	UPROPERTY(VisibleAnywhere, meta=(DisplayName="Squares"))
	TArray<ASquare*> m_squares;

	UPROPERTY(EditAnywhere, meta=(DisplayName="Chess Shapes"), Category="Chess Shapes")
	TArray<TSubclassOf<AShape>> m_chessShapes;

	UFUNCTION()
	void Init();

	//UFUNCTION(BlueprintCallable)
	//void SpawnShapesOnBoard(const TArray<AShape*>& Shapes)
	//{
	//	FActorSpawnParameters spawnParameters;
	//}

	UFUNCTION(BlueprintCallable)
	TArray<ASquare*> Sort(const TArray<ASquare*>& Squares);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
