// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerControlSettings.h"
#include "PlayerControlComponent.generated.h"

#define DELTA_TIME GetWorld()->DeltaTimeSeconds

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CCCPROJECT_API UPlayerControlComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TObjectPtr<UPlayerControlSettings> controlSettings = nullptr;
	UPROPERTY(EditAnywhere)
		FName vAxisName = "Vertical";
	UPROPERTY(EditAnywhere)
		FName hAxisName = "Horizontal";
	float dampX = 0, dampY = 0, vAxis = 0, hAxis = 0;;
public:	
	UPlayerControlComponent();

	FORCEINLINE FVector PlayerVelocity()
	{
		if(!controlSettings)
			return FVector(0);

		if(controlSettings->UseLocal())
			return ((controlSettings->UseRotate() ? FVector(0) : GetOwner()->GetActorRightVector() * HorizontalDamping()) + GetOwner()->GetActorForwardVector() * VerticalDamping()) * controlSettings->GetMovementSpeed();

		return FVector((controlSettings->UseRotate() ? 0 : VerticalDamping() ,HorizontalDamping(), 0) * controlSettings->GetMovementSpeed());
	}
	FORCEINLINE FVector PlayerLocation() { return (PlayerVelocity() * DELTA_TIME) + GetOwner()->GetActorLocation(); }
	FORCEINLINE FRotator PlayerRotation() 
	{
		if (!controlSettings || !controlSettings->UseRotate())
			return FRotator(0);
		if(controlSettings->RotationPerSeconds())
			return FRotator(0, controlSettings->GetDegreesByTick() * HorizontalDamping() * DELTA_TIME, 0);
		
		return FRotator(0, controlSettings->GetDegreesByTick() * HorizontalDamping() * controlSettings->GetRotationSpeed(), 0);
	}

	FORCEINLINE float VerticalDamping()
	{
		if (controlSettings->UseDamp())
			return dampX = FMath::Lerp(dampX, vAxis, DELTA_TIME * 1 / controlSettings->GetWeight());

		return vAxis;
	}

	FORCEINLINE float HorizontalDamping()
	{
		if (controlSettings->UseDamp())
			return dampY = FMath::Lerp(dampY, hAxis, DELTA_TIME * 1 / controlSettings->GetWeight());

		return hAxis;
	}

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void BindCustom();
	void MoveByControls();
	void OnVerticalAxis(float _axis);
	void OnHorizontalAxis(float _axis);
	void DrawDebug();
};
