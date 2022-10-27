// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FollowSmoothMoveComponent.h"
#include "FollowConstMoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CCCPROJECT_API UFollowConstMoveComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		FMoveSettings moveSettings;
	UPROPERTY(EditAnywhere)
		FDebugSettings debugSettings;
public:	
	// Sets default values for this component's properties
	UFollowConstMoveComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	void FollowTargetConst();
	void DrawDebug();
};
