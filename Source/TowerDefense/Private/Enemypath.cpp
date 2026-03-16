// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemypath.h"

// Sets default values
AEnemypath::AEnemypath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PathSpline = CreateDefaultSubobject<USplineComponent>(TEXT("PathSpline"));
	SetRootComponent(PathSpline);
}

// Called when the game starts or when spawned
void AEnemypath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemypath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

