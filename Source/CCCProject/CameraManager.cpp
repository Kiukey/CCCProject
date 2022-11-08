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

void UCameraManager::Enable(const FString _id) const
{
	if (!Exist(_id))
		return;
	allCameras[_id]->Enable();
}
