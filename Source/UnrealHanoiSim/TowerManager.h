// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tower.h"
#include "GameFramework/Actor.h"
#include "TowerManager.generated.h"

UCLASS()
class UNREALHANOISIM_API ATowerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerManager();

	UFUNCTION(BlueprintCallable, Category = "TowerManager")
		void InitializeTowers(int32 HanoiCount);
	UFUNCTION(BlueprintCallable, Category = "TowerManager")
		void ChangeTower(int32 from, int32 to);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "SpawnDefault")
		TSubclassOf<ATower> TowerToSpawn;

private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerManager", meta = (AllowPrivateAccess = "true"))
		USceneComponent* TowersStartPosition;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TowerManager", meta = (AllowPrivateAccess = "true"))
		FVector TowersOffset;


	UPROPERTY()
		TArray<ATower*> TowerOfHanoi;
	
};
