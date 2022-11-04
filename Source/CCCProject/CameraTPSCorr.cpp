// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraTPSCorr.h"
#include "Kismet/KismetMathLibrary.h"
#include "GizmosUtils.h"
ACameraTPSCorr::ACameraTPSCorr()
{
	PrimaryActorTick.bCanEverTick = true;
	cameraTarget = CreateDefaultSubobject<UCameraComponent>("Camera");
	//lookAtSettings = CreateDefaultSubobject<UCameraRotationSettings>("LookAtSettings");
	//positionSettings = CreateDefaultSubobject<UCameraPositionSettings>("MoveSettings");
	//lookAtSettings = NewObject<UCameraRotationSettings>(this, FName("lookAtSettings"));
	//positionSettings = NewObject<UCameraPositionSettings>(this, FName("positionSettings"));
	RootComponent = cameraTarget;
}

void ACameraTPSCorr::InitCamera()
{
	GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
}

void ACameraTPSCorr::BeginPlay()
{
	Super::BeginPlay();
	InitCamera();
}

void ACameraTPSCorr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToTarget();
	LookAtTarget();
	OnDrawDebug();
}

void ACameraTPSCorr::OnDrawDebug()
{
	if (!lookAtSettings)
		return;
	lookAtSettings->DrawLookAtStatus(GetActorLocation(), GetWorld());
	lookAtSettings->DrawLookAtTarget(CurrentTargetLocation(), CurrentCameraLocation(), FColor::Red,GetWorld());
	positionSettings->DrawCameraPosition(GetTransform(),GetWorld());
}

void ACameraTPSCorr::LookAtTarget()
{
	const FRotator& _dir = UKismetMathLibrary::FindLookAtRotation(CurrentCameraLocation(), CurrentTargetLocation());
	const FRotator& _final = lookAtSettings->UseSmoothLookAt() ? 
		FMath::RInterpTo(CurrentCameraRotation(), _dir, GetWorld()->DeltaTimeSeconds, lookAtSettings->RotationSpeed()):
		FMath::RInterpConstantTo(CurrentCameraRotation(), _dir, GetWorld()->DeltaTimeSeconds, lookAtSettings->RotationSpeed());
	
	SetActorRotation(_final);
}

void ACameraTPSCorr::MoveToTarget()
{
	if (!positionSettings->UseMoveTo())
		return;

	const FVector _newPos = positionSettings->UseSmoothMoveTo() ? FMath::VInterpTo(CurrentCameraLocation(), positionSettings->GetCameraPosition(target), GetWorld()->DeltaTimeSeconds, positionSettings->PositionSpeed()) :
										  FMath::VInterpConstantTo(CurrentCameraLocation(), positionSettings->GetCameraPosition(target), GetWorld()->DeltaTimeSeconds, positionSettings->PositionSpeed());
	SetActorLocation(_newPos);
}

