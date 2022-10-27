// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FollowSmoothMoveComponent.h"
#include "SmoothFollowActor.generated.h"

UCLASS()
class CCCPROJECT_API ASmoothFollowActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		UFollowSmoothMoveComponent* moveComponent = nullptr;
public:	
	ASmoothFollowActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
