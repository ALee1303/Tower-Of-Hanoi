// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealHanoiSim.h"
#include "Disk.h"


ADisk::ADisk()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DiskMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	RootComponent = DiskMesh;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> DiskVisualAsset(TEXT("/Game/StarterContent/Architecture/SM_AssetPlatform"));
	//if (DiskVisualAsset.Succeeded())
	//{
	//	DiskMesh->SetStaticMesh(DiskVisualAsset.Object);
	//}

	InitialScale = FVector(0.5f, 0.5f, 1.0f);
	DiskMesh->SetWorldScale3D(InitialScale);

	IncrementalScale = FVector(0.1f, 0.1f, 0.0f);
}

// Called every frame
void ADisk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADisk::MoveDisk(FVector Destination)
{
	DiskMesh->SetWorldLocation(Destination);
}

void ADisk::ChangeDiskScale(int32 Level)
{
	DiskMesh->SetWorldScale3D(InitialScale + IncrementalScale * Level);
}

void ADisk::BeginPlay()
{
	Super::BeginPlay();
}