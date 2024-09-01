// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Settlement.generated.h"

class UDelegateController;

UCLASS()
class PROJECTMARS_API ASettlement : public AActor
{
	GENERATED_BODY()

public:

	UFUNCTION()
	ASettlement* SetDelegateController(UDelegateController* DelegateController);

private:
	UPROPERTY()
	UDelegateController* DelegateController{ nullptr };

	
public:	
	// Sets default values for this actor's properties
	ASettlement();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	

	//////////////////////////////////////////////////////
	// BASE COMPONENTS

	UPROPERTY(EditAnywhere, Category = "Root")
	class USceneComponent* Root{ nullptr };

	UPROPERTY(EditAnywhere, Category = "StaticMesh")
	class UStaticMeshComponent* StaticMesh{ nullptr };

	UFUNCTION()
	void SettlementClicked(UPrimitiveComponent* PrimComp, FKey InKey);

public:	
	UPROPERTY(EditAnywhere, Category = "Widget Component")
	class USettlementWidgetComponent* SettlementWidgetComponent{ nullptr };
	
	UPROPERTY(EditAnywhere, Category = "Widget Component")
	TSubclassOf<class UUserWidget> SettlementWidgetComponentClass;
	
};