// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FollowSmoothMoveComponent.h"
#include "Move.h"
#include "FollowSmoothMovementComponent.generated.h"

USTRUCT()
struct FMovementSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> target = nullptr; // = AActor*
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, UIMax = 100, ClampMin = 0, ClampMax = 100))
		float speed = 10;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, UIMax = 1000, ClampMin = 0, ClampMax = 1000))
		float range = 100;
	UPROPERTY(EditAnywhere)
		bool isPause = false;
	FORCEINLINE FVector TargetPosition()
	{
		if (target.Get() != nullptr)
			return target.Get()->GetActorLocation();

		return FVector(0);
	}
	FORCEINLINE bool IsAtRange(FVector _origin)
	{
		return FVector::Distance(_origin, TargetPosition()) < range;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CCCPROJECT_API UFollowSmoothMovementComponent : public UActorComponent, public IMove
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Movement Settings")
		FMovementSettings settings;	
	UPROPERTY(EditAnywhere, Category = "Movement Settings")
		FDebugSettings debugSettings;

public:	
	UFollowSmoothMovementComponent();
	FORCEINLINE FMovementSettings& Settings() { return settings; }
	FORCEINLINE FVector CurrentPosition() const { return GetOwner()->GetActorLocation(); }
	FORCEINLINE bool IsValidComponent() const { return settings.target != nullptr; }
#pragma region IMOVE
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Movement)
		void MoveToTarget();
	virtual void MoveToTarget_Implementation();

#pragma endregion
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//void MoveToTarget();
	void DrawDebug();
};
