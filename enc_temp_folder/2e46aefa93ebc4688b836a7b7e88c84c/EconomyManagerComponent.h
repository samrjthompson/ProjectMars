// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EconomyManagerComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTMARS_API UEconomyManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEconomyManagerComponent();

	UPROPERTY()
	class AMarsGameStateBase* GameState{ nullptr };

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly)
	class AProjectMarsPlayer* Player{ nullptr };

	UFUNCTION()
	void UpdatePlayerTreasury();

	UFUNCTION()
	float GetPlayerTreasury() const;

	UFUNCTION()
	bool InitialiseDelegateManager();

	UFUNCTION()
	void AddDelegates();

	UFUNCTION()
	bool InitialisePointers();

	UFUNCTION()
	float GetSumOfOutgoings() const;

	UFUNCTION()
	float GetGrossIncomePerMonth() const;

	UFUNCTION()
	float GetNetIncomePerMonth() const;

	UFUNCTION()
	void CalculateNetIncomePerMonth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float money {};

	UPROPERTY(EditAnywhere)
	class UTradeManagerComponent* TradeManagerComponent{ nullptr };

	struct FEconomyData* EconomyData{ nullptr };

	UPROPERTY()
	class ADelegateManager* DelegateManager{ nullptr };

	UPROPERTY()
		float SumOfOutgoings{};

	UPROPERTY()
		float GrossIncomePerMonth{};

	UPROPERTY()
		float NetIncomePerMonth{};
};
