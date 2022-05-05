// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class DWPROJECT_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	UPROPERTY(EditAnywhere, Category = "Pawn")
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, Category = "BehaviourTree", Meta = (MakeEditWidget = true))
	FVector PatrolPoint1;

	UPROPERTY(EditAnywhere, Category = "BehaviourTree", Meta = (MakeEditWidget = true))
	FVector PatrolPoint2;

	UPROPERTY(EditAnywhere, Category = "BehaviourTree", Meta = (MakeEditWidget = true))
	FVector PatrolPoint3;

	UPROPERTY(EditAnywhere, Category = "BehaviourTree", Meta = (MakeEditWidget = true))
	FVector PatrolPoint4;

	class AEnemyController* EnemyController;
	

	/** Aggro & Attack Components */
	UPROPERTY(VisibleAnywhere, Category = "BehaviourTree")
	class USphereComponent* AggroSphere;

	UPROPERTY(VisibleAnywhere, Category = "BehaviourTree")
	USphereComponent* AttackSphere;

	UPROPERTY(VisibleAnywhere, Category = "Attacking")
	bool bCanAttack;

	UPROPERTY(VisibleAnywhere, Category = "Dying")
	bool bCanDie;

	/* Enemy Health */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enemy Health")
	float CurrentHealthEnemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Health")
	float MaxHealthEnemy;

	/** Melee attack */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	class UBoxComponent* FistCollisionComponent;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Character collision
	UFUNCTION()
	virtual void AggroSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void AggroSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// For exploding enemy
	UFUNCTION()
	virtual void AttackSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void AttackSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// For slime enemy
	UFUNCTION()
	virtual void FistBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
