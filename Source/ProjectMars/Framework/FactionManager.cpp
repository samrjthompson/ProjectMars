// Fill out your copyright notice in the Description page of Project Settings.


#include "../Framework/FactionManager.h"

#include "MarsGameStateBase.h"

// Sets default values
AFactionManager::AFactionManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AllFactionNamesPtr = &GetAllFactionNames();
}

// Called when the game starts or when spawned
void AFactionManager::BeginPlay()
{
	Super::BeginPlay();

	GameStateBase = Cast<AMarsGameStateBase>(GetWorld()->GetGameState());
	ensure(GameStateBase);

	PassSelfToGameStateBase();

	/*if(AllFactionNames)
	{
		UE_LOG(LogTemp, Warning, TEXT("AllFactionNamesPtr is INITIALISED!"));
	}*/

	SetFactionNames();
	UE_LOG(LogTemp, Warning, TEXT("All factions ptr size: %d"), AllFactionNames.Num());
	for(int32 i = 0; i < AllFactionNames.Num(); i++)
	{
		//FString fac = AllFactionNames[i];
		// TODO - Trying to return an element from the array that AllFactionNamesPtr points to
		//UE_LOG(LogTemp, Error, TEXT("Faction: %s"), AllFactionNames[i]);
	}
	
}

// Called every frame
void AFactionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFactionManager::PassSelfToGameStateBase()
{
	if(!GameStateBase) return;
}

TArray<FString>& AFactionManager::GetAllFactionNames()
{
	return AllFactionNames;
}

void AFactionManager::SetFactionNames()
{
	//AllFactionNamesPtr->Add("Rome");
}
