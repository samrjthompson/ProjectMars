// Fill out your copyright notice in the Description page of Project Settings.


#include "CivicService.h"

#include "ProjectMars/Economy/EconomyService.h"

UCivicService::UCivicService(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	EconomyService(NewObject<UEconomyService>()),
	PopulationService(NewObject<UPopulationService>())
{
}

void UCivicService::UpdateIncome() const
{
	// TODO: Remove hard coding of taxable pop percentage
	EconomyService->UpdateTax(PopulationService->CalculateTaxablePopNum(0.8f));
}

UEconomyService* UCivicService::GetEconomyService() const
{
	return EconomyService;
}

UPopulationService* UCivicService::GetPopulationService() const
{
	return PopulationService;
}

