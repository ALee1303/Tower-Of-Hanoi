// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4HanoiSim.h"
#include "HanoiBlock.h"


// Sets default values
AHanoiBlock::AHanoiBlock() :
	Speed(2.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;
	BoxVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));

	BoxVisual->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHanoiBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHanoiBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}