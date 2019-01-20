// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//move the barrel to the correct rotation, 
	//given max elevation speed & frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}




