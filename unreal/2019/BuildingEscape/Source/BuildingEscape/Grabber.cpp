/* Following Udemy Course */

#include "Grabber.h"
#include "DrawDebugHelpers.h"
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
    UE_LOG(LogTemp, Warning, TEXT("Input component found"));
    // bind the input axis
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

  // Get player view point this tick
  FVector PlayerViewPointLocation;
  FRotator PlayerViewPointRotator;
  GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
      OUT PlayerViewPointLocation, 
      OUT PlayerViewPointRotator
    );

  FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotator.Vector() * reach;

  // if the physics handle is attached 
  if (PhysicsHandle->GrabbedComponent)
  {
    // move the object that we're holding
    PhysicsHandle->SetTargetLocation(LineTraceEnd);
  }
}

void UGrabber::Grab()
{
  UE_LOG(LogTemp, Warning, TEXT("Grab Pressed."));

  // Line trace and see if we reach any actors with physics body collision channel set
  auto HitResult = GetFirstPhysicsBodyInReach();
  auto ComponentToGrab = HitResult.GetComponent();
  auto ActorHit = HitResult.GetActor();

  // If we hit something then attach a physics handle
  if (ActorHit)
  {
    // Attach physics handle
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
  UE_LOG(LogTemp, Warning, TEXT("Grab Released."));
  // TODO release physics handle
  PhysicsHandle->ReleaseComponent();
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
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
  return Hit;
}