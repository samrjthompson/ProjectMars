// Fill out your copyright notice in the Description page of Project Settings.


#include "SettlementCard.h"

USettlementCard::USettlementCard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void USettlementCard::NativeConstruct()
{
	Super::NativeConstruct();

}

void USettlementCard::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
}

void USettlementCard::UpdateArmyRosterWidget(USettlementWidgetComponent* Comp)
{
	if (Comp)
	{
		UE_LOG(LogTemp, Warning, TEXT("UpdateArmyRosterWidget CALLED"));
	}
}