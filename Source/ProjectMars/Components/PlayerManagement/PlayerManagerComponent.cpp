// Fill out your copyright notice in the Description page of Project Settings.


#include "../../Components/PlayerManagement/PlayerManagerComponent.h"

#include "ProjectMars/Delegates/DelegateController.h"
#include "ProjectMars/Framework/MarsGameStateBase.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/Factions/FactionBase.h"

// Sets default values for this component's properties
UPlayerManagerComponent::UPlayerManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	
	InitialiseRefs();
	CreateArrayOfAvailableFactions();
}

// Called every frame
void UPlayerManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerManagerComponent::InitialiseRefs()
{
	GameState = Cast<AMarsGameStateBase>(GetWorld()->GetGameState());
	ensure(GameState);
	if(!GameState) return;

	DelegateController = GameState->GetDelegateController();
	ensure(DelegateController);
}

AMarsGameStateBase* UPlayerManagerComponent::GetGameState() const
{
	return GameState;
}

TArray<AProjectMarsPlayer*>& UPlayerManagerComponent::GetAllPlayersArray()
{
	return AllPlayers;
}

AProjectMarsPlayer* UPlayerManagerComponent::GetPlayer() const
{
	return Player;
}

ABasePlayerController* UPlayerManagerComponent::GetPlayerController() const
{
	return PlayerController;
}

AAIControllerBase* UPlayerManagerComponent::GetAIController() const
{
	return AIController;
}

void UPlayerManagerComponent::AssignAIFactions()
{
	if (!AvailableFactionsArray) return;

	TArray<EFactionName> TempFactionsArray = *AvailableFactionsArray;

	for(auto& Elem : TempFactionsArray)
	{
		AProjectMarsPlayer* AIPlayer{ nullptr };
		AIPlayer = GetWorld()->SpawnActor<AProjectMarsPlayer>(AProjectMarsPlayer::StaticClass());
		AIPlayer->SpawnDefaultController();
		AIPlayer->SetFactionName(Elem);
		
		AIPlayersArray.Emplace(AIPlayer);

		FString FactionNameString = StaticEnum<EFactionName>()->GetValueAsString(AIPlayer->GetFactionName());
		AvailableFactionsArray->Remove(Elem);
	}
	DelegateController->OnAIFactionInitialisation.Broadcast();
}

void UPlayerManagerComponent::CreateArrayOfAvailableFactions()
{
	for (int32 i = 0; i < (uint8)EFactionName::Max; i++)
	{
		EFactionName FactionName = EFactionName(i);
		AllFactionsArray.Add(FactionName);

		FString FactionNameString = StaticEnum<EFactionName>()->GetValueAsString(FactionName);
		TArray<FString> OutArray;
		FactionNameString.ParseIntoArray(OutArray, TEXT("::"), true);
		FactionNameString = OutArray[1];
	}
	
	//PopulateFactionStartingInformation(AllFactionsArray);
	
	AvailableFactionsArray = &AllFactionsArray;
}

TArray<EFactionName>& UPlayerManagerComponent::GetAllFactionsArray()
{
	return AllFactionsArray;
}

TArray<EFactionName>& UPlayerManagerComponent::GetAvailableFactionsArray() const
{
	return *AvailableFactionsArray;
}

TArray<AProjectMarsPlayer*>& UPlayerManagerComponent::GetAIPlayersArray()
{
	return AIPlayersArray;
}

UDelegateController* UPlayerManagerComponent::GetDelegateController() const
{
	return DelegateController;
}

void UPlayerManagerComponent::SetDelegateManager(UDelegateController* DelegateControllerVar)
{
	DelegateController = DelegateControllerVar;
}

