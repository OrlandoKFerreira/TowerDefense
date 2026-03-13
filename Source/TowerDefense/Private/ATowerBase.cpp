// Fill out your copyright notice in the Description page of Project Settings.


#include "ATowerBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AATowerBase::AATowerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AATowerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FindTarget();

}
void AATowerBase::FindTarget()
{
	TArray<AActor*> Enemies;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Enemy"), Enemies);
	float ClosestDistance = AttackRange;
	AActor* ClosestEnemy = nullptr;
	for (AActor* Enemy : Enemies)
	{
		float Distance = FVector::Dist(GetActorLocation(), Enemy->GetActorLocation());
		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			ClosestEnemy = Enemy;
		}
	}
	if (ClosestEnemy)
	{
		CurrentTarget = ClosestEnemy;
		AttackTarget();
	}
	else
	{
		CurrentTarget = nullptr;
	}
}
void AATowerBase::AttackTarget()
{
	if (CurrentTarget)
	{
		// Implement attack logic here, e.g., apply damage to the target
		UE_LOG(LogTemp, Warning, TEXT("Attacking target: %s"), *CurrentTarget->GetName());
	}
}
