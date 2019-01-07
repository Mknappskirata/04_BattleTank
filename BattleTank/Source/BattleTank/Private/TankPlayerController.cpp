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

	//AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;}

	//Get world location through crosshair
	//if hits landscape
		//tell tank to aim towards the point
}




