// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace.h"
#include "SlidingDoor.h"


// Sets default values
ASlidingDoor::ASlidingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASlidingDoor::BeginPlay()
{
	Super::BeginPlay();
	
	closedPosition = GetActorLocation();

}

// Called every frame
void ASlidingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isOpen)
	{
		FVector newPosition = { FMath::Lerp(GetActorLocation().X, 
			openPosition.X, speed*DeltaTime),FMath::Lerp(GetActorLocation().Y,
			openPosition.Y, speed*DeltaTime), GetActorLocation().Z };
		SetActorLocation(newPosition);
	}
	else
	{
		FVector newPosition = { FMath::Lerp(GetActorLocation().X,
			closedPosition.X, speed*DeltaTime),FMath::Lerp(GetActorLocation().Y,
			closedPosition.Y, speed*DeltaTime), GetActorLocation().Z };
		SetActorLocation(newPosition);
	}
}

void ASlidingDoor::OpenDoor(bool open)
{
	isOpen = open;
}

