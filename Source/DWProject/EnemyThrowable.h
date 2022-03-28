// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyThrowable.generated.h"

UCLASS()
class DWPROJECT_API AEnemyThrowable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyThrowable();

	/** Sphere Component */
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class USphereComponent* SphereComponent;

	/** Static Mesh */
	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* StaticMeshComponent;

	/** Find player */
	UPROPERTY(VisibleAnywhere, Category = "Player")
	class AMainCharacter* MainCharacter;

	/** Initialise chase player */
	UPROPERTY(VisibleAnywhere, Category = "Chase Player")
	bool bCanChase;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void SphereComponentOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void AttackSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
