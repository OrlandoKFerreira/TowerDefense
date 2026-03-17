#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

class ATowerBase;
class ACoreBase;

UCLASS()
class TOWERDEFENSE_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyBase();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	float Speed = 300.f;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	float DamageToCore = 100.f;

	UPROPERTY(EditAnywhere, Category = "Enemy")
	float RewardEnergy = 5.f;

	UPROPERTY();
	ACoreBase* TargetCore;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ReceiveDamage(float DamageAmount);

protected:

	void Die();
	void MoveToCore();
	void ReachCore();
};