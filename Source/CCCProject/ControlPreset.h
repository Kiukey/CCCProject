// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ControlPreset.generated.h"

/**
 * 
 */
UCLASS()
class CCCPROJECT_API UControlPreset : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,meta = (UIMin = -10000,UIMax = 10000, ClampMin = -10000,ClampMax = 10000))
		float movementSpeed = 1;
	UPROPERTY(EditAnywhere, meta = (UIMin = -1000, UIMax = 1000, ClampMin = -1000, ClampMax = 1000))
		float rotationSpeed = 1;
	UPROPERTY(EditAnywhere, meta = (UIMin = -360, UIMax = 360, ClampMin = -360, ClampMax = 360))
		float degreesByTick = 1;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0.1, UIMax = 10, ClampMin = 0.1, ClampMax = 10))
		float weight = 2;
	UPROPERTY(EditAnywhere)
		bool useDamp = true;
	UPROPERTY(EditAnywhere)
		bool useRotate = true;
	UPROPERTY(EditAnywhere)
		bool useLocal = true;
	UPROPERTY(EditAnywhere)
		bool useRotationPerSeconds = false;
public:

	FORCEINLINE float GetMovementSpeed() { return movementSpeed; }
	FORCEINLINE float GetRotationSpeed() { return rotationSpeed; }
	FORCEINLINE float GetDegreesByTick() { return degreesByTick; }
	FORCEINLINE float GetWeight() { return weight; }
	FORCEINLINE bool GetUseDamp() { return useDamp; }
	FORCEINLINE bool GetUseRotate() { return useRotate; }
	FORCEINLINE bool GetUseLocal() { return useLocal; }
	FORCEINLINE bool GetRotationPerSeconds() { return useRotationPerSeconds; }
	

};
