// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4HanoiSim.h"
#include "UE4HanoiSimController.h"

void AUE4HanoiSimController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeGameAndUI());
}


