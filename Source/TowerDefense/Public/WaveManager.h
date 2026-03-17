// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBase.h"
#include "WaveManager.generated.h"


UCLASS()
class TOWERDEFENSE_API AWaveManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaveManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Wave")
	int32 CurrentWave=1;
	UPROPERTY(EditAnywhere, Category = "Wave")
	int32 EnemiesPerWave=5;
	
	UPROPERTY(EditAnywhere, Category = "Wave")
	float SpawnInterval = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Wave")
	TSubclassOf<class AEnemyBase> EnemyClass;

	int32 EnemiesSpawned;

	int32 EnemiesAlive;

	
	FTimerHandle NextWaveTimer;
	FTimerHandle SpawnTimer;

	void StartWave();
	void SpawnEnemy();

public:	
	// Called every frame
	void OnEnemyKilled();
};
