// Fill out your copyright notice in the Description page of Project Settings.


#include "NationService.h"

#include "ProjectMars/Civic/CivicService.h"

UNationService::UNationService(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	CivicService(NewObject<UCivicService>())
{
}

void UNationService::UpdateIncome() const
{
	CivicService->UpdateIncome();
}

UCivicService* UNationService::GetCivicService() const
{
	return CivicService;
}
