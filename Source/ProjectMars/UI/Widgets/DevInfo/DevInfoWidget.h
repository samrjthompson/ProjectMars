// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DevInfoWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UDevInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UDevInfoWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* TurnNumberText{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* SeasonText{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* YearText{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* CurrentTurnOwnerText{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* CurrentTotalPopNum{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* CurrentCitizenPopNum{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* CurrentNonCitizenPopNum{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* CurrentAlliedClientPopNum{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* CurrentSlavePopNum{ nullptr };
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* CurrentForeignerPopNum{ nullptr };
	
private:
	
};
