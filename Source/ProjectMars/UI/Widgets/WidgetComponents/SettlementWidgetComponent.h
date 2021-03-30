// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "SettlementWidgetComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API USettlementWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	USettlementWidgetComponent();

	void RefreshWidget();

	UPROPERTY()
	class USettlementCard* SettlementCard{ nullptr };
};
