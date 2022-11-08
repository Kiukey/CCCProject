#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CameraManager.h"
#include "GameModeManager.generated.h"


UCLASS()
class CCCPROJECT_API AGameModeManager : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite ,meta = (EditInLine, AllowPrivateAccess))
		TObjectPtr<UCameraManager> cameraManager = nullptr;


public:
	FORCEINLINE TObjectPtr<UCameraManager> CameraManager() const { return cameraManager; }
	FORCEINLINE bool IsValidCameraManager() const { return cameraManager != nullptr; }
private:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);

};
