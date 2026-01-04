#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "SilvaCharacter.generated.h"

// Animation
class UAnimBlueprint;

// Input
class UInputMappingContext;
class UInputAction;
class UInputComponent;

UCLASS()
class UE_PROJECT_API ASilvaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASilvaCharacter();

	// First Person animations
	UPROPERTY(EditAnywhere, Category = Animation)
	UAnimBlueprint *FirstPersonDefaultAnim;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	// Pointer that links IA to buttons
	TObjectPtr<UInputMappingContext> FirstPersonContext;

	// Move Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction *MoveAction;

	// Jump Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction *JumpAction;

	// Look Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction *LookAction;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	// Hanldes 2D movement input
	UFUNCTION()
	void Move(const FInputActionValue &Value);

	// Handles look input
	UFUNCTION()
	void Look(const FInputActionValue &Value);

	// First person camera
	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent *FirstPersonCameraComponent;

	// Offset for the first person camera
	UPROPERTY(EditAnywhere, Category = Camera)
	// FVector FirstPersonCameraOffset = FVector(2.8f, 5.9f, 0.0f);
	FVector FirstPersonCameraOffset = FVector(0.0f, 0.0f, 0.0f);

	// First-person camera field of view
	UPROPERTY(EditAnywhere, Category = Camera)
	float FirstPersonFieldOfView = 70.0f;

	// First-person camera view scale
	UPROPERTY(EditAnywhere, Category = Camera)
	float FirstPersonScale = 0.6f;

	// First-person mesh, visible only to the owning player
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	USkeletalMeshComponent *FirstPersonMeshComponent;
};