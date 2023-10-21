#include "Misc/AutomationTest.h"
#include "ProjectMars/Economy/EconomyManager.h"
#include "ProjectMars/Economy/IncomeCalculator.h"
#include "ProjectMars/Economy/IncomeSource.h"

UIncomeCalculator* IncomeCalculator = NewObject<UIncomeCalculator>();

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestCalculateNetIncome, "Test net income is calculated correctly", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FTestCalculateNetIncome::RunTest(const FString& Parameters)
{
	{
		// given
		constexpr int32 GrossIncome = 500;
		constexpr int32 GrossOutgoings = 250;
		constexpr int32 Expected = 250;

		// when
		const int32 Actual = IncomeCalculator->CalculateNetIncome(GrossIncome, GrossOutgoings);

		// then
		TestEqual(TEXT("Test net income is calculated correctly"), Actual, Expected);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestCalculateGrossIncome, "Test gross income is calculated correctly", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FTestCalculateGrossIncome::RunTest(const FString& Parameters)
{
	{
		// given
		constexpr int32 TaxIncomeVal = 200;
		constexpr int32 TradeIncomeVal = 350;
		
		FIncomeSource* TaxIncomeSource = new FIncomeSource;
		TaxIncomeSource->SetIncome(TaxIncomeVal);
		FIncomeSource* TradeIncomeSource = new FIncomeSource;
		TradeIncomeSource->SetIncome(TradeIncomeVal);
		
		TMap<EIncomeSourceType, FIncomeSource*> MapOfIncomeSources;
		MapOfIncomeSources.Add(EIncomeSourceType::TaxIncome, TaxIncomeSource);
		MapOfIncomeSources.Add(EIncomeSourceType::TradeIncome, TradeIncomeSource);
		
		constexpr int32 Expected = TaxIncomeVal + TradeIncomeVal;

		// when
		const int32 Actual = IncomeCalculator->CalculateGrossIncome(MapOfIncomeSources);

		// then
		TestEqual(TEXT("Test gross income is calculated correctly"), Actual, Expected);
	}
	return true;
}


