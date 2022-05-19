// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "ArmyWidgetComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClick, class AProjectMarsPlayer*, Player);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnClick, class AProjectMarsPlayer*, Player);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTMARS_API UArmyWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:

	UArmyWidgetComponent();

	void RefreshWidget();

	UPROPERTY()
	class UArmyRoster* ArmyRosterWidget{ nullptr };

	UPROPERTY(EditDefaultsOnly)
	FOnClick OnClick;

	UPROPERTY(EditDefaultsOnly)
	FOnUnClick OnUnClick;

	void ArmyClicked(class AProjectMarsPlayer* PlayerCharacter);
	
	void ArmyUnClicked(class AProjectMarsPlayer* PlayerCharacter);
};