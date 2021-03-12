// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Cultures/Italic/ItalicCultureGroup.h"
#include "EtruscanCulture.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API AEtruscanCulture : public AItalicCultureGroup
{
	GENERATED_BODY()
public:
	AEtruscanCulture();

	ECulture Culture;
};
