// Fill out your copyright notice in the Description page of Project Settings.


#include "ARL_Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AARL_Character::AARL_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AARL_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARL_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AARL_Character::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

// Called to bind functionality to input
void AARL_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AARL_Character::MoveForward);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}