#include "Misc/AutomationTest.h"
#include "ProjectMars/Economy/EconomyController.h"
#include "ProjectMars/Economy/FinanceCalculator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestCalculateNetIncome, "ProjectMars.ProjectMars.Test.Economy.TestCalculateNetIncome", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FTestCalculateNetIncome::RunTest(const FString& Parameters)
{
	{
		// given
		const UFinanceCalculator* FinanceCalculator = NewObject<UFinanceCalculator>();
		
		constexpr int32 GrossIncome = 500;
		constexpr int32 GrossOutgoings = 250;
		constexpr int32 Expected = 250;

		// when
		const int32 Actual = FinanceCalculator->CalculateNetIncome(GrossIncome, GrossOutgoings);

		// then
		TestEqual(TEXT("Test net income is calculated correctly"), Actual, Expected);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestCalculateGrossIncome, "ProjectMars.ProjectMars.Test.Economy.TestCalculateGrossIncome", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FTestCalculateGrossIncome::RunTest(const FString& Parameters)
{
	{
		// given
		const UFinanceCalculator* FinanceCalculator = NewObject<UFinanceCalculator>();
		
		constexpr int32 TaxIncomeVal = 200;
		constexpr int32 TradeIncomeVal = 350;
		
		TMap<EIncomeType, int32> MapOfIncomeSources;
		MapOfIncomeSources.Add(EIncomeType::Tax, TaxIncomeVal);
		MapOfIncomeSources.Add(EIncomeType::Trade, TradeIncomeVal);
		
		constexpr int32 Expected = TaxIncomeVal + TradeIncomeVal;

		// when
		const int32 Actual = FinanceCalculator->CalculateGrossIncome(MapOfIncomeSources);

		// then
		TestEqual(TEXT("Test gross income is calculated correctly"), Actual, Expected);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestCalculateExpenses, "ProjectMars.ProjectMars.Test.Economy.TestCalculateExpenses", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FTestCalculateExpenses::RunTest(const FString& Parameters)
{
	{
		// given
		UFinanceCalculator* FinanceCalculator = NewObject<UFinanceCalculator>();
		
		TMap<EExpenseType, int32> ExpenseSources;
		ExpenseSources.Add(EExpenseType::Army, 200);
		ExpenseSources.Add(EExpenseType::Tribute, 350);
		constexpr int32 Expected = 200 + 350;

		// when
		const int32 Actual = FinanceCalculator->CalculateExpenses(ExpenseSources);

		// then
		TestEqual(TEXT("Test Expenses are calculated correctly"), Actual, Expected);
	}
	return true;
}
