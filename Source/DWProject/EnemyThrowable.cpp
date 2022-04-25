// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyThrowable.h"

#include "MainCharacter.h"
#include "CollisionAnalyzer/Public/ICollisionAnalyzer.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyThrowable::AEnemyThrowable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = StaticMeshComponent;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(GetRootComponent());
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));

	ProjectileMovementComponent->InitialSpeed = 400.0f;
	ProjectileMovementComponent->MaxSpeed = 0.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = false;
	ProjectileMovementComponent->bInitialVelocityInLocalSpace = true;
	ProjectileMovementComponent->HomingAccelerationMagnitude = 500.0f;
	ProjectileMovementComponent->bIsHomingProjectile = true;

}

// Called when the game starts or when spawned
void AEnemyThrowable::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemyThrowable::SphereComponentOnBeginOverlap);
	//SphereComponent->SetWorldLocation(StaticMeshComponent->GetComponentLocation());
	
	
}

// Called every frame
void AEnemyThrowable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AEnemyThrowable::SphereComponentOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Code for detecting the player... :)
	if(OtherActor)
	{
		AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
		if(OtherActor)
		{
			// Code for damaging player goes here... :)
		}
	}
}

