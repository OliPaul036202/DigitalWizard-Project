// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTrackerNew.h"
#include "Components/TextBlock.h"

void UQuestTrackerNew::NativeConstruct()
{
	Super::NativeConstruct();

	// QuestItem can be nullptr if we haven't created it in the blueprint subclass
	if(QuestTitle)
	{
		QuestTitle->SetText(FText::FromString(TEXT("The GREAT MAESTRO!")));
	}

	if(QuestDescription)
	{
		QuestDescription->SetText(FText::FromString(TEXT("You knew these bars could not hold you for long... ESCAPE!")));
	}
}


