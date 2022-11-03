// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraTPSCorr.h"
#include "Kismet/KismetMathLibrary.h"
#include "GizmosUtils.h"
ACameraTPSCorr::ACameraTPSCorr()
{
	PrimaryActorTick.bCanEverTick = true;
	cameraTarget = CreateDefaultSubobject<UCameraComponent>("Camera");
	lookAtSettings = CreateDefaultSubobject<UCameraRotationSettings>("LookAtSettings");
	positionSettings = CreateDefaultSubobject<UCameraPositionSettings>("MoveSettings");
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
	LookAtTarget();
	OnDrawDebug();
}

void ACameraTPSCorr::OnDrawDebug()
{
	if (!lookAtSettings)
		return;
	lookAtSettings->DrawLookAtStatus(GetActorLocation());
	lookAtSettings->DrawLookAtTarget(CurrentTargetLocation(), CurrentCameraLocation(), FColor::Red);
	positionSettings->DrawCameraPosition(GetTransform());
}

void ACameraTPSCorr::LookAtTarget()
{
	const FRotator& _dir = UKismetMathLibrary::FindLookAtRotation(CurrentCameraLocation(), CurrentTargetLocation());
	const FRotator& _final = lookAtSettings->UseSmoothLookAt() ? 
		FMath::RInterpTo(CurrentCameraRotation(), _dir, GetWorld()->DeltaTimeSeconds, lookAtSettings->RotationSpeed()):
		FMath::RInterpConstantTo(CurrentCameraRotation(), _dir, GetWorld()->DeltaTimeSeconds, lookAtSettings->RotationSpeed());
	
	SetActorRotation(_final);
}



