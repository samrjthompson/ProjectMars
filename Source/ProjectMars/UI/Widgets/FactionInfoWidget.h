// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FactionInfoWidget.generated.h"

class UFactionButton;
class UTextBlock;

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UFactionInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	explicit UFactionInfoWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;
	
	void SetFactionInfo(const FString& Name);

	void PopulateFactionInfoMap();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* FactionInfoText{ nullptr };

private:
	UPROPERTY()
	TMap<FString,FString> FactionInfoMap;
	
};
