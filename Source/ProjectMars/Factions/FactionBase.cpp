// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionBase.h"

#include "ProjectMars/Characters/GameCharacter.h"


FPolitics::FPolitics()
{
	
}

FFaction::FFaction()
{

}

FFaction::FFaction(EFactionName InitFaction)
{
	Faction = InitFaction;
}

void FFaction::AddCharacterToAliveOrDeadArray(FInGameCharacter* Character)
{
	if (!Character) return;

	if(Character->CharacterState == ECharacterState::Alive)
	{
		LivingCharacters.Emplace(Character);
	}
	else if(Character->CharacterState == ECharacterState::Dead)
	{
		DeadCharacters.Emplace(Character);
	}
}

void FFaction::ApplyModifiersToLivingCharacters()
{
	if (!LivingCharacters.IsValidIndex(0)) return;
	
	TArray<ECharacterTraits> TraitsArrayPtr;

	for(auto& CharacterElem : LivingCharacters)
	{
		TraitsArrayPtr = CharacterElem->CharacterTraitsArray;

		for(auto& TraitElem : TraitsArrayPtr)
		{
			CharacterElem->ApplyTraitModifier(TraitElem);
		}
	}
}

AFactionBase::AFactionBase()
{

}

void AFactionBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFactionBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

FEconomics& AFactionBase::GetRefToEconomicsData()
{
	return Faction.Economics;
}

FPopulation& AFactionBase::GetRefToPopulationData()
{
	return Faction.Population;
}

FCultureGroup& AFactionBase::GetRefToCultureGroup()
{
	return Faction.CultureGroup;
}

FCultureData& AFactionBase::GetRefToCultureData()
{
	return Faction.CultureData;
}

void FEconomics::ApplyNetIncomeToTreasury()
{
	Treasury += GetNetIncome();
	if(Treasury < 0)
	{
		bHasADeficit = true;
	}
	else
	{
		bHasADeficit = false;
	}
}