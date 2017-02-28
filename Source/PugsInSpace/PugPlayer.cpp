// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace.h"
#include "PugPlayer.h"


// Sets default values
APugPlayer::APugPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APugPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APugPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APugPlayer::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &APugPlayer::MoveForward);
	InputComponent->BindAxis("MoveSides", this, &APugPlayer::MoveSides);

}

void APugPlayer::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APugPlayer::MoveSides(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// finner retningen karakteren står i
		FRotator Rotation = Controller->GetControlRotation();

		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void APugPlayer::Jump(bool isJumping)
{

}
