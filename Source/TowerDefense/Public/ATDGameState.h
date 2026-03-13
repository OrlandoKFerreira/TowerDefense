// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ATDGameState.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AATDGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AATDGameState();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Energy")
		float TotalEnergy;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Energy")
		float AvailableEnergy;

public:
	UFUNCTION(BlueprintCallable, Category = "Energy")
	void AddEnergy(float Amount);
	UFUNCTION(BlueprintCallable, Category = "Energy")
	bool SpendEnergy(float Amount);
	UFUNCTION(BlueprintCallable, Category = "Energy")
	float GetAvailableEnergy(float cost);

};
