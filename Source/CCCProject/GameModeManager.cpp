#include "GameModeManager.h"


void AGameModeManager::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	
	cameraManager = NewObject<UCameraManager>(this);
}

