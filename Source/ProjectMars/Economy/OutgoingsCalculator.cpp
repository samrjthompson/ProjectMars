// Fill out your copyright notice in the Description page of Project Settings.


#include "OutgoingsCalculator.h"

int32 UOutgoingsCalculator::CalculateOutgoings(const TMap<EExpenditureType, int32>& MapOfOutgoingsSourcesVar)
{
	int32 TotalOutgoings = 0;
	for (const auto OutgoingsSource : MapOfOutgoingsSourcesVar)
	{
		TotalOutgoings += OutgoingsSource.Value;
	}
	return TotalOutgoings;
}
