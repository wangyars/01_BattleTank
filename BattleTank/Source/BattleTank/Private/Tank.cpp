// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	UE_LOG(LogTemp, Warning, TEXT("Tank SetTurretReference"));
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	UE_LOG(LogTemp, Warning, TEXT("Tank SetBarrelReference"));
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::AimAt(FVector AimLocation)
{
	TankAimingComponent->AimAt(AimLocation);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Tank fire"));

	if (!Barrel) { 

		UE_LOG(LogTemp, Warning, TEXT("No Barrel Found"));
		return; }

	GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);

}

