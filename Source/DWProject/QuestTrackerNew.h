// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestTrackerNew.generated.h"

/**
 * 
 */
UCLASS()
class DWPROJECT_API UQuestTrackerNew : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	/** Bind Widgets */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* QuestTitle;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* QuestDescription;
	
};
