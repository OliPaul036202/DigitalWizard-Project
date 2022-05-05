// Fill out your copyright notice in the Description page of Project Settings.


#include "MimicEnemy.h"
#include "EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MainCharacter.h"


void AMimicEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(HopTimer, this, &AMimicEnemy::Hop, 1.0f, true, 0.5f);
	CanHop = false;
}

void AMimicEnemy::Hop()
{
	if(CanHop)
	{
		this->LaunchCharacter(FVector(0.0f, 0.0f,400.0f) + GetActorForwardVector() * 800.0f, true,false);
	}
}

void AMimicEnemy::AggroSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::AggroSphereOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

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
			EnemyController->GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = 80.0f;
			CanHop = true;
		}
	}
}

void AMimicEnemy::FistBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		AMainCharacter* Main = Cast<AMainCharacter>(OtherActor);
		if(Main)
		{
			if(bCanAttack)
			{
				FVector MainForward = Main->GetActorForwardVector() * -300;
				Main->LaunchCharacter(MainForward, true, false);
				Main->CurrentHealth -= 10;
			}
		}
	}
}

