// Fill out your copyright notice in the Description page of Project Settings.


#include "YearController.h"

#include "ProjectMars/Delegates/DelegateController.h"

UYearController::UYearController()
{
	StartYearSuffix = "BC";
	YearSuffix = StartYearSuffix;
	StartYear = 272;
	CurrentYear = StartYear;
}

UYearController* UYearController::SetDelegateController(UDelegateController* DelegateControllerVar)
{
	DelegateController = DelegateControllerVar;
	return this;
}

void UYearController::SubToEvents(UDelegateController* DelegateControllerVar)
{
	DelegateControllerVar->OnNewYear.AddDynamic(this, &UYearController::SetYear);
	DelegateControllerVar->OnFirstTurn.AddDynamic(this, &UYearController::SetFirstYear);
}

void UYearController::SetYear()
{
	// If in BC era
	if (YearSuffix == "BC")
	{
		// If next year decrement results in 0
		if (CurrentYear - 1 == 0)
		{
			YearSuffix = "AD";
		}
		else
		{
			CurrentYear--;
		}
	}
	// If in AD era
	else
	{
		CurrentYear++;
	}
	BuildFullDateText();
}

void UYearController::SetFirstYear()
{
	BuildFullDateText();
}

void UYearController::BuildFullDateText()
{
	FullDateText = FString::FromInt(CurrentYear) + " " + YearSuffix;
	DelegateController->OnUpdateDate.Broadcast(FullDateText);
}
