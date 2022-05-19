// Fill out your copyright notice in the Description page of Project Settings.


#include "../../Components/Economy/EconomyManagerComponent.h"

#include "ComponentUtils.h"
#include "TradeManagerComponent.h"
#include "../../Data/Economy/EconomyData.h"
#include "ProjectMars/Framework/DelegateManager.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"

// Sets default values for this component's properties
UEconomyManagerComponent::UEconomyManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	TradeManagerComponent = CreateDefaultSubobject<UTradeManagerComponent>(TEXT("Trade Manager Component"));
	EconomyData = new FEconomyData;
}

// Called when the game starts
void UEconomyManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	GameState = Cast<AMarsGameStateBase>(GetWorld()->GetGameState());
	ensure(GameState);
	
	ensure(InitialisePointers());
	ensure(InitialiseDelegateManager());

	AddDelegates();	
}

bool UEconomyManagerComponent::InitialisePointers()
{
	// Initialise pointers here...
	Player = Cast<AProjectMarsPlayer>(GetOwner());
	
	TArray<AActor*> ActorArray;
	ActorArray.Add(Player);

	if(ActorArray.IsEmpty()) return false;
	const int32 NumOfElements = ActorArray.Num();
	
	for(int32 i = 0; i < NumOfElements; i++)
	{	
		if(i == (NumOfElements - 1) && ActorArray[i] != nullptr) return true;
		if(ActorArray[i] != nullptr) continue;
	}
	return false;
}

// Called every frame
void UEconomyManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Error, TEXT("Economy money = %d"), EconomyData->GetMoney());
}

void UEconomyManagerComponent::UpdatePlayerTreasury()
{
	UE_LOG(LogTemp, Warning, TEXT("Month UPDATED!"));
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "Month UPDATED!", true);
}

int32 UEconomyManagerComponent::GetPlayerTreasury() const
{
	return EconomyData->GetMoney();
}

bool UEconomyManagerComponent::InitialiseDelegateManager()
{
	if(!GameState) return false;
	
	DelegateManager = GameState->GetDelegateManager();
	if(DelegateManager)
	{
		return true;
	}

	return false;
}

void UEconomyManagerComponent::AddDelegates()
{
	DelegateManager->OnMonthlyUpdate.AddDynamic(this, &UEconomyManagerComponent::UpdatePlayerTreasury);
}

