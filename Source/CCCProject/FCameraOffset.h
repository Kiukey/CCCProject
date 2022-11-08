// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FCameraOffset.generated.h"
/**
 * 
 */
USTRUCT()
struct CCCPROJECT_API FCameraOffset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (UIMin = -2000, ClampMin = -2000, UIMax = 2000, ClampMax = 2000))
		float xOffset = 0;
	UPROPERTY(EditAnywhere, meta = (UIMin = -2000, ClampMin = -2000, UIMax = 2000, ClampMax = 2000))
		float yOffset = 0;
	UPROPERTY(EditAnywhere, meta = (UIMin = -2000, ClampMin = -2000, UIMax = 2000, ClampMax = 2000))
		float zOffset = 0;

	UPROPERTY(EditAnywhere)
		bool useLocalOffset = true;
public:

	FORCEINLINE void SetLocalOffset(bool _enable) { useLocalOffset = _enable; }
	FORCEINLINE FVector Offset() const { return FVector(xOffset, yOffset, zOffset); }
	FORCEINLINE void SetOffset(FVector _newOffset)
	{
		xOffset = _newOffset.X;
		yOffset = _newOffset.Y;
		zOffset = _newOffset.Z;
	}
	FORCEINLINE FVector GetLocalOffset(const AActor* _ref) const
	{
		FVector _offSetLocal = FVector::ZeroVector;
		_offSetLocal = _ref->GetActorLocation() + 
					   _ref->GetActorForwardVector() * xOffset + 
					   _ref->GetActorUpVector() * zOffset + 
					   _ref->GetActorRightVector() * yOffset;
		return _offSetLocal;
	}
};
