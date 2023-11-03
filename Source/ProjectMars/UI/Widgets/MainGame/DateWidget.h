// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DateWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UDateWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	explicit UDateWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;
private:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* DateText{ nullptr };
};
