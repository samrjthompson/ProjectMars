// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChooseFactionWidget.generated.h"

class UCanvasPanel;
class UVerticalBox;

class UDelegateController;
class UButton;
class UFactionButton;
class UFactionInfoWidget;

UCLASS()
class PROJECTMARS_API UChooseFactionWidget : public UUserWidget
{
	friend class ABaseHUD;
	
	GENERATED_BODY()

public:
	explicit UChooseFactionWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	void SubscribeToEvents(UDelegateController* DelegateControllerVar);

	void ShowFactionInfoWidget(UFactionButton* ButtonHovered);

	void InitialiseFactionButtonsWithSelf();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UFactionButton* FactionButton_Rome{ nullptr };
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UFactionButton* FactionButton_Carthage{ nullptr };
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UFactionButton* FactionButton_Samnium{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UFactionInfoWidget* FactionInfoWidget{ nullptr };

	void BuildWidgets();

	/*UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCanvasPanel* CanvasPanelMain{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCanvasPanel* CanvasPanelSecond{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UVerticalBox* VerticalBoxMain{ nullptr };*/

	/*UPROPERTY(EditAnywhere)
	class UButton* FactionButton2{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* FactionButtonText{ nullptr };*/

	/*UPROPERTY()
	TArray<UButton*> ListOfButtons;*/
};
