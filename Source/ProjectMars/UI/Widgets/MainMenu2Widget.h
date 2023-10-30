// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu2Widget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UMainMenu2Widget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	explicit UMainMenu2Widget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* StartNewGameButton_1{ nullptr };
};
