// Fill out your copyright notice in the Description page of Project Settings.


#include "AEnemyBase.h"
#include "ATDGameState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ACoreBase.h"

// Sets default values
AAEnemyBase::AAEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	GetCharacterMovement()->MaxWalkSpeed = Speed;

	TargetCore = Cast<ACoreBase>(UGameplayStatics::GetActorOfClass(GetWorld(), ACoreBase::StaticClass()));

	if (TargetCore)
	{
		UE_LOG(LogTemp, Warning, TEXT("Core encontrado!"));
	}
	
}

// Called every frame
void AAEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveToCore();

}

// Called to bind functionality to input
void AAEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void AAEnemyBase::TakeDamage(float DamageAmount)
{
	CurrentHealth -= DamageAmount;
	if (CurrentHealth <= 0)
	{
		Die();
	}
}
void AAEnemyBase::Die()
{
	// Implement death logic here, e.g., play death animation, drop loot, etc.
	UE_LOG(LogTemp, Warning, TEXT("Enemy died: %s"), *GetName());
	Destroy();
}
void AAEnemyBase::ReachCore()
{
	if (TargetCore) {
		// Implement logic for when the enemy reaches the core, e.g., apply damage to the core
		UE_LOG(LogTemp, Warning, TEXT("Reached the core: %s"), *TargetCore->GetName());
	}
}
void AAEnemyBase::MoveToCore()
{
	FVector CoreLocation = TargetCore->GetActorLocation();

	FVector EnemyLocation = GetActorLocation();

	FVector Direction = (CoreLocation - EnemyLocation).GetSafeNormal();

	AddMovementInput(Direction, 1.0f);

	float Distance = FVector::Dist(EnemyLocation, CoreLocation);

	if (Distance <= 150.f)
	{
		ReachCore();
	}
}
