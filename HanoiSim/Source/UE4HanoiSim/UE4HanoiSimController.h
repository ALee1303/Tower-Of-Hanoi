// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "UE4HanoiSimController.generated.h"

/**
 * 
 */
UCLASS()
class UE4HANOISIM_API AUE4HanoiSimController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
};
