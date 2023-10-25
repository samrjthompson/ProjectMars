// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DelegateController.h"
#include "StateDelegateController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStateMonthlyUpdate);

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UStateDelegateController : public UDelegateController
{
	GENERATED_BODY()

public:
	UStateDelegateController();
	
	FOnStateMonthlyUpdate OnStateMonthlyUpdate;
};
