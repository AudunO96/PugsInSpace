// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CatEnemy.generated.h"

UCLASS()
class PUGSINSPACE_API ACatEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACatEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector CurrentVelocity;

	UPROPERTY(EditAnywhere)
		float PatrolTurnWest = 450.0;

	UPROPERTY(EditAnywhere)
		float PatrolTurnEast = 1250.0;

	
}; 
