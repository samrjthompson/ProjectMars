// Fill out your copyright notice in the Description page of Project Settings.


#include "PopulationService.h"

#include "PopulationData.h"

UPopulationService::UPopulationService(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	PopulationData(NewObject<UPopulationData>())
{
}

int32 UPopulationService::CalculateTaxablePopNum(const float TaxablePopPercentageVar) const
{
	return PopulationData->GetCurrentTotalPopNum() * TaxablePopPercentageVar;
}

UPopulationData* UPopulationService::GetPopulationData() const
{
	return PopulationData;
}
