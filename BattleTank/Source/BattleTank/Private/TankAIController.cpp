// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
//#include "CoreMinimal.h"
#include "Engine/World.h"
#include "BattleTank.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank) 
	{ 
		ControlledTank->AimAt(PlayerTank->GetActorLocation()); 	

		//fire when ready
		ControlledTank->Fire(); //TODO limit firing rate
	}
	


}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController:: GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}





