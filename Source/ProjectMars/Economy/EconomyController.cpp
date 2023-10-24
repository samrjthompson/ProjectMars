// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyController.h"

#include "FinanceCalculator.h"
#include "ProjectMars/Delegates/DelegateController.h"
#include "ProjectMars/Economy/Data/EconomyData.h"

UEconomyController::UEconomyController()
{
	// Data structs
	EconomyData = new FEconomyData;

	// Calculators
	FinanceCalculator = NewObject<UFinanceCalculator>();

	// Maps
	InitialiseMonetarySources();
	InitialiseDelegateEvents();
}

FEconomyData* UEconomyController::GetEconomyData() const
{
	return EconomyData;
}

const TMap<EIncomeType, int32>* UEconomyController::GetIncomeSources() const
{
	return &IncomeSources;
}

const TMap<EExpenseType, int32>* UEconomyController::GetExpenseSources() const
{
	return &ExpenseSources;
}

UEconomyController* UEconomyController::SetEconomyData(FEconomyData* EconomyDataVar)
{
	this->EconomyData = EconomyDataVar;
	return this;
}

void UEconomyController::UpdateTreasury()
{
	// Calculate sum of income
	const int32 GrossIncome = FinanceCalculator->CalculateGrossIncome(IncomeSources);
	EconomyData->SetGrossIncome(GrossIncome);

	// Calculate expenses
	const int32 Expenses = FinanceCalculator->CalculateExpenses(ExpenseSources);
	EconomyData->SetExpenses(Expenses);
	
	// Calculate net income
	const int32 NetIncome = FinanceCalculator->CalculateNetIncome(
		EconomyData->GetSumOfIncome(),
		EconomyData->GetExpenses());
	EconomyData->SetNetIncome(NetIncome);

	// Calculate treasury
	const int32 UpdatedTreasury = EconomyData->GetTreasury() + EconomyData->GetNetIncome();
	EconomyData->SetTreasury(UpdatedTreasury);
}

// Initialises map of income sources with enum keys and values set to 0 by default
void UEconomyController::InitialiseMonetarySources()
{
	IncomeSources.Empty();
	ExpenseSources.Empty();
	
	for (EIncomeType Type : TEnumRange<EIncomeType>())
	{
		IncomeSources.Add(Type, 0);
	}
	for (EExpenseType Type :  TEnumRange<EExpenseType>())
	{
		ExpenseSources.Add(Type, 0);
	}
}

void UEconomyController::InitialiseDelegateEvents()
{
	if (!DelegateController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Delegate manager was null."));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Delegate manager is INITIALISED!"));
	DelegateController->OnMonthlyUpdate.AddDynamic(this, &UEconomyController::UpdateTreasury);
}


