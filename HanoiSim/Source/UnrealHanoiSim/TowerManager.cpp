// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealHanoiSim.h"
#include "TowerManager.h"


// Sets default values
ATowerManager::ATowerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TowersStartPosition = CreateDefaultSubobject<USceneComponent>(TEXT("StartPosition"));
	RootComponent = TowersStartPosition;
	TowersOffset = FVector(50.0f, 0.0f, 0.0f);
}

// Called when the game starts or when spawned
void ATowerManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATowerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATowerManager::InitializeTowers(int32 HanoiCount)
{
	//if first time spawning towers
	if (TowerOfHanoi.Num() == 0)
	{
		TowerOfHanoi.Reset(3);
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParam;
			SpawnParam.Owner = this;
			SpawnParam.Instigator = Instigator;
			FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);
			for (int32 iTowerCount = 0; iTowerCount < 3; iTowerCount++)
			{
				FVector SpawnLoc = TowersStartPosition->GetComponentLocation() + TowersOffset * iTowerCount;
				ATower* SpawnedTower = World->SpawnActor<ATower>(TowerToSpawn, SpawnLoc, SpawnRotation, SpawnParam);
				TowerOfHanoi.Add(SpawnedTower);
				TowerOfHanoi[iTowerCount]->ReserveTower(HanoiCount);
			}
		}
	}
	//or reset the arrays
	else
	{
		for (int32 iTowerCount = 0; iTowerCount < 3; iTowerCount++)
		{
			TowerOfHanoi[iTowerCount]->ResetTower(HanoiCount);
		}
	}
	// fill first tower with new disk
	TowerOfHanoi[0]->SetAsStartTower(HanoiCount);
}

void ATowerManager::ChangeTower(int32 from, int32 to)
{
	ADisk* DiskToMove = TowerOfHanoi[from]->PopDiskOnTop();
	TowerOfHanoi[to]->StackDiskOnTop(DiskToMove);
}