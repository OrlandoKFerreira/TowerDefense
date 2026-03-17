// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TDPlayerController.generated.h"

/**
 * 
 */

class ABuildGrid;
class ATowerBase;

UCLASS()
class TOWERDEFENSE_API ATDPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATDPlayerController();
protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Grid")
	ABuildGrid* BuildGrid;

	UPROPERTY(EditAnywhere, Category = "Tower")
	float TowerCost = 20.0f;

	void HandleBuildInput();

	virtual void SetupInputComponent() override;

	void TryBuildTower(const FVector& WorldLocation);
};
