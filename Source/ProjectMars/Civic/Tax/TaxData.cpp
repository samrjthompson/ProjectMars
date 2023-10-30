// Fill out your copyright notice in the Description page of Project Settings.


#include "TaxData.h"

float UTaxData::GetTaxRate() const
{
	return TaxRate;
}

int32 UTaxData::GetTotalTaxIncome() const
{
	return TotalTaxIncome;
}

int32 UTaxData::GetBaseTaxValue() const
{
	return BaseTaxValue;
}

UTaxData* UTaxData::SetTaxRate(const float TaxRateVar)
{
	TaxRate = TaxRateVar;
	return this;
}

UTaxData* UTaxData::SetTotalTaxIncome(const int32 TotalTaxIncomeVar)
{
	TotalTaxIncome = TotalTaxIncomeVar;
	return this;
}

UTaxData* UTaxData::SetBaseTaxValue(const int32 BaseTaxValueVar)
{
	BaseTaxValue = BaseTaxValueVar;
	return this;
}
