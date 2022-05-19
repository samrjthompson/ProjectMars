// Fill out your copyright notice in the Description page of Project Settings.


#include "../Framework/DelegateManager.h"

// Sets default values
ADelegateManager::ADelegateManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

// Called when the game starts or when spawned
void ADelegateManager::BeginPlay()
{
	Super::BeginPlay();

	MarsGameStateBase = Cast<AMarsGameStateBase>(GetWorld()->GetGameState());
	PassSelfToGameState();	
}

void ADelegateManager::PassSelfToGameState()
{
	if(!MarsGameStateBase) 
	{
		UE_LOG(LogTemp, Fatal, TEXT("MarsGameStateBase is null - game cannot continue!"));
		return;
	}

	MarsGameStateBase->SetDelegateManager(this);
	ensure(MarsGameStateBase->GetDelegateManager());
}

