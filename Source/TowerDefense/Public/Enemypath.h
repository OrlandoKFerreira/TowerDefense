// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Enemypath.generated.h"

class USplineComponent;

UCLASS()
class TOWERDEFENSE_API AEnemypath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemypath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Path")
	USplineComponent* PathSpline;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE USplineComponent* GetPathSpline() const { return PathSpline; }
};
