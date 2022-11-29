// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"
#include "GameFramework/PlayerController.h"

#define DELTA_TIME GetWorld()->DeltaTimeSeconds

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	InitInputs();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMovingActor::VerticalMove(float _axis)
{
	if (!controlPreset)
		return;
	SetActorLocation((GetPlayerVerticalVelocity(_axis) * DELTA_TIME) + GetActorLocation());
	
	//debug
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + GetPlayerVerticalVelocity(_axis), FColor::Red);
	DrawDebugSphere(GetWorld(), GetActorLocation() + GetPlayerVerticalVelocity(_axis), 30, 15, FColor::Red);

}

void AMovingActor::HorizontalMove(float _axis)
{
	if (!controlPreset)
		return;
	if (controlPreset->GetUseRotate())
	{
		AddActorWorldRotation(FRotator(0, (controlPreset->GetDegreesByTick()  * (controlPreset->GetRotationPerSeconds() ? DELTA_TIME /* ou 60 si on s'en fou que le mec RAM*/ : 1)) * HorizontalDamping(_axis) * controlPreset->GetRotationSpeed(), 0));
	}
	else
	{
		SetActorLocation((GetPlayerHorizontalVelocity(_axis) * DELTA_TIME) + GetActorLocation());
	}
}

float AMovingActor::VerticalDamping(float _axis)
{
	if (!controlPreset)
		return 0 ;

	if (controlPreset->GetUseDamp())
		return dampX = FMath::Lerp(dampX, _axis, DELTA_TIME * 1 / controlPreset->GetWeight());
	else
		return _axis;
}

float AMovingActor::HorizontalDamping(float _axis)
{
	if (controlPreset->GetUseDamp())
		return dampY = FMath::Lerp(dampY, _axis, DELTA_TIME * 1 / controlPreset->GetWeight());
	else
		return _axis;
}

FVector AMovingActor::GetPlayerVerticalVelocity(float _axis)
{
	if (!controlPreset)
		return FVector(0);

	return (FVector::ZeroVector+ (GetActorForwardVector() * VerticalDamping(_axis) * controlPreset->GetMovementSpeed()));
}

FVector AMovingActor::GetPlayerHorizontalVelocity(float _axis)
{
	if (!controlPreset)
		return FVector(0);

	if (controlPreset->GetUseLocal())
		return (controlPreset->GetUseRotate() ? FVector::ZeroVector : GetActorRightVector() * HorizontalDamping(_axis) * controlPreset->GetMovementSpeed());

	return FVector(0, (controlPreset->GetUseRotate() ? 0 : HorizontalDamping(_axis)) * controlPreset->GetMovementSpeed(), 0);
}

void AMovingActor::InitInputs()
{
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();
	if (!_controller)
		return;

	_controller->InputComponent->BindAxis("Horizontal", this, &AMovingActor::HorizontalMove);
	_controller->InputComponent->BindAxis("Vertical", this, &AMovingActor::VerticalMove);
}



