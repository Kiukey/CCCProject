// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraManager.h"

void UCameraManager::AddCamera(ACameraTPSCorr* _camera)
{
	if (Exist(_camera))
		return;
	allCameras.Add(_camera->ID(), _camera);
}

void UCameraManager::RemoveCamera(FString _id)
{
	if (!Exist(_id))
		return;

	allCameras.Remove(_id);
}

void UCameraManager::RemoveCamera(ACameraTPSCorr* _camera)
{
	if (!Exist(_camera->ID()))
		return;

	allCameras.Remove(_camera->ID());
}

bool UCameraManager::Exist(const FString _id) const
{
	return allCameras.Contains(_id);
}

bool UCameraManager::Exist(const ACameraTPSCorr* _camera) const
{
	return allCameras.Contains(_camera->ID());
}

ACameraTPSCorr* UCameraManager::CreateCamera(const FString _ID, AActor* _target, UCameraPositionSettings* _positionData, UCameraRotationSettings* _rotationData)
{
	TObjectPtr<ACameraTPSCorr> _camera = GetWorld()->SpawnActor<ACameraTPSCorr>();
	_camera->SetID(_ID);
	_camera->SetTarget(_target);
	_camera->SetPosition(_positionData);
	_camera->SetRotation(_rotationData);
	/*_camera->Enable();*/
	return _camera;
}



void UCameraManager::Enable(const FString _id) const
{
	if (!Exist(_id))
		return;
	allCameras[_id]->Enable();
}
