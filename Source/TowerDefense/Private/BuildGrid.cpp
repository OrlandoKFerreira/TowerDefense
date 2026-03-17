// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildGrid.h"
#include "DrawDebugHelpers.h"
// Sets default values
ABuildGrid::ABuildGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	

}

// Called when the game starts or when spawned
void ABuildGrid::BeginPlay()
{
	Super::BeginPlay();
	DrawGrid();
}
FIntPoint ABuildGrid::WorldToCell(const FVector& WorldLocation) const
{
	int CellX = FMath::FloorToInt(WorldLocation.X / GridSize);
	int CellY = FMath::FloorToInt(WorldLocation.Y / GridSize);

	CellX = FMath::Clamp(CellX, 0, GridWidth - 1);
	CellY = FMath::Clamp(CellY, 0, GridHeight - 1);

	return FIntPoint(CellX, CellY);
}
bool ABuildGrid::IsCellOccupied(const FIntPoint& Cell) const
{
	return OccupiedCells.Contains(Cell);
}

void ABuildGrid::SetCellOccupied(const FIntPoint& Cell, bool bOccupied)
{
	if (bOccupied)
	{
		OccupiedCells.Add(Cell);
		return;
	}
		OccupiedCells.Remove(Cell);
}
FVector ABuildGrid::SnapToGrid(const FVector& WorldLocation) const
{
	FIntPoint Cell = WorldToCell(WorldLocation);

	float SnappedX = Cell.X * GridSize + GridSize / 2.0f;
	float SnappedY = Cell.Y * GridSize + GridSize / 2.0f;

	float ZOffset = 50.0f;

	return FVector(SnappedX, SnappedY, ZOffset);
}
void ABuildGrid::DrawGrid()
{
	if (!GetWorld()) return;

	FVector Origin = GetActorLocation();

	for (int32 X = 0; X < GridWidth; X++)
	{
		for (int32 Y = 0; Y < GridHeight; Y++)
		{
			FVector Location = Origin + FVector(X * GridSize, Y * GridSize, 100);

			DrawDebugBox(
				GetWorld(),
				Location,
				FVector(GridSize * 0.5f),
				FColor::Red,
				true,
				9999.0f,
				0,
				5.0f
			);
		}
	}
}