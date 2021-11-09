﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DestructiveForce/Base/PawnBase.h"
#include "TankPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class DESTRUCTIVEFORCE_API ATankPawn : public APawnBase
{
	GENERATED_BODY()

private:
	float ActiveForwardAxis = 0.f;
	float ActiveRightAxis = 0.f;

	float CurrentForwardRate = 0.f;
	float CurrentRightRate = 0.f;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement|Speed")
	float MoveSpeed = 100.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement|Speed")
	float RotationSpeed = 100.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement|Speed")
	float InterpolationSpeed = .1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement|Speed")
	float TurretRotationInterpolationSpeed = .4f;

private:
	void OnMoveForward(const float Value);
	void OnTurnRight(const float Value);

	void PerformMove(float DeltaTime);
	void PerformRotate(float DeltaTime);
	void PerformRotateTurret(float DeltaTime) const;

protected:
	virtual void BeginPlay() override;

public:
	ATankPawn();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
