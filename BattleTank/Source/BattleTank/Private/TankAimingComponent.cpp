// Fill out your copyright notice in the Description page of Project Settings.
//#include "Kismet/GameplayStatics.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
//#include "Components/ActorComponent.h"
//#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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
		ESuggestProjVelocityTraceOption::DoNotTrace
		//ResponseParam, 				
		//ActorsToIgnore,	(For drawing debug arcs)
		//1
	);
	if(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		//find the 

	}
	//if no launch velocity, don't print
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *DeltaRotator.ToString());

	//find difference between current barrel and aimdirection rotation
	//if different
		//move the barrel to the correct rotation, given max elevation speed & frame time
}

