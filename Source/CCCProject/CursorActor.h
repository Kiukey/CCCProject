// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CursorActor.generated.h"

UCLASS()
class CCCPROJECT_API ACursorActor : public AActor
{
	GENERATED_BODY()

		FVector point;
	UPROPERTY(EditAnywhere, Category = "Deproject")
		bool isEnable = true;
	UPROPERTY(EditAnywhere, Category = "Deproject")
		float depth = 1000;
	UPROPERTY(EditAnywhere, Category = "Deproject")
		TObjectPtr<AActor> target = nullptr;
public:	
	ACursorActor();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	FVector GetWorldLocationFromMouse(float _depth = 1000);
	void UpdateLocation(AActor* _object, const FVector& _point);
	void DrawDebugPoint();

};
