// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FollowConstMoveComponent.h"
#include "ConstFollowActor.generated.h"

UCLASS()
class CCCPROJECT_API AConstFollowActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		UFollowConstMoveComponent* moveComponent = nullptr;
public:	
	// Sets default values for this actor's properties
	AConstFollowActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
