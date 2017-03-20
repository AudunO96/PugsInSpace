// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "LaserCat.generated.h"

/**
 * 
 */
UCLASS()
class PUGSINSPACE_API ALaserCat : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(transient)
	class UBlackBoardComponent *BlackboardComp;
	
	class UBehaviorTreeComp *BehaviorComp;
	
public:

	ALaserCat();

	virtual void Possess(APawn *InPawn) override;

	uint8 EnemyKeyID;


};
