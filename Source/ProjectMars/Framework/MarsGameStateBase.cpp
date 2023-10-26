// Fill out your copyright notice in the Description page of Project Settings.


#include "MarsGameStateBase.h"

#include "Logging/StructuredLog.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/Delegates/DelegateController.h"
#include "ProjectMars/Nation/State.h"
#include "ProjectMars/Nation/StateBuilder.h"

AMarsGameStateBase::AMarsGameStateBase()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;

	DelegateController = NewObject<UDelegateController>();

	// TODO: May remove when needed - this is here for testing purposes
	UStateBuilder* StateBuilder = NewObject<UStateBuilder>();
	States = StateBuilder->BuildStates();

	for (const auto& State : States)
	{
		State.Value->SubscribeToDelegateEvents(DelegateController);
	}
	
	UE_LOGFMT(LogTemp, Log, "Constructing MarsGameStateBase");
}

void AMarsGameStateBase::AddPlayerToPlayerArray(AProjectMarsPlayer* ProjectMarsPlayer)
{
	AllPlayers.Add(ProjectMarsPlayer);
	UE_LOGFMT(LogTemp, Display, "Added player to player array");
}

// BeginPlay in the game state is called before BeginPlay in the player class. References will therefore not be initialised in BeginPlay here.
void AMarsGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("TEST VS CODE!"));
}

void AMarsGameStateBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

UDelegateController* AMarsGameStateBase::GetDelegateController() const
{
	return DelegateController;
}

void AMarsGameStateBase::SetDelegateController(UDelegateController* DelegateControllerVar)
{
	DelegateController = DelegateControllerVar;
}