// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CameraTPSCorr.h"
#include "CameraManager.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CCCPROJECT_API UCameraManager : public UObject
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "CameraManager")
		TMap<FString, TObjectPtr<ACameraTPSCorr>> allCameras;

public:
	UFUNCTION(BlueprintCallable) void AddCamera(ACameraTPSCorr* _camera);
	UFUNCTION(BlueprintCallable) void RemoveCamera(FString _id);
	void RemoveCamera(ACameraTPSCorr* _camera);
	UFUNCTION(BlueprintCallable) bool Exist(const FString _id) const ;
	UFUNCTION(BlueprintCallable) void Enable(const FString _id) const ;
	bool Exist(const ACameraTPSCorr* _camera) const ;
	
};
