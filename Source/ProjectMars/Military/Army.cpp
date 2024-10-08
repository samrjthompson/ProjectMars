// Fill out your copyright notice in the Description page of Project Settings.


#include "Army.h"

#include "Blueprint/UserWidget.h"
#include "Components/BoxComponent.h"
#include "Components/TextBlock.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/UI/Widgets/Military/ArmyRoster.h"
#include "ProjectMars/UI/Widgets/WidgetComponents/ArmyWidgetComponent.h"

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

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->SetupAttachment(Mesh);

	ArmyWidgetComponent = CreateDefaultSubobject<UArmyWidgetComponent>(TEXT("Army Details Component"));
	ArmyWidgetComponent->SetupAttachment(Root);

	NumOfLegions = Army.Num();
}

AArmy* AArmy::SetTargetLocation(FVector LocationVar)
{
	TargetLocation = LocationVar;
	return this;
}

// Called when the game starts or when spawned
void AArmy::BeginPlay()
{
	Super::BeginPlay();
	
	SetupDelegates();
	
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
	if (!OwnerOfArmy) return;

	// Makes movement speed relative to game speed
	CurrentMovementSpeed = DefaultMovementSpeed; // Resets movement speed to the default - if we don't do this, CurrentMovementSpeed will infinitely increase
	CurrentMovementSpeed *= 3;	

	FVector Location = GetActorLocation();

	const float JourneyLength = (TargetLocation - GetActorLocation()).Size();

	// Setting this to 1.f seems to fix the glitching issue
	if(JourneyLength > 1.f)
	{		
		Direction = (TargetLocation - Location).GetSafeNormal();
		
		Location += CurrentMovementSpeed * GetWorld()->DeltaTimeSeconds * Direction;

		SetActorLocation(Location);
	}
}

void AArmy::SetPlayerOwnerOfArmy(AProjectMarsPlayer* PlayerOwner)
{
	OwnerOfArmy = PlayerOwner;
}

void AArmy::HideArmyWidget()
{
	OnArmyUnClicked.Broadcast();
	if (ArmyRosterWidget)
	{
		ArmyRosterWidget->RemoveFromParent();
	}
}

void AArmy::TestDelegate(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed)
{
	UE_LOG(LogTemp, Error, TEXT("Army click DELEGATE"));
}

void AArmy::SetupDelegates()
{
	TriggerBox->OnClicked.AddUniqueDynamic(this, &AArmy::TestDelegate);
}
