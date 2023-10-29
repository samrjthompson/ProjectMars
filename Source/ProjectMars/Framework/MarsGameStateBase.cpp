// Fill out your copyright notice in the Description page of Project Settings.


#include "MarsGameStateBase.h"

#include "Logging/StructuredLog.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/Delegates/DelegateController.h"
#include "ProjectMars/Nation/Nation.h"
#include "ProjectMars/Nation/NationBuilder.h"
#include "ProjectMars/Season/SeasonController.h"
#include "ProjectMars/Turns/TurnController.h"
#include "ProjectMars/Turns/YearController.h"
#include "ProjectMars/Utils/ReadWriteJsonFile.h"

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

	// Season Controller
	SeasonController = NewObject<USeasonController>();
	SeasonController->SetDelegateController(DelegateController);
	SeasonController->SubscribeToDelegateEvents(DelegateController);

	// Year Controller
	YearController = NewObject<UYearController>();
	YearController->SetDelegateController(DelegateController);
	YearController->SubToEvents(DelegateController);
	
	InitialiseFactionTags();
	BuildNations();
}

void AMarsGameStateBase::AddPlayerToPlayerArray(AProjectMarsPlayer* ProjectMarsPlayer)
{
	AllPlayers.Add(ProjectMarsPlayer);
	ABasePlayerController* PlayerController = Cast<ABasePlayerController>(ProjectMarsPlayer->GetController());
	ensure(PlayerController);
	PlayerController->SetDelegateController(DelegateController);
	PlayerController->SubscribeToDelegates(DelegateController);
	PlayerController->SetNation(*Nations.Find("ROM"));
}

void AMarsGameStateBase::LoadFirstTurn()
{
	TurnController->BroadcastFirstTurn();
}

// BeginPlay in the game state is called before BeginPlay in the player class. References will therefore not be initialised in BeginPlay here.
void AMarsGameStateBase::BeginPlay()
{
	Super::BeginPlay();
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
	bool bSuccess;
	FString Output;
	const FString GameContentDirectory = FPaths::GameSourceDir();
	const FString JsonPath = GameContentDirectory + "ProjectMars/TempJson/Nations/Nations.json";
	const TSharedPtr<FJsonObject> Json = UReadWriteJsonFile::ReadJson(JsonPath, bSuccess, Output);

	if (!bSuccess)
	{
		UE_LOGFMT(LogTemp, Fatal, "Initialising faction tags failed with the following output: {0}", Output);
	}
	
	for (const auto& Elem : Json->Values)
	{
		FactionTags.Add(Elem.Key);
	}
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
