// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "EnemyController.h"
#include "EnemyThrowable.h"
#include "MainCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Set up aggro and attack sphere components.
	AggroSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AggroSphere"));
	AggroSphere->SetupAttachment(GetRootComponent());
	AttackSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AttackSphere"));
	AttackSphere->SetupAttachment(GetRootComponent());

	// Initialising default health
	MaxHealthEnemy = 100.0f;
	CurrentHealthEnemy = MaxHealthEnemy;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = GetActorLocation();
	EnemyController = Cast<AEnemyController>(GetController());
	EnemyController->GetBlackboard()->SetValueAsVector(TEXT("PatrolPoint1"), PatrolPoint1 + Location);
	EnemyController->GetBlackboard()->SetValueAsVector(TEXT("PatrolPoint2"), PatrolPoint2 + Location);
	EnemyController->GetBlackboard()->SetValueAsVector(TEXT("PatrolPoint3"), PatrolPoint3 + Location);
	EnemyController->GetBlackboard()->SetValueAsVector(TEXT("PatrolPoint4"), PatrolPoint4 + Location);

	// Bind overlap functions to the Delegates on the sphere
	AggroSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::AggroSphereOverlapBegin);
	AggroSphere->OnComponentEndOverlap.AddDynamic(this, &AEnemy::AggroSphereOverlapEnd);
	AttackSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::AttackSphereOverlapBegin);
	AttackSphere->OnComponentEndOverlap.AddDynamic(this, &AEnemy::AttackSphereOverlapEnd);

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::AggroSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		AMainCharacter* Main = Cast<AMainCharacter>(OtherActor);
		if(Main)
		{
			if(EnemyController == nullptr)
			{
				EnemyController = Cast<AEnemyController>(GetController());
			}
			EnemyController->GetBlackboard()->SetValueAsObject(TEXT("TargetActor"), Main);
			EnemyController->GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = 350.0f;
		}
	}
}

void AEnemy::AggroSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor)
	{
		AMainCharacter* Main = Cast<AMainCharacter>(OtherActor);
		if(Main)
		{
			if(EnemyController == nullptr)
			{
				EnemyController = Cast<AEnemyController>(GetController());
			}
			EnemyController->GetBlackboard()->SetValueAsObject(TEXT("TargetActor"), nullptr);
		}
	}
}

void AEnemy::AttackSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		AMainCharacter* Main = Cast<AMainCharacter>(OtherActor);
		if(Main)
		{
			if(EnemyController == nullptr)
			{
				EnemyController = Cast<AEnemyController>(GetController());
			}
			EnemyController->GetBlackboard()->SetValueAsBool(TEXT("InAttackRange"), true);
		}
	}

	if(OtherActor->ActorHasTag("FireBall"))
	{
		CurrentHealthEnemy -= 20;
		OtherActor->Destroy();
	}
}

void AEnemy::AttackSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor)
	{
		AMainCharacter* Main = Cast<AMainCharacter>(OtherActor);
		if(Main)
		{
			if(EnemyController == nullptr)
			{
				EnemyController = Cast<AEnemyController>(GetController());
			}
			EnemyController->GetBlackboard()->SetValueAsBool(TEXT("InAttackRange"), false);
		}
	}
}

