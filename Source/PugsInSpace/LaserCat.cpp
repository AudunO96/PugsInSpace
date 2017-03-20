// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace.h"
#include "BehaviorTree/BehaviorTree.h"
#include "LaserCat.h"



ALaserCat::ALaserCat()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
}

void ALaserCat::Possess(APawn *InPawn)
{

}