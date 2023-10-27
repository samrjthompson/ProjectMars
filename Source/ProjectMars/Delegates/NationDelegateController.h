// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DelegateController.h"
#include "NationDelegateController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNewTurn);

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UNationDelegateController : public UDelegateController
{
	GENERATED_BODY()

public:
	UNationDelegateController();
	
	FOnNewTurn OnNewTurn;
};
