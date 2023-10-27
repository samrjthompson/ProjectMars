// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnController.h"

#include "Logging/StructuredLog.h"
#include "ProjectMars/Delegates/DelegateController.h"

UTurnController::UTurnController()
{
	CurrentTurnOwnerIndex = 1;
	TurnNumber = 1;
}

void UTurnController::BroadcastFirstTurn()
{
	DelegateController->OnFirstTurn.Broadcast();
}

void UTurnController::EndTurn()
{
	UE_LOGFMT(LogTemp, Display, "Turn controller calling ENDTURN");
	BroadcastCurrentTurnOwner(ChangeCurrentTurnOwner());
}

// Broadcasts an event that a new turn has started
void UTurnController::StartNewTurn(const int32 TurnNumberVar)
{
	DelegateController->OnStartNewTurn.Broadcast(TurnNumberVar);
}

int32 UTurnController::UpdateTurnNumber()
{
	const int32 NewTurnNumber = ++TurnNumber;
	StartNewTurn(NewTurnNumber);
	return NewTurnNumber;
}

int32 UTurnController::GetTurnNumber() const
{
	return TurnNumber;
}

UTurnController* UTurnController::SetDelegateController(UDelegateController* DelegateControllerVar)
{
	DelegateController = DelegateControllerVar;
	return this;
}

UTurnController* UTurnController::SetMarsGameStateBase(AMarsGameStateBase* MarsGameStateBaseVar)
{
	MarsGameStateBase = MarsGameStateBaseVar;
	return this;
}

UTurnController* UTurnController::SetFactionTags(const TArray<FString>& FactionTagsVar)
{
	FactionTags = FactionTagsVar;
	return this;
}

void UTurnController::SubscribeToDelegates(UDelegateController* DelegateControllerVar)
{
	DelegateControllerVar->OnEndTurn.AddDynamic(this, &UTurnController::EndTurn);
}

// Returns the tag of the current turn owner
const FString& UTurnController::ChangeCurrentTurnOwner()
{
	if (CurrentTurnOwnerIndex + 1 > FactionTags.Num())
	{
		CurrentTurnOwnerIndex = 0;
		UpdateTurnNumber();
	}
	const FString& Tag = FactionTags[CurrentTurnOwnerIndex];
	CurrentTurnOwnerIndex++;
	return Tag;
}

void UTurnController::BroadcastCurrentTurnOwner(const FString& CurrentTurnOwnerVar)
{
	DelegateController->OnChangeTurnOwner.Broadcast(CurrentTurnOwnerVar);
}
