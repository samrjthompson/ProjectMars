// Fill out your copyright notice in the Description page of Project Settings.


#include "Nation.h"

#include "NationService.h"
#include "ProjectMars/Delegates/NationDelegateController.h"

UNation::UNation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	NationService(NewObject<UNationService>())
{
	FactionTag = "NONE";
}

void UNation::SubscribeToEvents(UDelegateController* DelegateControllerVar)
{
	DelegateControllerVar->OnStartNewTurn.AddDynamic(this, &UNation::UpdateIncome);
}

void UNation::UpdateIncome(const int32 TurnNumberVar)
{
	// TODO: Remove turn number var, Nation and it's components don't need to know about it
	NationService->UpdateIncome();
}

AProjectMarsPlayer* UNation::GetOwningPlayer() const
{
	return OwningPlayer;
}

UNation* UNation::SetOwningPlayer(AProjectMarsPlayer* PlayerVar)
{
	OwningPlayer = PlayerVar;
	return this;
}

UNation* UNation::SetFactionTag(const FString& FactionTagVar)
{
	FactionTag = FactionTagVar;
	return this;
}

const FString& UNation::GetFactionTag() const
{
	return FactionTag;
}

UNationService* UNation::GetNationService() const
{
	return NationService;
}
