// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "UnrealHanoiSimGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UNREALHANOISIM_API AUnrealHanoiSimGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	AUnrealHanoiSimGameModeBase();

	UFUNCTION(BlueprintCallable, Category = "HanoiSim")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
	UFUNCTION(BlueprintCallable, Category = "HanoiSim")
		void SetCount(FText level);


protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "HanoiSim")
		void EnqueueMoveCall(int32 level, int32 from = 0, int32 to = 2, int32 use = 1);
	UFUNCTION(BlueprintCallable, Category = "HanoiSim")
		void DequeueMoveCall();

	UPROPERTY()
		AActor* TowerManager;

	FTimerHandle MoveTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HanoiSim")
	float MoveDelay;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HanoiSim", meta = (AllowPrivateAccess = "true"))
		int32 HanoiCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HanoiSim", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;

	TQueue<int32> MoveCall;
};
