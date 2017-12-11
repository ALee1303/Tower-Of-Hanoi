// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealHanoiSim.h"
#include "UnrealHanoiSimGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "TowerManager.h"

AUnrealHanoiSimGameModeBase::AUnrealHanoiSimGameModeBase()
{
	MoveDelay = 2.0f;
}

void AUnrealHanoiSimGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	ChangeMenuWidget(StartingWidgetClass);

	/** Get TowerManager */
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATowerManager::StaticClass(), FoundActors);
	TowerManager = Cast<ATowerManager>(FoundActors[0]);

	HanoiCount = 8;

	Cast<ATowerManager>(TowerManager)->InitializeTowers(8);
	EnqueueMoveCall(8);
	GetWorldTimerManager().SetTimer(MoveTimer, this, &AUnrealHanoiSimGameModeBase::DequeueMoveCall, MoveDelay, false);
}

void AUnrealHanoiSimGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
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

void AUnrealHanoiSimGameModeBase::SetCount(FText level)
{
	FString toInt = level.ToString();
	HanoiCount = FCString::Atoi(*toInt);
}

void AUnrealHanoiSimGameModeBase::EnqueueMoveCall(int32 level, int32 from, int32 to, int32 use)
{
	if (level == 1)
	{
		MoveCall.Enqueue(from);
		MoveCall.Enqueue(to);
	}
	else
	{
		EnqueueMoveCall(level - 1, from, use, to);
		MoveCall.Enqueue(from);
		MoveCall.Enqueue(to);
		EnqueueMoveCall(level - 1, use, to, from);
	}
}

void AUnrealHanoiSimGameModeBase::DequeueMoveCall()
{
	if (!MoveCall.IsEmpty())
	{
		int32 from, to;
		MoveCall.Dequeue(from); MoveCall.Dequeue(to);
		Cast<ATowerManager>(TowerManager)->ChangeTower(from, to);
		TArray<AActor*> FoundActors;
		//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATowerManager::StaticClass(), FoundActors);
		//Cast<ATowerManager>(FoundActors[0])->ChangeTower(from, to);
		GetWorldTimerManager().SetTimer(MoveTimer, this, &AUnrealHanoiSimGameModeBase::DequeueMoveCall, MoveDelay, false);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(MoveTimer);
	}
}