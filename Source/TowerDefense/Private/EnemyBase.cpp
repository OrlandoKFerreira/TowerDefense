// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "TDGameState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CoreBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	GetCharacterMovement()->MaxWalkSpeed = Speed;

	TargetCore = Cast<ACoreBase>(UGameplayStatics::GetActorOfClass(GetWorld(), ACoreBase::StaticClass()));

	if (TargetCore)
	{
		UE_LOG(LogTemp, Warning, TEXT("Core Nao encontrado!"));
	}
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveToCore();

}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void AEnemyBase::ReceiveDamage(float DamageAmount)
{
	CurrentHealth -= DamageAmount;
	if (CurrentHealth <= 0)
	{
		Die();
	}
}
void AEnemyBase::Die()
{
	ATDGameState* GS = GetWorld()->GetGameState<ATDGameState>();
	if(GS){
		GS->AddEnergy(RewardEnergy);
	}
	UE_LOG(LogTemp, Warning, TEXT("Enemy died: %s"), *GetName());
	Destroy();
}
void AEnemyBase::ReachCore()
{
	if (TargetCore) {
		TargetCore->ReceiveDamage(DamageToCore);
		Destroy();
	}
}
void AEnemyBase::MoveToCore()
{
	if (!TargetCore)return;
	FVector CoreLocation = TargetCore->GetActorLocation();

	FVector EnemyLocation = GetActorLocation();

	FVector Direction = (CoreLocation - EnemyLocation).GetSafeNormal();

	AddMovementInput(Direction, 1.0f);

	float Distance = FVector::Dist(EnemyLocation, CoreLocation);

	if (Distance <= 150.f)
	{
		ReachCore();
		return;
	}
}
