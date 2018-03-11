// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Disk.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS()
class UNREALHANOISIM_API ATower : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATower();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Stack Related
	ADisk* const PopDiskOnTop();
	void StackDiskOnTop(ADisk* DiskToStack);
	void SetAsStartTower(int32 HanoiCount);

	//for Array
	void ReserveTower(int32 Count);
	void ResetTower(int32 NewCount);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	const FVector GetPositionToStack() const;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tower", meta = (AllowPrivateAccess = "true"))
		USceneComponent* TowerLocation;
	UPROPERTY()
		TArray<ADisk*> DiskStack;
	UPROPERTY(EditAnywhere, Category = "SpawnDefault")
		TSubclassOf<ADisk> DiskToSpawn;

	UPROPERTY(EditAnywhere, Category = "SpawnDefault")
		float StackOffset;
};
