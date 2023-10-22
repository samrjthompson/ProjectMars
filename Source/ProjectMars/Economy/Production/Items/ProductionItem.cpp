// Fill out your copyright notice in the Description page of Project Settings.


#include "ProductionItem.h"

UProductionItem::UProductionItem()
{
}

void UProductionItem::AddModifierToCurrentValue(const float ModifierVal)
{
	CurrentValue *= ModifierVal;
}

int32 UProductionItem::GetCurrentValue() const
{
	return CurrentValue;
}

UProductionItem* UProductionItem::SetCurrentValue(const int32 NewValue)
{
	CurrentValue = NewValue;
	return this;
}
