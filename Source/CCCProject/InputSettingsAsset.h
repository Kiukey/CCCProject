// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FButtonStruct.h"
#include "FAxisStruct.h"
#include "InputSettingsAsset.generated.h"

/**
 * 
 */
UCLASS()
class CCCPROJECT_API UInputSettingsAsset : public UDataAsset
{
	GENERATED_BODY()
private:

	UPROPERTY(EditAnywhere, Category = Buttons)
		TArray<FButtonStruct> allButtons;
	UPROPERTY(EditAnywhere, Category = Axis)
		TArray<FAxisStruct> allAxis;
public:
	FORCEINLINE TArray<FButtonStruct> GetAllButtons() { return allButtons; }
	FORCEINLINE TArray<FAxisStruct> GetAllAxis() { return allAxis; }
};
