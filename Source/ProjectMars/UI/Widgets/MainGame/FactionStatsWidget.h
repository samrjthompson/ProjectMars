// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FactionStatsWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UFactionStatsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	explicit UFactionStatsWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;
private:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* MoneyText{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* ManpowerText{ nullptr };
};
