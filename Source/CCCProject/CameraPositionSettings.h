// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FCameraOffset.h"
#include "CameraPositionSettings.generated.h"

/**
 * 
 */
UCLASS()
class CCCPROJECT_API UCameraPositionSettings : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Offset)
		FCameraOffset offset;
	UPROPERTY(EditAnywhere, Category = Settings, meta = (UIMin = 0, UIMax = 500, ClampMin = 0, ClampMap = 500))
		float positionSpeed = 10;
	UPROPERTY(EditAnywhere, Category = Settings)
		bool useMoveTo = true;
	UPROPERTY(EditAnywhere, Category = Settings)
		bool useSmoothMoveTo = true;
	UPROPERTY(EditAnywhere, Category = "Gizmos position settings")
		bool drawGizmos = true;
	UPROPERTY(EditAnywhere, Category = "Gizmos position settings")
		FColor validLookAtColor = FColor::Green;

public:

	FORCEINLINE bool UseMoveTo() const { return useMoveTo; }
	FORCEINLINE float PositionSpeed() const { return positionSpeed; }
	FORCEINLINE bool UseSmoothMoveTo() const { return useSmoothMoveTo; }
	FORCEINLINE bool DrawGizmos() const { return drawGizmos; }

	FVector GetCameraPosition(const AActor* _target) const ;
	void DrawCameraPosition(const FTransform& _target, UWorld* _world);
	void DrawMoveToStatus(FVector _origin, UWorld* _world);

};
