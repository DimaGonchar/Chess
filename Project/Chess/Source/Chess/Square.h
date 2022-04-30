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
	H_7 UMETA(DisplaName="7"),
	H_8	UMETA(DisplayName="8"),
};

UENUM()
enum class EColor : uint8
{
	C_White		UMETA(DisplayName="White"),
	C_Black		UMETA(DisplayName="Black"),
};

USTRUCT()
struct FPosition
{
	GENERATED_BODY()

	FPosition();

	UPROPERTY()
	EVerticales verticalPos;

	UPROPERTY()
	EHorisontales horisontalPos;

};

UCLASS()
class CHESS_API ASquare : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASquare();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Square Static Mesh"), Category = "Static Mesh")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Position on Board")
	FPosition m_positionOnBoard;

	UPROPERTY(EditAnywhere,  Category = "Base Color")
	EColor m_color;

	UPROPERTY(EditAnywhere, Category ="Index on board")
	uint32 m_indexOnBoard = 0;

	UFUNCTION(Category ="Setters")
	void SetIndex(const uint32 index);
	
	UFUNCTION(Category ="Getters")
	const uint32 GetIndex() const;

	UFUNCTION(Category ="Setters")
	void SetPosition(const FPosition Pos);

	UFUNCTION(Category ="Getters")
	const FPosition& GetPositionOnBoard() const;

	UFUNCTION(Category ="Setters")
	void SetColor(const EColor Color);

	UFUNCTION(Category ="Getters")
	const EColor GetColor()const;

	UFUNCTION(Category = "Getters")
	const EVerticales GetVertical() const;

	UFUNCTION(Category = "Getters")
	const EHorisontales GetHorisontal() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
