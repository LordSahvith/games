// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

  UE_LOG(LogTemp, Warning, TEXT("Grabber is working."));		
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player view point this tick
  FVector PlayerViewPointLocation;
  FRotator PlayerViewPointRotator;
  GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
      OUT PlayerViewPointLocation, 
      OUT PlayerViewPointRotator
    );

  // UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"), *PlayerViewPointLocation.ToString(), *PlayerViewPointRotator.ToString());

  FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotator.Vector() * reach;

  // Draw red trace in thw world to visualize
  DrawDebugLine(
    GetWorld(),
    PlayerViewPointLocation,
    LineTraceEnd,
    FColor(255, 0, 0),
    false,
    0.f,
    0.f,
    10.f
  );

  // See what we hit
}

