// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacterAnimInstance.h"
#include "MainCharacter.h"

void UMainCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if(Pawn == nullptr)
	{
		if(Pawn)
		{
			Main = Cast<AMainCharacter>(Pawn);
		}
	}
}

void UMainCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
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
			Main = Cast<AMainCharacter>(Pawn);
		}

		if(Main)
		{
			if(MoveSpeed > 0)
			{
				bIsPlayerAccelerating = true;
			}else
			{
				bIsPlayerAccelerating = false;
			}
		}
	}
}

