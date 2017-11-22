// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4HanoiSim.h"
#include "UE4HanoiSimGameModeBase.h"

void AUE4HanoiSimGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);
}

void AUE4HanoiSimGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void AUE4HanoiSimGameModeBase::SetCount(FText level)
{
	FString toInt = level.ToString();
	HanoiCount = FCString::Atoi(*toInt);
}


