// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EButtonAction : uint8
{
	NONE  = 0 UMETA(DisplayName = "Default"),
	JUMP = 100 UMETA(DisplayName = "Jump Action"),
	MOVE_FORWARD = 200 UMETA(DisplayName = "Move forward")
};
