// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Disk.generated.h"

UCLASS()
class UNREALHANOISIM_API ADisk : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADisk();

	virtual void Tick(float DeltaTime) override;

	void MoveDisk(FVector Destination);
	void ChangeDiskScale(int32 Level);
	
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return DiskMesh; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Disk")
		FVector InitialScale;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Disk")
		FVector IncrementalScale;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Disk", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* DiskMesh;

};