// Fill out your copyright notice in the Description page of Project Settings.


#include "TDGameMode.h"
#include "TDPlayerController.h"
#include "TDGameState.h"

ATDGameMode::ATDGameMode()
{
	PlayerControllerClass = ATDPlayerController::StaticClass();

	// 🔥 ESSENCIAL (isso resolve seu problema)
	GameStateClass = ATDGameState::StaticClass();
}

TSubclassOf<ATowerBase> ATDGameMode::GetDefaultTowerClass() const
{
	return DefaultTowerClass;
}