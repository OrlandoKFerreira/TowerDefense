#include "TDPlayerController.h"
#include "BuildGrid.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "TDGameState.h"
#include "TDGameMode.h"
#include "TowerBase.h"
#include "Kismet/GameplayStatics.h"

ATDPlayerController::ATDPlayerController()
{
	bShowMouseCursor = true;
}

void ATDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Encontrar a grid no mundo
	BuildGrid = Cast<ABuildGrid>(
		UGameplayStatics::GetActorOfClass(GetWorld(), ABuildGrid::StaticClass())
	);

	if (BuildGrid)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildGrid encontrada"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BuildGrid NÃO encontrada"));
	}
}

void ATDPlayerController::HandleBuildInput()
{
	if (!BuildGrid)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildGrid NULL no input"));
		return;
	}

	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	if (!HitResult.bBlockingHit)
	{
		return;
	}

	FVector WorldLocation = HitResult.Location;

	// Debug visual
	DrawDebugSphere(GetWorld(), WorldLocation, 25.f, 12, FColor::Green, false, 2.f);

	TryBuildTower(WorldLocation);
}

void ATDPlayerController::TryBuildTower(const FVector& WorldLocation)
{
	if (!BuildGrid)
	{
		UE_LOG(LogTemp, Error, TEXT("BuildGrid NULL"));
		return;
	}

	FIntPoint Cell = BuildGrid->WorldToCell(WorldLocation);

	if (BuildGrid->IsCellOccupied(Cell))
	{
		UE_LOG(LogTemp, Warning, TEXT("Célula já ocupada"));
		return;
	}

	ATDGameState* GS = GetWorld()->GetGameState<ATDGameState>();
	if (!GS)
	{
		UE_LOG(LogTemp, Error, TEXT("GameState NULL"));
		return;
	}

	if (!GS->SpendEnergy(TowerCost))
	{
		UE_LOG(LogTemp, Warning, TEXT("Sem energia"));
		return;
	}

	ATDGameMode* GM = Cast<ATDGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GM || !GM->DefaultTowerClass)
	{
		UE_LOG(LogTemp, Error, TEXT("GameMode ou TowerClass inválido"));
		return;
	}

	FVector TowerLocation = BuildGrid->SnapToGrid(WorldLocation);

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ATowerBase* Tower = GetWorld()->SpawnActor<ATowerBase>(
		GM->DefaultTowerClass,
		TowerLocation,
		FRotator::ZeroRotator,
		Params
	);

	if (!Tower)
	{
		UE_LOG(LogTemp, Error, TEXT("Falha ao spawnar torre"));
		return;
	}

	BuildGrid->SetCellOccupied(Cell, true);

	UE_LOG(LogTemp, Warning, TEXT("Torre construída com sucesso"));
}

void ATDPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UE_LOG(LogTemp, Warning, TEXT("SetupInputComponent chamado"));

	InputComponent->BindAction("LeftClick", IE_Pressed, this, &ATDPlayerController::HandleBuildInput);
}