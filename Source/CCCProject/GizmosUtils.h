// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define WORLD GetWorld()
#define DRAW_SPHERE(position, radius, segment, color) DrawDebugSphere(WORLD, position, radius, segment, color)
#define DRAW_BOX(position, size, color) DrawDebugBox(WORLD, position, size, color)
#define DRAW_LINE(positionFrom, positionTo, color) DrawDebugLine(WORLD,positionFrom, positionTo,color)
#define DRAW_CIRCLE(position, radius, segment, color,yAxis, zAxis ) DrawDebugCircle(WORLD, position, radius,segment, color, false ,-1,0,2,yAxis, zAxis);