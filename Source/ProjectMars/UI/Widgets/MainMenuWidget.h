// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	explicit UMainMenuWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* StartButton{ nullptr };

private:
	
};
