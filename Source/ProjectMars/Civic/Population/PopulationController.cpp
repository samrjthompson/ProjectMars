// Fill out your copyright notice in the Description page of Project Settings.


#include "PopulationController.h"

#include "PopulationData.h"

UPopulationController::UPopulationController(const FObjectInitializer& ObjInitializer)
	: Super(ObjInitializer),
	PopulationData(NewObject<UPopulationData>())
{
	
}

const UPopulationData* UPopulationController::GetPopulationData() const
{
	return PopulationData;
}
