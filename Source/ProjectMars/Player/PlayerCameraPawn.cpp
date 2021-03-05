// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Player/PlayerCameraPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Factions/FactionBase.h"
#include "ProjectMars/Factions/Hellenic/EtruriaFaction.h"
#include "ProjectMars/Factions/Hellenic/RomeFaction.h"
#include "ProjectMars/Factions/Punic/CarthageFaction.h"
#include "ProjectMars/UI/BaseHUD.h"

// Sets default values
APlayerCameraPawn::APlayerCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Scene Component/Root Component
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent = RootComp;

	// Spring Arm
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComp->SetupAttachment(RootComp);
	SpringArmComp->bEnableCameraLag = true;

	// Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComp);

	MovementSpeed = 500.f;

	bHasChosenFaction = false;
}

// Called when the game starts or when spawned
void APlayerCameraPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PawnMovement(DeltaTime);
}

// Called to bind functionality to input
void APlayerCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(PlayerInputComponent)
	{
		// Movement
		PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCameraPawn::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCameraPawn::MoveRight);

		PlayerInputComponent->BindAction("Rome", IE_Pressed, this, &APlayerCameraPawn::ChooseRome);
		PlayerInputComponent->BindAction("Etruria", IE_Pressed, this, &APlayerCameraPawn::ChooseEtruria);
		PlayerInputComponent->BindAction("Carthage", IE_Pressed, this, &APlayerCameraPawn::ChooseCarthage);
	}
}

void APlayerCameraPawn::PawnMovement(float DeltaTime)
{
	if(!MovementDirection.IsZero())
	{
		const FVector NewLocation = GetActorLocation() + (MovementDirection * DeltaTime * MovementSpeed);
		SetActorLocation(NewLocation);
	}
}

void APlayerCameraPawn::MoveForward(float Val)
{
	// The FMath::Clamp helps to prevent higher speeds when pressing two keyboard keys at once
	MovementDirection.X = FMath::Clamp(Val, -1.f, 1.f);
}

void APlayerCameraPawn::MoveRight(float Val)
{
	// The FMath::Clamp helps to prevent higher speeds when pressing two keyboard keys at once
	MovementDirection.Y = FMath::Clamp(Val, -1.f, 1.f);
}

void APlayerCameraPawn::ChooseRome()
{
	SetPlayerFaction(EFaction::Rome);
}

void APlayerCameraPawn::ChooseEtruria()
{
	SetPlayerFaction(EFaction::Etruria);
}

void APlayerCameraPawn::ChooseCarthage()
{
	SetPlayerFaction(EFaction::Carthage);
}

void APlayerCameraPawn::SetPlayerFaction(const EFaction Faction)
{
	if(bHasChosenFaction) { return; }
	
	switch (Faction)
	{
		case EFaction::Rome : PlayerAssignedFaction = NewObject<URomeFaction>();
		break;

		case EFaction::Etruria : PlayerAssignedFaction = NewObject<UEtruriaFaction>();
		break;

		case EFaction::Carthage : PlayerAssignedFaction = NewObject<UCarthageFaction>();
		break;

		default: PlayerAssignedFaction = nullptr;
		break;
	}

	if(PlayerAssignedFaction)
	{
		UE_LOG(LogTemp, Warning, TEXT("Faction Name: %s"), *PlayerAssignedFaction->GetBaseFactionName().ToString());
	}

	bHasChosenFaction = true;
}
