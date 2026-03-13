// Fill out your copyright notice in the Description page of Project Settings.


#include "ATDGameState.h"
AATDGameState::AATDGameState()
{
	TotalEnergy = 100.0f;
	AvailableEnergy = TotalEnergy;
}
bool AATDGameState::SpendEnergy(float Amount)
{
	if (AvailableEnergy >= Amount)
	{
		AvailableEnergy -= Amount;
		return true;
	}
	return false;
}
void AATDGameState::AddEnergy(float Amount)
{
	AvailableEnergy = FMath::Clamp(AvailableEnergy + Amount,0.f, TotalEnergy);
}

float AATDGameState::GetAvailableEnergy(float cost)
{
	// Return the energy that would remain after spending `cost` (never negative)
	return FMath::Max(0.f, AvailableEnergy - cost);
}
