// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreBase.h"

// Sets default values
ACoreBase::ACoreBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoreBase::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void ACoreBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ACoreBase::ReceiveDamage(float DamageAmount)
{
	CurrentHealth -= DamageAmount;
	if (CurrentHealth <= 0)
	{
		// Game Over logic here
	}
}
