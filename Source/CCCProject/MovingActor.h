// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ControlPreset.h"
#include "MovingActor.generated.h"

UCLASS()
class CCCPROJECT_API AMovingActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<UControlPreset> controlPreset = nullptr;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh = nullptr;
	float dampX = 0;
	float dampY = 0;

public:	
	AMovingActor();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:

	void VerticalMove(float _axis);
	void HorizontalMove(float _axis);
	float VerticalDamping(float _axis);
	float HorizontalDamping(float _axis);
	FVector GetPlayerVerticalVelocity(float _axis);
	FVector GetPlayerHorizontalVelocity(float _axis);
	void InitInputs();
};
