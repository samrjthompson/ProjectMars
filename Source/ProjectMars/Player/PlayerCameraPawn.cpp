// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Player/PlayerCameraPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Factions/FactionBase.h"
#include "ProjectMars/Factions/Hellenic/RomeFaction.h"
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
}

// Called when the game starts or when spawned
void APlayerCameraPawn::BeginPlay()
{
	Super::BeginPlay();

	URomeFaction* Rome = NewObject<URomeFaction>();

	if(Rome)
	{
		UE_LOG(LogTemp, Warning, TEXT("Faction Name: %s"), *Rome->GetFactionName().ToString());
	}
	else if(!Rome)
	{
		UE_LOG(LogTemp, Error, TEXT("Rome is NULL"));
	}

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