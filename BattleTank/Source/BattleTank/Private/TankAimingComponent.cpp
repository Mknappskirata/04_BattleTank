// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"

#include "BattleTank.h"

//#include "Components/ActorComponent.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; //TODO should it tick???

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	const FCollisionResponseParams ResponseParam;
	const TArray<AActor*> ActorsToIgnore;

	//calc the out velocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(	this,
		OutLaunchVelocity,
		StartLocation, HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
		//find the 

	}
	//if no launch velocity, don't print
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}


void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

/*void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Barrel && Turret)) { return; }
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	if (FMath::Abs(DeltaRotator.Yaw) < 180)
	{
		Turret->Azimuth(DeltaRotator.Yaw);
	}

	/*auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch); 
	//Turret->Rotate(DeltaRotator.Yaw);
}*/

float UTankAimingComponent::Conversion(float rot) { return rot > 0 ? rot : rot + 360.0f; }

void UTankAimingComponent::MoveBarrelTowards(const FVector& AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);

	if (!Turret) { return; }
	float aimRotation = Conversion(AimDirection.Rotation().Yaw);
	float currentTurretRotation = Conversion(Turret->GetForwardVector().Rotation().Yaw);

	float relativeRotation = aimRotation - currentTurretRotation;
	/* calculate the opposite rotation: */
	float oppositeRelativeRotation = (360.0f - FMath::Abs<float>(relativeRotation)) * FMath::Sign(relativeRotation) * (-1);
	/* rotate the turret using the shortest path */
	Turret->Rotate(
		FMath::Abs<float>(relativeRotation) < FMath::Abs<float>(oppositeRelativeRotation)
		? relativeRotation
		: oppositeRelativeRotation
	);
}


