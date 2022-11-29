// Fill out your copyright notice in the Description page of Project Settings.


#include "InputGameModeBase.h"

void AInputGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	if (!inputManagerBase)
		return;
	inputManager = GetWorld()->SpawnActor<AInputManager>(inputManagerBase);
}
