// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryItem.generated.h"

UCLASS()
class CCCPROJECT_API AInventoryItem : public AActor
{
	GENERATED_BODY()

		FVector point;
	UPROPERTY(EditAnywhere, Category = "Deproject")
		bool isEnable = true;
	UPROPERTY(EditAnywhere, Category = "Deproject")
		float depth = 1000;
	UPROPERTY(EditAnywhere, Category = "Deproject")
		TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere, Category = "Deproject",meta = (UIMin = 0, UIMax = 1,ClampMin = 0,ClampMax = 1 ))
		float screenX = .5f;
	UPROPERTY(EditAnywhere, Category = "Deproject", meta = (UIMin = 0, UIMax = 1, ClampMin = 0, ClampMax = 1))
		float screenY = .5f;
public:	
	AInventoryItem();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	FVector GetWorldLocationFromViewport(float _depth = 1000);
	void SetItemLocation(const FVector& _location, AActor* _item);
	void DrawDebugPoint();
};
