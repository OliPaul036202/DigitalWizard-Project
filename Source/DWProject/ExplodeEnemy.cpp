// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplodeEnemy.h"
#include "EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

AExplodeEnemy::AExplodeEnemy()
{
	// Set up VFX component
	//ExplosionVFX = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	//ExplosionVFX->SetupAttachment(GetRootComponent());
}


void AExplodeEnemy::BeginPlay()
{
	Super::BeginPlay();

	EnemyController = Cast<AEnemyController>(GetController());
	
}

void AExplodeEnemy::ExplodeAttack()
{
	if(bCanExplode)
	{
		//BOOM! Spawn Explosion VF
		UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionVFX, GetActorLocation(), GetActorRotation(),true);
		Destroy();
	}
}

void AExplodeEnemy::AggroSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
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
			EnemyController->GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = 600.0f;
		}
	}
}

void AExplodeEnemy::AttackSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
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
			bCanExplode = true;
			Main->LaunchCharacter(FVector(0.0f, 0.0f, 500.0f), true, false);
			Main->CurrentHealth -= 20;
			ExplodeAttack();
		}
	}
}




