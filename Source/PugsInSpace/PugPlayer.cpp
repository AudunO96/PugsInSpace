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

	CurrentHealth = MaxHealth;
	
}

// Called every frame
void APugPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GEngine->AddOnScreenDebugMessage(3, 0.f, FColor::Green, FString::Printf(TEXT("HP: %f"), CurrentHealth));
	//UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentHealth);

}

// Called to bind functionality to input
void APugPlayer::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &APugPlayer::MoveForward);
	InputComponent->BindAxis("MoveSides", this, &APugPlayer::MoveSides);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APugPlayer::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APugPlayer::StopJump);


}

void APugPlayer::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// finner ut hvilken vei som er frem
		FRotator Rotation = Controller->GetControlRotation();
		
		// legger til bevegelse i retningen
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

		// legger til bevegelse i retningen
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
} 

void APugPlayer::StartJump()
{
	bPressedJump = true;
}

void APugPlayer::StopJump()
{
	bPressedJump = false;
}

//standard-funksjon tatt fra dokumentasjon, tar inn parametre for mengde skade, kilden til skade og hvilken type skade det er
float APugPlayer::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	CurrentHealth = CurrentHealth - ActualDamage;

	if (CurrentHealth <= 0.000001)
		OnDeath();

	return ActualDamage;
}

//Her skal det implementeres andre ting, som for eksempel OnDeath-meny, lasting etc.
void APugPlayer::OnDeath()
{
	UWorld* TheWorld = GetWorld();
	UGameplayStatics::OpenLevel(GetWorld(), "Main");
}