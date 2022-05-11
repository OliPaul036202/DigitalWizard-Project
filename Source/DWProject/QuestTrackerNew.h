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

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	/** Bind Widgets */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* QuestTitle;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* QuestDescription;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stage Check")
	bool bIsFirstStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Kill Count")
	int enemyKillCount;
	
};
