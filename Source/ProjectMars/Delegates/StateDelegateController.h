// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DelegateController.h"
#include "StateDelegateController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNationMonthlyUpdate);

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UNationDelegateController : public UDelegateController
{
	GENERATED_BODY()

public:
	UNationDelegateController();
	
	FOnNationMonthlyUpdate OnNationMonthlyUpdate;
};
