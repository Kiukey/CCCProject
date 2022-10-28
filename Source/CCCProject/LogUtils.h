// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define LOG(msg) UE_LOG(LogTemp, Log, TEXT(msg));
#define LOG_WARNING(msg) UE_LOG(LogTemp, Warning, TEXT(msg));
#define LOG_ERROR(msg) UE_LOG(LogTemp, Error, TEXT(msg));
#define SCREEN_MSG(msg, time , color) GEngine->AddOnScreenDebugMessage(-1, time, color, TEXT(msg));
