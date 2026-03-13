#include "WaveManager.h"
#include "AEnemyBase.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
AWaveManager::AWaveManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AWaveManager::BeginPlay()
{
	Super::BeginPlay();

	StartWave();
}

void AWaveManager::StartWave()
{
	EnemiesSpawned = 0;
	EnemiesAlive = 0;

	GetWorld()->GetTimerManager().SetTimer(
		SpawnTimer,
		this,
		&AWaveManager::SpawnEnemy,
		SpawnInterval,
		true
	);
}

void AWaveManager::SpawnEnemy()
{
	if (!EnemyClass) return;

	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = FRotator::ZeroRotator;

	GetWorld()->SpawnActor<AEnemyBase>(
		EnemyClass,
		SpawnLocation,
		SpawnRotation
	);

	EnemiesSpawned++;
	EnemiesAlive++;

	if (EnemiesSpawned >= EnemiesPerWave)
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimer);
	}
}

void AWaveManager::OnEnemyKilled()
{
	EnemiesAlive--;

	if (EnemiesAlive <= 0 && EnemiesSpawned >= EnemiesPerWave)
	{
		CurrentWave++;

		StartWave();
	}
}