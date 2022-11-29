// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EButtonAction.h"
#include "FAxisStruct.generated.h"
/**
 * 
 */
USTRUCT()
struct FAxisDetails
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		FKey axis;
	UPROPERTY(EditAnywhere)
		float scale = 1;
};
USTRUCT()
struct FAxisStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		FName axisName = "Axis";
	UPROPERTY(EditAnywhere)
		EButtonAction axisAction = EButtonAction::NONE;
	UPROPERTY(EditAnywhere)
		TArray<FAxisDetails> axisKeyCode;
	//UPROPERTY(EditAnywhere)
	//	FKey buttonKeyCode;
	//UPROPERTY(EditAnywhere)
	//	float scale = 1;

};
