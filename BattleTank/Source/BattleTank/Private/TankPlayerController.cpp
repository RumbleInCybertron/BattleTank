// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"


void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()))

	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	// Call parent class tick function
	AimTowardsCrosshair();
}

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
		if (!GetControlledTank()) { return; }

		/*FVector CamLoc;
		FRotator CamRot;
		ATankPlayerController()->GetPlayerViewPoint(CamLoc, CamRot);
		const FVector StartTrace = CamLoc;	// Trace start is the camera location
		const FVector ShootDir = CamRot.Vector();
		const FVector EndTrace = StartTrace + ShootDir * 200;*/

		FVector OutHitLocation;	// Out parameter
		if (GetSightRayHitLocation(OutHitLocation)) // Has "side-effect", is going to line trace
		{
			//FCollisionQueryParams TraceParams(FName(TEXT("WeaponTrace")), true, this);
			//TraceParams.bTraceAsyncScene = true;
			//TraceParams.bReturnPhysicalMaterial = true;

			//FHitResult Hit(ForceInit);
			//GetWorld()->LineTraceSingle(Hit, StartTrace, EndTrace, COLLISION_WEAPON, TraceParams);
			UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString())
			// TODO Tell controlled tank to aim at this point
				// if it hits the landscape
					// Tell controlled tank to aim at this point
		}
}
// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}