// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "ExplodeEnemy.generated.h"

/**
 * 
 */
UCLASS()
class DWPROJECT_API AExplodeEnemy : public AEnemy
{
	GENERATED_BODY()

public:

	//Set defaults
	AExplodeEnemy();
	
	/** Attacking player components and VFX */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attacking Properties")
	bool bCanExplode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attacking Properties")
	float ExplodeDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	UParticleSystem* ExplosionVFX;

	class AEnemyController* EnemyController;
	
protected:

	virtual void BeginPlay();
	
public:
	
	UFUNCTION()
	void ExplodeAttack();
	
	virtual void AggroSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;
	
	virtual void AttackSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;
};
