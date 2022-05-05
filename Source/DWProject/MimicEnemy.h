// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "MimicEnemy.generated.h"

/**
 * 
 */
UCLASS()
class DWPROJECT_API AMimicEnemy : public AEnemy
{
	GENERATED_BODY()

public:

	/** Handle timer */
	FTimerHandle HopTimer;

	bool CanHop;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:

	UFUNCTION()
	void Hop();
	
	virtual void AggroSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;
	
	virtual void FistBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;
};
