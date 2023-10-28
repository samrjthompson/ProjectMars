// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "YearController.generated.h"

class UDelegateController;

/**
 * Controller and maintainer of what year it is in game
 */
UCLASS()
class PROJECTMARS_API UYearController : public UObject
{
	GENERATED_BODY()

public:
	UYearController();

	// Functions
	UFUNCTION()
	void SubToEvents(UDelegateController* DelegateControllerVar);

	// Setters
	UFUNCTION()
	UYearController* SetDelegateController(UDelegateController* DelegateControllerVar);

private:
	// Functions
	UFUNCTION()
	void SetYear();

	UFUNCTION()
	void SetFirstYear();

	// Turns year (int32) and suffix (string) into one String - e.g. FString Date 272 BC
	UFUNCTION()
	void BuildFullDateText();
	
	// Properties
	UPROPERTY()
	UDelegateController* DelegateController{ nullptr };
	
	UPROPERTY(EditAnywhere)
	int32 CurrentYear;

	UPROPERTY(EditAnywhere)
	int32 StartYear;

	UPROPERTY(EditAnywhere)
	FString StartYearSuffix;

	UPROPERTY(EditAnywhere)
	FString YearSuffix;

	UPROPERTY(EditAnywhere)
	FString FullDateText;
};
