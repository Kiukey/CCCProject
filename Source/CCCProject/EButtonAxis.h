// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EButtonAxis : uint8
{
	NONE = 0 UMETA(DisplayName = "Default"),
	VERTICAL = 100 UMETA(DisplayName = "Vertical"),
	HORIZONTAL = 200 UMETA(DisplayName = "Horizontal")
};
