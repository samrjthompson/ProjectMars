// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Country.generated.h"

struct FPopulation;

UENUM()
enum class ESettlementLevel
{
	VeryLow,
	Low,
	Medium,
	High,
	VeryHigh
};

enum class EResourceType;

USTRUCT()
struct FRegion
{
	GENERATED_BODY()

	FRegion();


	/*****************************************************/
	/* RESOURCES */

	EResourceType ResourceType;
};

UENUM()
enum class ECityLevel
{
	VeryLow,
	Low,
	Medium,
	High,
	VeryHigh
};

USTRUCT()
struct FCity : public FRegion
{
	GENERATED_BODY()

	FCity();

	ECityLevel CityLevel;
	

	/*****************************************************/
	/* POPULATION */

	int32 CityPopulation;
	FPopulation* Population{ nullptr };
	
};

USTRUCT()
struct FSettlement : public FRegion
{
	GENERATED_BODY()

		FSettlement();

	ESettlementLevel SettlementLevel;


	/*****************************************************/
	/* POPULATION */

	int32 SettlementPopulation;
	FPopulation* Population{ nullptr };

};

USTRUCT()
struct FCapitalCity : public FCity
{
	GENERATED_BODY()

	FCapitalCity();

	ECityLevel CapitalCityLevel;
	

	/*****************************************************/
	/* POPULATION */

	int32 CapitalCityPopulation;
	FPopulation* Population{ nullptr };
};

enum class EFertilityLevel;

UENUM()
enum class EProvinceAdvancement
{
	VeryLow,
	Low,
	Medium,
	High,
	VeryHigh
};

USTRUCT()
struct FProvince
{
	GENERATED_BODY()

	FProvince();

	FCapitalCity CapitalCity;
	FCity City;
	FSettlement Settlement;
	

	/*****************************************************/
	/* POPULATION */

	int32 ProvincePopulation;
	FPopulation* Population{ nullptr };
	

	/*****************************************************/
	/* FERTILITY */

	EFertilityLevel FertilityLevel;
	
};

UCLASS()
class PROJECTMARS_API ACountry : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountry();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:

public:
	FProvince Province;

	FCapitalCity* CapitalCityPtr = &Province.CapitalCity;
	FCity* CityPtr = &Province.City;
	FSettlement* SettlementPtr = &Province.Settlement;
};