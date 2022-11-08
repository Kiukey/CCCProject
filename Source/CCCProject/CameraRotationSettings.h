// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FCameraOffset.h"
#include "engine/DataAsset.h"
#include "CameraRotationSettings.generated.h"

/**
 * 
 */
UCLASS()
class CCCPROJECT_API UCameraRotationSettings : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = Offset)
		FCameraOffset offset;
	UPROPERTY(EditAnywhere,Category = Settings, meta = (UIMin = 0, UIMax = 500, ClampMin = 0, ClampMax = 500))
		float rotationSpeed = 10;
	UPROPERTY(EditAnywhere,Category = Settings)
		bool useLookAt = true;
	UPROPERTY(EditAnywhere, Category = Settings)
		bool useSmoothLookAt = true;
	UPROPERTY(EditAnywhere,Category = "Debug")
		bool drawGizmos = true;
	UPROPERTY(EditAnywhere, Category = "Debug")
		FColor validLookAtColor = FColor::Green;
public:
	FORCEINLINE bool UseLookAt() const { return useLookAt; }
	FORCEINLINE float RotationSpeed() { return rotationSpeed; }
	FORCEINLINE bool UseSmoothLookAt() { return useSmoothLookAt; }
	FORCEINLINE bool DrawGizmos() { return drawGizmos; }
	FORCEINLINE FCameraOffset& GetOffset() { return offset; }

	FVector GetLookAtTarget(const AActor* _target);
	void DrawLookAtStatus(const FVector& _origin,  UWorld* _world);
	void DrawLookAtTarget(FVector _targetPosition, FVector _origin, FColor _color,UWorld* _world);
};
