// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = SetUp)
	float MaxDegreePerSecond = 5;

	UPROPERTY(EditAnywhere, Category = SetUp)
	float MaxElevation = 30;

	UPROPERTY(EditAnywhere, Category = SetUp)
	float MinElevation = -5;
	
};
