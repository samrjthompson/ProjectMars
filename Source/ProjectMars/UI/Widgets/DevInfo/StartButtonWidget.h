// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartButtonWidget.generated.h"

class UTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UStartButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UStartButtonWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* StartText{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* StartButton{ nullptr };

private:
	
};
