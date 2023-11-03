// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MiniMapWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UMiniMapWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	explicit UMiniMapWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;
private:
		
};
