// Fill out your copyright notice in the Description page of Project Settings.


#include "MarsGameStateBase.h"

#include "Logging/StructuredLog.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/Delegates/DelegateController.h"
#include "ProjectMars/Nation/Nation.h"
#include "ProjectMars/Nation/NationBuilder.h"
#include "ProjectMars/Turns/TurnController.h"

AMarsGameStateBase::AMarsGameStateBase()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;

	DelegateController = NewObject<UDelegateController>();

	// Turn Controller
	TurnController = NewObject<UTurnController>();
	TurnController->SetMarsGameStateBase(this);
	TurnController->SetDelegateController(DelegateController);
	TurnController->SubscribeToDelegates(DelegateController);
	
	InitialiseFactionTags();
	BuildNations();
	
	UE_LOGFMT(LogTemp, Log, "Constructing MarsGameStateBase");
}

void AMarsGameStateBase::AddPlayerToPlayerArray(AProjectMarsPlayer* ProjectMarsPlayer)
{
	AllPlayers.Add(ProjectMarsPlayer);
	ABasePlayerController* PlayerController = Cast<ABasePlayerController>(ProjectMarsPlayer->GetController());
	ensure(PlayerController);
	PlayerController->SetDelegateController(DelegateController);
	PlayerController->SubscribeToDelegates(DelegateController);
	PlayerController->SetNation(*Nations.Find("ROM"));
	UE_LOGFMT(LogTemp, Display, "Added player to player array");
}

// BeginPlay in the game state is called before BeginPlay in the player class. References will therefore not be initialised in BeginPlay here.
void AMarsGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("TEST VS CODE!"));
	// TODO: For development purposes - gives the developer a nation
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

// Creates array of all faction tags - the order of this array is the order of the turn owners turn
void AMarsGameStateBase::InitialiseFactionTags()
{
	// TODO: Have array populated by JSON file of all faction tags
	
	FactionTags.Add("ROM");
	FactionTags.Add("SAM");
	FactionTags.Add("CAR");
	TurnController->SetFactionTags(FactionTags);
}

// Creates all the nations in the game
void AMarsGameStateBase::BuildNations()
{
	UNationBuilder* NationBuilder = NewObject<UNationBuilder>();
	Nations = NationBuilder->BuildNations(FactionTags);
	for (const auto& Nation : Nations)
	{
		Nation.Value->SubscribeToDelegateEvents(DelegateController);
	}
}
