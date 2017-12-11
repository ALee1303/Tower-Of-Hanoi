// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealHanoiSim.h"
#include "Tower.h"
#include "Disk.h"


// Sets default values
ATower::ATower()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TowerLocation = CreateDefaultSubobject<USceneComponent>(TEXT("TowerPosition"));
	RootComponent = TowerLocation;
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ADisk* const ATower::PopDiskOnTop()
{
	return DiskStack.Pop();
}

void ATower::StackDiskOnTop(ADisk* DiskToStack)
{
	DiskToStack->MoveDisk(GetPositionToStack());
	DiskStack.Add(DiskToStack);
}

void ATower::SetAsStartTower(int32 HanoiCount)
{
	UWorld* World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParam;
		SpawnParam.Owner = this;
		SpawnParam.Instigator = Instigator;
		FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);
		for (int32 iDiskLevel = HanoiCount; iDiskLevel > 0; iDiskLevel--)
		{
			FVector SpawnLoc = GetPositionToStack();
			ADisk* SpawnedDisk = World->SpawnActor<ADisk>(DiskToSpawn, SpawnLoc, SpawnRotation, SpawnParam);
			SpawnedDisk->ChangeDiskScale(iDiskLevel - 1);
			DiskStack.Add(SpawnedDisk);
		}
	}
}

/** Array Related */
void ATower::ReserveTower(int32 Count)
{
	DiskStack.Reserve(Count);
}

void ATower::ResetTower(int32 NewCount)
{
	DiskStack.Reset(NewCount);
}

const FVector ATower::GetPositionToStack() const
{
	FVector position = TowerLocation->GetComponentScale();
	position.Z += StackOffset * (DiskStack.Num() - 1);
	return position;
}

const float ATower::StackOffset = 2.0f;