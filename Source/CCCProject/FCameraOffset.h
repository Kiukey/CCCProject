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

	UPROPERTY(EditAnywhere, meta = (UIMin = -2000, ClampMin = -2000, UIMax = 2000, ClampMap = 2000))
		float xOffset = 0;
	UPROPERTY(EditAnywhere, meta = (UIMin = -2000, ClampMin = -2000, UIMax = 2000, ClampMap = 2000))
		float yOffset = 0;
	UPROPERTY(EditAnywhere, meta = (UIMin = -2000, ClampMin = -2000, UIMax = 2000, ClampMap = 2000))
		float zOffset = 0;


};
