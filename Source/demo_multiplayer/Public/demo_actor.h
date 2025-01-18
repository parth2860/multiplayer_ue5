// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "demo_actor.generated.h"

UCLASS()
class DEMO_MULTIPLAYER_API Ademo_actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ademo_actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
