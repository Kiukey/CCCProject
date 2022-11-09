// Fill out your copyright notice in the Description page of Project Settings.


#include "ZoneDemoCPP.h"

AZoneDemoCPP::AZoneDemoCPP()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
}

void AZoneDemoCPP::BeginPlay()
{
	Super::BeginPlay();
	
	cameraManager = GetCameraManager();
	FName _pathPos = "CameraPositionSettings'/Game/SettingsData/DataSettingsPosition.DataSettingsPosition'",
		  _pathRot = "CameraRotationSettings'/Game/SettingsData/DataRotationSettings.DataRotationSettings'";;
	UCameraPositionSettings* _posSettings = Cast<UCameraPositionSettings>( StaticLoadObject(UCameraPositionSettings::StaticClass(), this, *_pathPos.ToString())); 
	UCameraRotationSettings* _rotSettings = Cast<UCameraRotationSettings>(StaticLoadObject(UCameraRotationSettings::StaticClass(), this, *_pathRot.ToString()));
	ACameraTPSCorr* _cam =  cameraManager->CreateCamera("Zob", this, _posSettings, _rotSettings);
	//_cam->Enable();
}

void AZoneDemoCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SwitchCamera();
}

void AZoneDemoCPP::SwitchCamera()
{
	if (!target || !cameraManager)
		return;
	bool _atRange = FVector::Dist(GetActorLocation(), target->GetActorLocation()) < range;
	cameraManager->Enable(_atRange ? "Other" : "Erika");
}

TObjectPtr<class UCameraManager> AZoneDemoCPP::GetCameraManager()
{
	TObjectPtr<AGameModeManager> _gm = GetWorld()->GetAuthGameMode<AGameModeManager>();
	if (!_gm)
		return nullptr;

	return _gm->IsValidCameraManager() ? _gm->CameraManager() : nullptr;
}
