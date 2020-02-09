/* Following Udemy Course */

#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"

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

  // look for attached physics hanle
  PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
  if (!PhysicsHandle) 
  {
    UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName());
  }
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

  // setup query parameters
  FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

  // line-trace (aka ray-cast) out to reach distance
  FHitResult Hit;
  GetWorld()->LineTraceSingleByObjectType(
    OUT Hit,
    PlayerViewPointLocation,
    LineTraceEnd,
    FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
    TraceParameters
  );


  // See what we hit
  AActor* ActorHit = Hit.GetActor();
  if (ActorHit) 
  {
    UE_LOG(LogTemp, Warning, TEXT("In contact with: %s"), *(ActorHit->GetName()));
  }
}

