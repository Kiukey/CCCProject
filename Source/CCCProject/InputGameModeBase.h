// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InputManager.h"
#include "InputGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CCCPROJECT_API AInputGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TSubclassOf<AInputManager> inputManagerBase = nullptr;
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<AInputManager> inputManager = nullptr;

protected:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
public :
	FORCEINLINE AInputManager* GetInputManager() { return inputManager; }
};
