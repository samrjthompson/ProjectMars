// Fill out your copyright notice in the Description page of Project Settings.


#include "MarsGameStateBase.h"

#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/UI/BaseHUD.h"
#include "ProjectMars/Controllers/AIControllerBase.h"
#include "ProjectMars/Military/Army.h"
#include "ProjectMars/TimeManagement/TimeManagementComponent.h"
#include "ProjectMars/Components/PlayerManagement/PlayerManagerComponent.h"
#include "ProjectMars/Delegates/DelegateController.h"
#include "ProjectMars/Nation/State.h"

AMarsGameStateBase::AMarsGameStateBase()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
	
	TimeManagementComponent = CreateDefaultSubobject<UTimeManagementComponent>(TEXT("Time Management Component"));
	PlayerManagerComponent = CreateDefaultSubobject<UPlayerManagerComponent>(TEXT("Player Manager Component"));

	DelegateController = NewObject<UDelegateController>();

	// TODO: Remove - this is here for testing purposes
	UState* Rome = NewObject<UState>();
	Rome->SetupDelegateEvents(DelegateController);
}

AProjectMarsPlayer* AMarsGameStateBase::GetPlayer()
{
	return Player;
}

UTimeManagementComponent* AMarsGameStateBase::GetTimeManagementComponent() const {
	return TimeManagementComponent;
}

ABasePlayerController* AMarsGameStateBase::GetPlayerController() const
{
	return PlayerController;
}

void AMarsGameStateBase::AddPlayerToPlayerArray(AProjectMarsPlayer* ProjectMarsPlayer)
{
	AllPlayers.Add(ProjectMarsPlayer);
}

AActor* AMarsGameStateBase::PassActorToSelf(AActor* ActorToPass)
{
	return ActorToPass;
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
	
	//LogEveryFiveSeconds();
}

void AMarsGameStateBase::LogEveryFiveSeconds()
{
	if(GetTimeSince(LogTickCheck) >= 5.0)
	{
		UE_LOG(LogTemp, Error, TEXT("LOG"));
		LogTickCheck = FPlatformTime::Seconds();		
	}
}

void AMarsGameStateBase::SetStartTime(double& StartTime)
{
	StartTime = FPlatformTime::Seconds();
}

double AMarsGameStateBase::GetTimeSince(double StartTime)
{
	return FPlatformTime::Seconds() - StartTime;
}

void AMarsGameStateBase::InitialiseReferences(AProjectMarsPlayer* InitPlayer)
{
	Player = InitPlayer;
	
	if(!Player)
	{
		UE_LOG(LogTemp, Error, TEXT("Player is NULL"));
		return;
	}

	if (!Player->IsPlayerControlled()) { return; }
	
	// If player is controlled by player
	if(Player->IsPlayerControlled())
	{
		PlayerController = Cast<ABasePlayerController>(Player->GetController());
		if (!PlayerController)
		{
			UE_LOG(LogTemp, Error, TEXT("PlayerController is NULL"));
			return;
		}
	}

	BaseHUD = Cast<ABaseHUD>(PlayerController->GetHUD());
	if(!BaseHUD)
	{
		UE_LOG(LogTemp, Error, TEXT("BaseHUD is NULL"));
		return;
	}
}

UDelegateController* AMarsGameStateBase::GetDelegateController() const
{
	return DelegateController;
}

AFactionManager* AMarsGameStateBase::GetFactionManager() const
{
    return FactionManager;
}

ABaseHUD* AMarsGameStateBase::GetBaseHUD() const
{
	return BaseHUD;
}

void AMarsGameStateBase::SetFactionManager(AFactionManager* FactionMan)
{
    FactionManager = FactionMan;
}

void AMarsGameStateBase::SetDelegateController(UDelegateController* DelegateControllerVar)
{
	DelegateController = DelegateControllerVar;
}

UPlayerManagerComponent* AMarsGameStateBase::GetPlayerManagerComponent() const
{
	return PlayerManagerComponent;
}
