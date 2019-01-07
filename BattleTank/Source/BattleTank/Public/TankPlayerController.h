// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank()  const;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	//start tank moving barrel so that it's barrel moves/shoots towards crosshair
	void AimTowardsCrosshair();

	
	
};
