// 

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"

#include "FlappyCharacter.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS()
class FLAPPYBIRD_API AFlappyCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	AFlappyCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float FlapImpulse = 100.f;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<ACameraActor> GameCamera;

private:

	UPROPERTY(EditDefaultsOnly, Category=Input)
	TObjectPtr<UInputMappingContext> FlappyContext;

	UPROPERTY(EditDefaultsOnly, Category=Input)
	TObjectPtr<UInputAction> FlapAction;

	void Flap(const FInputActionValue& Value);
};
