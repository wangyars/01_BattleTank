// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankTurret;
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float LaunchSpeed = 5000.f;

	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;

public:
	void SetTurretReference(UTankTurret* TurretToSet);

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void MoveBarrelTowards(FVector AimDirection);

	void AimAt(FVector AimLocation);

	
};
