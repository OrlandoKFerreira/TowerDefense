#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BuildGrid.generated.h"

UCLASS()
class TOWERDEFENSE_API ABuildGrid : public AActor
{
	GENERATED_BODY()

public:
	ABuildGrid();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Grid")
	float GridSize = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 GridWidth = 6;

	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 GridHeight = 6;

private:
	UPROPERTY()
	TSet<FIntPoint> OccupiedCells;

public:
	FIntPoint WorldToCell(const FVector& WorldLocation) const;
	bool IsCellOccupied(const FIntPoint& Cell) const;
	void SetCellOccupied(const FIntPoint& Cell, bool bOccupied);
	FVector SnapToGrid(const FVector& WorldLocation) const;

	void DrawGrid();
};