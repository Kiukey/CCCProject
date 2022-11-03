// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraTPS.h"
#include "Kismet/KismetMathLibrary.h"

ACameraTPS::ACameraTPS()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	currentCamera = CreateDefaultSubobject<UCameraComponent>("CurrentCamera");
	billboardComponent = CreateDefaultSubobject<UBillboardComponent>("Billboard");
	currentCamera->SetupAttachment(RootComponent);
	billboardComponent->SetupAttachment(RootComponent);
}

void ACameraTPS::BeginPlay()
{
	Super::BeginPlay();
	ActivateCamera();
}

void ACameraTPS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToTarget();
	LookAtTarget();
	DrawDebug();
}

void ACameraTPS::MoveToTarget()
{
	if (!IsCameraTPSValid() || !positionSettings.useMoveTo)
		return;

	const FVector _currentLocation = GetActorLocation();

	if (positionSettings.useSmoothMoveTo)
		SetActorLocation(FMath::Lerp(_currentLocation, positionSettings.GetCameraPosition(target), GetWorld()->DeltaTimeSeconds * positionSettings.positionSpeed));
	else 
		SetActorLocation(FMath::VInterpConstantTo(_currentLocation, positionSettings.GetCameraPosition(target), GetWorld()->DeltaTimeSeconds ,positionSettings.positionSpeed));
}

void ACameraTPS::LookAtTarget()
{
	if (!IsCameraTPSValid() || !lookAtSettings.useLookAt)
		return;
	const FVector _currentLocation = GetActorLocation();
	const FRotator _currentRotation = GetActorRotation();

	FRotator _rotation = UKismetMathLibrary::FindLookAtRotation(_currentLocation,target->GetActorLocation());
	if (lookAtSettings.useSmoothLookAt)
		SetActorRotation(FMath::Lerp(_currentRotation, _rotation, GetWorld()->DeltaTimeSeconds * lookAtSettings.rotationSpeed));
	else
		SetActorRotation(FMath::RInterpConstantTo(_currentRotation, _rotation, GetWorld()->DeltaTimeSeconds , lookAtSettings.rotationSpeed));
}

void ACameraTPS::DrawDebug()
{
	if (!useDebug)
		return;
	UWorld* _world = GetWorld();
	const FVector _currentLocation = GetActorLocation();

	positionSettings.DrawMoveToStatus(_world, _currentLocation);
	lookAtSettings.DrawLookAtStatus(_world, _currentLocation);
	if (!IsCameraTPSValid())
		return;
	lookAtSettings.DrawLookAtTarget(_world, target->GetActorLocation(), _currentLocation);
	positionSettings.DrawCameraPosition(_world, target);
}

void ACameraTPS::ActivateCamera()
{
	GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
}
