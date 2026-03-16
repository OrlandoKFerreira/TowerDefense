// Fill out your copyright notice in the Description page of Project Settings.


#include "ATDGameState.h"
ATDGameState::ATDGameState()
{
	TotalEnergy = 100.0f;
	AvailableEnergy = TotalEnergy;
}
bool ATDGameState::SpendEnergy(float Amount)
{
	if (AvailableEnergy >= Amount)
	{
		AvailableEnergy -= Amount;
		return true;
	}
	return false;
}
void ATDGameState::AddEnergy(float Amount)
{
	AvailableEnergy = FMath::Clamp(AvailableEnergy + Amount,0.f, TotalEnergy);
}

float ATDGameState::GetAvailableEnergy()
{
	// Return the energy that would remain after spending `cost` (never negative)
	return AvailableEnergy;
}
bool ATDGameState::CanAfford(float Cost) const
{
	return AvailableEnergy >= Cost;
}
