// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Square.generated.h"

UENUM()
enum class  EVerticales : uint8
{
	V_A		UMETA(DisplayName="a"),
	V_B		UMETA(DisplayName="b"),
	V_C		UMETA(DisplayName="c"),
	V_D		UMETA(DisplayName="d"),
	V_E		UMETA(DisplayName="e"),
	V_F		UMETA(DisplayName="f"),
	V_G		UMETA(DisplayName="g"),
	V_H		UMETA(DisplayName="h"),
};

UENUM()
enum class EHorisontales  : uint8
{
	H_1 UMETA(DisplayName="1"),
	H_2	UMETA(DisplayName="2"),
	H_3	UMETA(DisplayName="3"),
	H_4	UMETA(DisplayName="4"),
	H_5	UMETA(DisplayName="5"),
	H_6	UMETA(DisplayName="6"),
	H_7 UMETA(DisplayName="7"),
	H_8	UMETA(DisplayName="8"),
};

UENUM()
enum class EColor : uint8
{
	C_None		UMETA(DisplayName="None"),
	C_White		UMETA(DisplayName="White"),
	C_Black		UMETA(DisplayName="Black"),
};

USTRUCT(BlueprintType)
struct CHESS_API FPosition
{
	GENERATED_BODY()

	FPosition();

	UPROPERTY(EditAnywhere)
	EVerticales verticalPos;

	UPROPERTY(EditAnywhere)
	EHorisontales horisontalPos;
};

UCLASS(BlueprintType,Blueprintable)
class CHESS_API ASquare : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASquare();

protected:

	UPROPERTY(EditAnywhere, meta=(DisplayName="Root Componemt"), Category="Root Component")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Square Static Mesh"), Category = "Static Mesh")
	UStaticMeshComponent* m_squareStaticMesh;

	UPROPERTY(EditAnywhere, meta=(DisplayName="Position on Board"), Category = "Position")
	FPosition m_positionOnBoard;

	UPROPERTY(EditAnywhere, meta=(DisplayName="Color"), Category = "Color")
	EColor m_color=EColor::C_None;

	UPROPERTY(EditAnywhere, Category ="Index on board")
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

	FORCEINLINE bool operator < (const ASquare& OtherSquare) const
	{
		return this->GetIndex() < OtherSquare.GetIndex();
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

