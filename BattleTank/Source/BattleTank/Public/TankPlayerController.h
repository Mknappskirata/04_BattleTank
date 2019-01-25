// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank()  const;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	//start tank moving barrel so that it's barrel moves/shoots towards crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;

	UPROPERTY(EditDefaultOnly)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultOnly)
		float CrosshairYLocation = 0.33333;

	UPROPERTY(EditDefaultOnly)
		float LineTraceRange = 1000000;

	
	
};
