// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "CameraRotationSettings.h"
#include "CameraPositionSettings.h"
#include "CameraTPSCorr.generated.h"

UCLASS()
class CCCPROJECT_API ACameraTPSCorr : public AActor
{
	GENERATED_BODY()
		
	UPROPERTY(VisibleAnywhere, Category = CameraTPS)
		TObjectPtr<UCameraComponent> cameraTarget = nullptr;
	UPROPERTY(EditAnywhere,Category = "CameraTPS | rotation")
		TObjectPtr<UCameraRotationSettings> lookAtSettings = nullptr;	
	UPROPERTY(EditAnywhere,Category = "CameraTPS | position")
		TObjectPtr<UCameraPositionSettings> positionSettings = nullptr;
	UPROPERTY(EditAnywhere, Category = CameraTPS)
		TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere, Category = "Manager Item")
		FString id = "Camera";
public:	
	ACameraTPSCorr();
	FORCEINLINE FVector CurrentCameraLocation() const { return GetActorLocation(); }
	FORCEINLINE FVector CurrentTargetLocation() const 
	{ 
		return cameraTarget ? lookAtSettings->GetLookAtTarget(target) : CurrentCameraLocation();
	}
	FORCEINLINE FRotator CurrentCameraRotation() const { return GetActorRotation(); }
	FORCEINLINE FString ID() const { return id; }
private:
	void InitCamera();
	virtual void BeginPlay() override;
	virtual void  EndPlay(const EEndPlayReason::Type EndPlayReason);
	virtual void Tick(float DeltaTime) override;
	void OnDrawDebug();
	void LookAtTarget();
	void MoveToTarget();
	TObjectPtr<class UCameraManager> GetCameraManager();
public:
	void Enable();
	void Disable();
};
