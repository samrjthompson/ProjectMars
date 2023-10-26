// Fill out your copyright notice in the Description page of Project Settings.


#include "StateBuilder.h"

#include "State.h"

UStateBuilder::UStateBuilder()
{
	
}

TMap<FString, UState*>& UStateBuilder::BuildStates()
{
	// TODO: The list of states will be defined in a JSON file instead of this array
	TArray<FString> StateNames { "Rome", "Etruria", "Samnium" };

	constexpr int32 NumOfStates = 3;
	for (int32 i = 0; i < NumOfStates; i++)
	{
		UState* State = NewObject<UState>();
		States.Add(StateNames[i], State);
	}
	return States;
}

const TMap<FString, UState*>& UStateBuilder::AddState(FString StateName, UState* State)
{
	States.Add(StateName, State);
	return States;
}

const TMap<FString, UState*>& UStateBuilder::GetStates() const
{
	return States;
}
