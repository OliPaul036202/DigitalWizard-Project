// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTrackerNew.h"

#include <string>

#include "Components/TextBlock.h"

void UQuestTrackerNew::NativeConstruct()
{
	Super::NativeConstruct();

	bIsFirstStage = false;
	enemyKillCount = 0;
	// QuestItem can be nullptr if we haven't created it in the blueprint subclass
	if(QuestTitle)
	{
		QuestTitle->SetText(FText::FromString(TEXT("The GREAT MAESTRO!")));
	}

	if(QuestDescription)
	{
		QuestDescription->SetText(FText::FromString(TEXT("You knew these bars could not hold you for long... You need to escape this foul place!")));
	}
}

void UQuestTrackerNew::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if(bIsFirstStage)
	{
		if(QuestTitle)
		{
			QuestTitle->SetText(FText::FromString(TEXT("BACK FROM WHENCE YOU CAME!")));
		}

		if(QuestDescription)
		{
			QuestDescription->SetText(FText::FromString(TEXT("Vanquish These Foul Monsters Back to Oblivion!")));
		}
	}
}


