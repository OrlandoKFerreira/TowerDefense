// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATowerBase.generated.h"

UCLASS()
class TOWERDEFENSE_API AATowerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATowerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Tower")
	float AttackRange=800;
	UPROPERTY(EditAnywhere, Category = "Tower")
	float Damage = 10.f;
	UPROPERTY(EditAnywhere, Category = "Tower")
	float FireRate = 1.f;
	UPROPERTY(EditAnywhere, Category = "Tower")
	float EnergyCost = 20.f;

	UPROPERTY()
	AActor* CurrentTarget;

	void FindTarget();

	void AttackTarget();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
