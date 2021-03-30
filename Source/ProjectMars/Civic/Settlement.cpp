// Fill out your copyright notice in the Description page of Project Settings.


#include "Settlement.h"

#include "Components/BoxComponent.h"

// Sets default values
ASettlement::ASettlement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root Component");
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("City Mesh");
	Mesh->SetupAttachment(Root);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>("Trigger Box");
	TriggerBox->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ASettlement::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnClicked.AddDynamic(this, &ASettlement::SettlementClicked);
}

void ASettlement::SettlementClicked(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed)
{
	UE_LOG(LogTemp, Error, TEXT("Settlement CLICKED"));
}

// Called every frame
void ASettlement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}