// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildGrid.generated.h"

UCLASS()
class TOWERDEFENSE_API ABuildGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildGrid();

	FIntPoint WorldToCell(const FVector& WorldLocation) const;
	bool IsCellOccupied(const FIntPoint& Cell) const;
	void SetCellOccupied(const FIntPoint& Cell, bool bOccupied);
	FVector SnapToGrid(const FVector& WorldLocation) const;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	float GridSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int GridWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int GridHeight;

private:

	TSet<FIntPoint> OccupiedCells;
};
