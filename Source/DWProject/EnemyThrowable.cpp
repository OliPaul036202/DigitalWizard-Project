// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyThrowable.h"

#include "MainCharacter.h"
#include "CollisionAnalyzer/Public/ICollisionAnalyzer.h"
#include "Components/SphereComponent.h"

// Sets default values
AEnemyThrowable::AEnemyThrowable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(GetRootComponent());

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	// Initialise
	bCanChase = false;
}

// Called when the game starts or when spawned
void AEnemyThrowable::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemyThrowable::SphereComponentOnBeginOverlap);
	
	
}

// Called every frame
void AEnemyThrowable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bCanChase)
	{
		//Throw object towards the general direction of the player... :)
		FVector TargetLoc = MainCharacter->GetActorLocation();
		
	}
}

void AEnemyThrowable::SphereComponentOnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Code for detecting the player... :)
	if(OtherActor)
	{
		MainCharacter = Cast<AMainCharacter>(OtherActor);
		if(MainCharacter)
		{
			bCanChase = true;
		}
	}
}

void AEnemyThrowable::AttackSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Code for damaging the player... :)
	
}

