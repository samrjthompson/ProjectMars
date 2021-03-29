// Fill out your copyright notice in the Description page of Project Settings.


#include "Army.h"

#include "Components/BoxComponent.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"

FLegion::FLegion()
{
}

FCohort::FCohort()
{
}

FInfantry::FInfantry()
{
}

// Sets default values
AArmy::AArmy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Army Mesh"));
	Mesh->SetupAttachment(Root);
	//Mesh->OnClicked.AddDynamic(this, &AArmy::ArmyHasBeenClickedOn);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->SetupAttachment(Mesh);

	// SetTickableWhenPaused(false);
}

// Called when the game starts or when spawned
void AArmy::BeginPlay()
{
	Super::BeginPlay();

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

// Called every frame
void AArmy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveArmy();
}

AArmy* AArmy::ArmyHasBeenClickedOn()
{
	return this;
}

void AArmy::MoveArmy()
{
	if (!OwnerOfArmy) { return; }

	// Makes movement speed relative to game speed
	CurrentMovementSpeed = DefaultMovementSpeed; // Resets movement speed to the default - if we don't do this, CurrentMovementSpeed will infinitely increase
	CurrentMovementSpeed *= OwnerOfArmy->GameSpeed;	
	
	UE_LOG(LogTemp, Warning, TEXT("CurrentMovementSpeed: %f"), CurrentMovementSpeed);
	
	// This prevents the army from moving when the game is paused but retains the TargetLocation ready for when we un-pause
	if(OwnerOfArmy->BasePlayerController && OwnerOfArmy->BasePlayerController->bGameIsPaused == true)
	{
		bCanMoveArmy = false;
	}
	else
	{
		bCanMoveArmy = true;
	}
	
	if (!bCanMoveArmy) { return; }

	FVector Location = GetActorLocation();

	float JourneyLength = (TargetLocation - GetActorLocation()).Size();

	// Setting this to 1.f seems to fix the glitching issue
	if(JourneyLength > 1.f)
	{		
		Direction = (TargetLocation - Location).GetSafeNormal();
		
		Location += CurrentMovementSpeed * GetWorld()->DeltaTimeSeconds * Direction;

		SetActorLocation(Location);
	}
}

void AArmy::GetPlayerOwnerOfArmy(AProjectMarsPlayer* PlayerOwner)
{
	OwnerOfArmy = PlayerOwner;
}
