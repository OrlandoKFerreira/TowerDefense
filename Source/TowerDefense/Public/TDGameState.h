// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TDGameState.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ATDGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ATDGameState();

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
	float GetAvailableEnergy();
	UFUNCTION(BlueprintCallable, Category = "Energy")
	bool CanAfford(float Cost) const;

};
