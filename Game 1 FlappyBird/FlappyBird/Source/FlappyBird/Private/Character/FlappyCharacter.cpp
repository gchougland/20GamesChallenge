// 


#include "FlappyBird/Public/Character/FlappyCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraActor.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AFlappyCharacter::AFlappyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetSimulatePhysics(true);
	GetCapsuleComponent()->SetEnableGravity(true);
}

void AFlappyCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(FlappyContext);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	check(PlayerController);
	if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(FlappyContext, 0);
	}

	PlayerController->SetViewTargetWithBlend(GameCamera);
}

void AFlappyCharacter::Flap(const FInputActionValue& Value)
{
	GetCapsuleComponent()->AddImpulse(FVector(0,0,FlapImpulse));
}

void AFlappyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFlappyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(FlapAction, ETriggerEvent::Started, this, &ThisClass::Flap);
}

