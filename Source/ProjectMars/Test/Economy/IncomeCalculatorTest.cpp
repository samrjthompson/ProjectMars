#include "Misc/AutomationTest.h"
#include "ProjectMars/Economy/EconomyManager.h"
#include "ProjectMars/Economy/IncomeCalculator.h"

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
		TMap<EIncomeSourceType, int32> MapOfIncomeSources;
		MapOfIncomeSources.Add(EIncomeSourceType::TaxIncome, 200);
		MapOfIncomeSources.Add(EIncomeSourceType::TradeIncome, 350);
		constexpr int32 Expected = 200 + 350;

		// when
		const int32 Actual = IncomeCalculator->CalculateGrossIncome(MapOfIncomeSources);

		// then
		TestEqual(TEXT("Test gross income is calculated correctly"), Actual, Expected);
	}
	return true;
}


