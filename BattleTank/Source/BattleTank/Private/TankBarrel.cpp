// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate Called at speed %f"), DegreesPerSecond);

	//move the barrel to the correct rotation, 
	//given max elevation speed & frame time
}




