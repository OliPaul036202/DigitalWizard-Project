// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "Enemy.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if(Pawn == nullptr)
	{
		if(Pawn)
		{
			Main = Cast<AEnemy>(Pawn);
		}
	}
}

void UMainAnimInstance::UpdateAnimationProperties()
{
	if(Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	if(Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MoveSpeed = LateralSpeed.Size();
		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
		if(Main == nullptr)
		{
			Main = Cast<AEnemy>(Pawn);
		}

		if(Main)
		{
			if(Main->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0)
			{
				bIsAccelerating = true;
			}else
			{
				bIsAccelerating = false;
			}
		}
	}
}



