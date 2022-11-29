// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerControlSettings.generated.h"

/**
 * 
 */
UCLASS()
class CCCPROJECT_API UPlayerControlSettings : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere/*, meta = (UIMin = -10000, UIMax = 10000, ClampMin = -10000, ClampMax = 10000)*/)
		float moveSpeed = 1;
	UPROPERTY(EditAnywhere/*, meta = (UIMin = -1000, UIMax = 1000, ClampMin = -1000, ClampMax = 1000)*/)
		float rotationSpeed = 1;
	UPROPERTY(EditAnywhere/*, meta = (UIMin = -360, UIMax = 360, ClampMin = -360, ClampMax = 360)*/)
		float degreesByRotation = 1;
	UPROPERTY(EditAnywhere/*, meta = (UIMin = 0.1, UIMax = 10, ClampMin = 0.1, ClampMax = 10)*/)
		float weight = 2;
	UPROPERTY(EditAnywhere)
		bool useDamping = false;
	UPROPERTY(EditAnywhere)
		bool useRotate = false;
	UPROPERTY(EditAnywhere)
		bool useLocal = false;
	UPROPERTY(EditAnywhere)
		bool useRotationBySecond = false;

public :
	FORCEINLINE float GetMovementSpeed()const { return moveSpeed; }
	FORCEINLINE float GetRotationSpeed() const { return rotationSpeed; }
	FORCEINLINE float GetDegreesByTick() const { return degreesByRotation; }
	FORCEINLINE float GetWeight() const { return weight; }
	FORCEINLINE bool UseDamp() const { return useDamping; }
	FORCEINLINE bool UseRotate() const { return useRotate; }
	FORCEINLINE bool UseLocal() const { return useLocal; }
	FORCEINLINE bool RotationPerSeconds() const{ return useRotationBySecond; }
};
