/* Following Udemy Course */

#include "Grabber.h"
#include "CollisionQueryParams.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();	
  FindPhysicsHandleComponent();
  SetupInputComponent();
}

// look for attached physics handle
void UGrabber::FindPhysicsHandleComponent()
{
  PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
  if (!PhysicsHandle) 
  {
    UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName());
  }
}

// look for attached Input Component (only appears at run time)
void UGrabber::SetupInputComponent()
{
  InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
  if (InputComponent)
  {
    InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
    InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
  } 
  else
  {
    UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *(GetOwner()->GetName()));
  }
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  // if the physics handle is attached 
  if (PhysicsHandle->GrabbedComponent)
  {
    // move the object that we're holding
    PhysicsHandle->SetTargetLocation(GetReachLineEnd());
  }
}

void UGrabber::Grab()
{
  // Line trace and see if we reach any actors with physics body collision channel set
  auto HitResult = GetFirstPhysicsBodyInReach();
  auto ComponentToGrab = HitResult.GetComponent(); // grabs mesh object from world
  auto ActorHit = HitResult.GetActor();

  // If we hit something then attach a physics handle
  if (ActorHit)
  {
    PhysicsHandle->GrabComponentAtLocationWithRotation(
      ComponentToGrab,
      NAME_None,
      HitResult.Location, 
      FRotator::ZeroRotator
    );
  }
}

void UGrabber::Release()
{
  PhysicsHandle->ReleaseComponent();
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
  // setup query parameters
  FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

  // line-trace (aka ray-cast) out to reach distance
  FHitResult HitResult;
  GetWorld()->LineTraceSingleByObjectType(
    OUT HitResult,
    GetReachLineStart(),
    GetReachLineEnd(),
    FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
    TraceParameters
  );
  return HitResult;
}

FVector UGrabber::GetReachLineStart() const
{
  // Get player view point 
  FVector PlayerViewPointLocation;
  FRotator PlayerViewPointRotator;
  GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
      OUT PlayerViewPointLocation, 
      OUT PlayerViewPointRotator
    );
  return PlayerViewPointLocation;
}

FVector UGrabber::GetReachLineEnd() const
{
  // Get player view point
  FVector PlayerViewPointLocation;
  FRotator PlayerViewPointRotator;
  GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
      OUT PlayerViewPointLocation, 
      OUT PlayerViewPointRotator
    );
  return PlayerViewPointLocation + PlayerViewPointRotator.Vector() * Reach;
}