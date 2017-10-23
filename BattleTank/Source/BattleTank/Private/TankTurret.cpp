// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Barrel Elevate: %f"), Time, RelativeSpeed);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;
	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
}



