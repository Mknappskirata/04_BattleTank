// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller not possessing"));

	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller possessing %s"), *(ControlledTank->GetName()));

	}
//	UE_LOG(LogTemp, Warning, TEXT("Player controller begin play"));
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//	UE_LOG(LogTemp, Warning, TEXT("Frame Tick"));
	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;}

	FVector HitLocation; //Out parameter

	if (GetSightRayLocation(HitLocation)) //Has side effect,is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
		//TODO tell tank to aim towards the point
	}
}

//Get world location through crosshair, true it it hits
bool ATankPlayerController::GetSightRayLocation(FVector &OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}




