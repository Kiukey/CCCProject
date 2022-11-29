// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EButtonAction.h"
#include "FButtonStruct.generated.h"
/**
 * 
 */
USTRUCT()
struct FButtonStruct
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere)
		FName actionName = "Button";
		UPROPERTY(EditAnywhere)
		EButtonAction buttonAction = EButtonAction::NONE;
		//UPROPERTY(EditAnywhere)
		//FKey buttonKeyCode;
		UPROPERTY(EditAnywhere)
			TArray<FKey> buttonsKeyCode;
		UPROPERTY(EditAnywhere)
		TEnumAsByte<EInputEvent> buttonState = IE_Pressed;
};
