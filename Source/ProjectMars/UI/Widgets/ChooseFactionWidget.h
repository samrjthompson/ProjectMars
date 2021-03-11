// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChooseFactionWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnChooseFaction);

UCLASS()
class PROJECTMARS_API UChooseFactionWidget : public UUserWidget
{
	friend class ABaseHUD;
	
	GENERATED_BODY()

public:
	UChooseFactionWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* EtruriaButton{ nullptr };

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* RomeButton{ nullptr };

	UFUNCTION()
	void CloseWidget();

	UPROPERTY()
	FOnChooseFaction OnChooseFaction;
	
};
