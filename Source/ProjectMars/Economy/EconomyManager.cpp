// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyManager.h"

#include "ProjectMars/EconomyInfo.h"


UEconomyManager::UEconomyManager()
{
	EconomyInfo = new FEconomyInfo;
}

FEconomyInfo* UEconomyManager::GetEconomyInfo() const
{
	return EconomyInfo;
}

UEconomyManager* UEconomyManager::SetEconomyInfo(FEconomyInfo* EconomyInfoVar)
{
	this->EconomyInfo = EconomyInfoVar;
	return this;
}
