// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace.h"
#include "MyTrigger.h"
#include "SlidingDoor.h"
#include "PugPlayer.h"


// Sets default values
AMyTrigger::AMyTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MyCube"));
	RootComponent = CollisionBox;
	CollisionBox->bGenerateOverlapEvents = true;
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMyTrigger::OnOverlap);
		CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AMyTrigger::OnOverlapEnd);
	}
	
}

// Called when the game starts or when spawned
void AMyTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTrigger::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APugPlayer::StaticClass()))
	{
		theDoorOfDoom->OpenDoor(true);
	}
}

void AMyTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APugPlayer::StaticClass()))
	{
		theDoorOfDoom->OpenDoor(false);
	}
}