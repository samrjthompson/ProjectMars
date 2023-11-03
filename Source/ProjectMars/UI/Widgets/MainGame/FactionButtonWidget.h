// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FactionButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UFactionButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	explicit UFactionButtonWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;
private:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* FactionFlagButton{ nullptr };
		
};
