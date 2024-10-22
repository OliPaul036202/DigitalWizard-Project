// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy.h"
#include "BehaviorTree/BehaviorTree.h"

AEnemyController::AEnemyController()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	check(BlackboardComponent);

	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviourTreeComp"));
	check(BehaviorTreeComponent);
	
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if(InPawn == nullptr)
	{
		return;
	}
	AEnemy* Enemy = Cast<AEnemy>(InPawn);
	if(Enemy)
	{
		if(Enemy->BehaviorTree)
		{
			BlackboardComponent->InitializeBlackboard(*(Enemy->BehaviorTree->BlackboardAsset));
			BehaviorTreeComponent->StartTree(*(Enemy->BehaviorTree));
		}
	}
}

UBlackboardComponent* AEnemyController::GetBlackboard()
{
	return BlackboardComponent;
}




