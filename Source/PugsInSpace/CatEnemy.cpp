// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace.h"
#include "CatEnemy.h"


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

} 

