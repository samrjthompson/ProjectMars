// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EventPopupWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UEventPopupWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UEventPopupWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* DecisionButton{ nullptr };

	void CloseEventPopup();
};