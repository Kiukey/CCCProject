// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameModeManager.h"
#include "ZoneDemoCPP.generated.h"

UCLASS()
class CCCPROJECT_API AZoneDemoCPP : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
		TObjectPtr<UCameraManager> cameraManager = nullptr;
	UPROPERTY(EditAnywhere, Category = "Example", meta = (UIMin = 0 , UIMax = 1000))
		float range = 100;
	UPROPERTY(EditAnywhere, Category = "Example")
		TObjectPtr<AActor> target = nullptr;
public:	
	AZoneDemoCPP();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void SwitchCamera();
	TObjectPtr<class UCameraManager> GetCameraManager();
};
