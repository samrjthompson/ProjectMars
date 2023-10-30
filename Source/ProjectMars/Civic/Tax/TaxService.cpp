// Fill out your copyright notice in the Description page of Project Settings.


#include "TaxService.h"

#include "TaxData.h"

UTaxService::UTaxService(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	TaxData(NewObject<UTaxData>())
{
}

void UTaxService::SetTotalTaxIncome(const int32 NewTaxIncomeVar) const
{
	TaxData->SetTotalTaxIncome(NewTaxIncomeVar);
}

int32 UTaxService::GetBaseValueTax() const
{
	return TaxData->GetBaseTaxValue();
}

void UTaxService::SetTaxIncome(const int32 TaxIncomeVar) const
{
	TaxData->SetTotalTaxIncome(TaxIncomeVar);
}
