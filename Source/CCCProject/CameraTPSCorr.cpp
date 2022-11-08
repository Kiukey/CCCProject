// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraTPSCorr.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameModeManager.h"
#include "GizmosUtils.h"
ACameraTPSCorr::ACameraTPSCorr()
{
	PrimaryActorTick.bCanEverTick = true;
	cameraTarget = CreateDefaultSubobject<UCameraComponent>("Camera");
	RootComponent = cameraTarget;
}

void ACameraTPSCorr::InitCamera()
{
	if (GetCameraManager())
		GetCameraManager()->AddCamera(this);

}

void ACameraTPSCorr::BeginPlay()
{
	Super::BeginPlay();
	InitCamera();
}

void ACameraTPSCorr::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (GetCameraManager())
		GetCameraManager()->RemoveCamera(this);

	Super::EndPlay(EndPlayReason);
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
	if (!target)
		return;
	const FRotator& _dir = UKismetMathLibrary::FindLookAtRotation(CurrentCameraLocation(), CurrentTargetLocation());
	const FRotator& _final = lookAtSettings->UseSmoothLookAt() ? 
		FMath::RInterpTo(CurrentCameraRotation(), _dir, GetWorld()->DeltaTimeSeconds, lookAtSettings->RotationSpeed()):
		FMath::RInterpConstantTo(CurrentCameraRotation(), _dir, GetWorld()->DeltaTimeSeconds, lookAtSettings->RotationSpeed());
	
	SetActorRotation(_final);
}

void ACameraTPSCorr::MoveToTarget()
{
	if (!target || !positionSettings->UseMoveTo())
		return;

	const FVector _newPos = positionSettings->UseSmoothMoveTo() ? FMath::VInterpTo(CurrentCameraLocation(), positionSettings->GetCameraPosition(target), GetWorld()->DeltaTimeSeconds, positionSettings->PositionSpeed()) :
										  FMath::VInterpConstantTo(CurrentCameraLocation(), positionSettings->GetCameraPosition(target), GetWorld()->DeltaTimeSeconds, positionSettings->PositionSpeed());
	SetActorLocation(_newPos);
}

void ACameraTPSCorr::CreateDefaultSettings(FVector _lookAtOffset, FVector _movementOffset)
{
	lookAtSettings = NewObject<UCameraRotationSettings>(this);
	lookAtSettings->GetOffset().SetOffset(_lookAtOffset);
	positionSettings = NewObject<UCameraPositionSettings>(this);
	positionSettings->GetOffset().SetOffset(_movementOffset);

}

TObjectPtr<class UCameraManager> ACameraTPSCorr::GetCameraManager()
{
	TObjectPtr<AGameModeManager> _gm = GetWorld()->GetAuthGameMode<AGameModeManager>();
	if (!_gm)
		return nullptr;

	return _gm->IsValidCameraManager() ? _gm->CameraManager() : nullptr;
}

void ACameraTPSCorr::Enable()
{
	GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
}
void ACameraTPSCorr::Disable()
{
}
