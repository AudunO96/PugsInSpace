// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace.h"
#include "CatEnemy.h"
#include "PugPlayer.h"


// Sets default values
ACatEnemy::ACatEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACatEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	

}

// Called every frame
void ACatEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentVelocity.Y == 0)
		CurrentVelocity.Y = 200.0f;

	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);

		if (NewLocation.Y <= PatrolTurnEast)
			CurrentVelocity.Y = CurrentVelocity.Y * -1;

		if (NewLocation.Y >= PatrolTurnWest)
			CurrentVelocity.Y = CurrentVelocity.Y * -1;

		SetActorLocation(NewLocation);
} 

void ACatEnemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	APlayerController *AAIController = GetWorld()->GetPlayerControllerIterator;
	if (OtherActor->IsA(APugPlayer::StaticClass()))
	{
		APugPlayer* thePlayer = Cast <APugPlayer> (OtherActor);

		TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
		FDamageEvent DamageEvent(ValidDamageTypeClass);

		const float DamageAmount = .2f;
		thePlayer->TakeDamage(DamageAmount, DamageEvent, AAIController, this);
	}
}
