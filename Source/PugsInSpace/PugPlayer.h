// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PugPlayer.generated.h"

UCLASS()
class PUGSINSPACE_API APugPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APugPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//frem og tilbake (w, s)
	UFUNCTION()
		void MoveForward(float Val);
	UFUNCTION()
		void MoveSides(float Val);	
	UFUNCTION()
		void Jump(bool isJumping);
};
