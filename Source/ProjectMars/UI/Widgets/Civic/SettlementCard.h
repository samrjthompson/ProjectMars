// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettlementCard.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API USettlementCard : public UUserWidget
{
	GENERATED_BODY()

public:
	USettlementCard(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* SettlementName{ nullptr };

	void UpdateArmyRosterWidget(class USettlementWidgetComponent* Comp);
};
