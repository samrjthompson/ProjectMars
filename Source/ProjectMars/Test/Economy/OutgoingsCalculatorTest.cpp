#include "Misc/AutomationTest.h"
#include "ProjectMars/Economy/EconomyManager.h"
#include "ProjectMars/Economy/OutgoingsCalculator.h"

UOutgoingsCalculator* OutgoingsCalculator = NewObject<UOutgoingsCalculator>();

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestCalculateOutgoings, "Test outgoings are calculated correctly", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FTestCalculateOutgoings::RunTest(const FString& Parameters)
{
	{
		// given
		TMap<EExpenditureType, int32> MapOfOutgoingsSources;
		MapOfOutgoingsSources.Add(EExpenditureType::Army, 200);
		MapOfOutgoingsSources.Add(EExpenditureType::Tribute, 350);
		constexpr int32 Expected = 200 + 350;

		// when
		const int32 Actual = OutgoingsCalculator->CalculateOutgoings(MapOfOutgoingsSources);

		// then
		TestEqual(TEXT("Test outgoings are calculated correctly"), Actual, Expected);
	}
	return true;
}
