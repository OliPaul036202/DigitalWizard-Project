// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability_Pickup.h"

#include "MainCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Components/SphereComponent.h"

// Sets default values
AAbility_Pickup::AAbility_Pickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialise static mesh component for mesh
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMeshComponent;
	
	//Initialise sphere component for collision
	USphereComponent = CreateDefaultSubobject<class USphereComponent>(TEXT("SphereComp"));
}

// Called when the game starts or when spawned
void AAbility_Pickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbility_Pickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAbility_Pickup::SphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

