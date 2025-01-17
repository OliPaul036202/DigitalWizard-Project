// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "Enemy.h"
#include "ExplodeEnemy.h"
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

void UMainAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	if(Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MoveSpeed = LateralSpeed.Size();
		if(Main == nullptr)
		{
			Main = Cast<AEnemy>(Pawn);
		}

		/** Can attack */
		if(Main->bCanAttack == true)
		{
			bIsAttacking = true;
		}else
		{
			bIsAttacking = false;
		}

		/** Basic walking and idle */
		if(Main)
		{
			if(MoveSpeed > 0)
			{
				bIsAccelerating = true;
				if(MoveSpeed >= 600)
				{
					bIsAccelerating = false;
					bIsSprinting = true;
				}else
				{
					bIsSprinting = false;
					bIsAccelerating = true;
				}
			}else
			{
				bIsAccelerating = false;
			}
		}

		/** Enemy death */
		if(Main->bCanDie == true)
		{
			bIsDead = true;
		}
	}
}



