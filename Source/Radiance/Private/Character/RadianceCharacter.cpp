// Copyright TPGames


#include "Character/RadianceCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/RadiancePlayerState.h"

ARadianceCharacter::ARadianceCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false; 
}

void ARadianceCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init Ability actor info for the Server
	InitAbilityActorInfo();
}

void ARadianceCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init Ability actor info for the Client 
	InitAbilityActorInfo();
}

void ARadianceCharacter::InitAbilityActorInfo()
{
	
	ARadiancePlayerState* RadiancePlayerState = GetPlayerState<ARadiancePlayerState>();
	check(RadiancePlayerState);
	RadiancePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RadiancePlayerState, this);
	AbilitySystemComponent = RadiancePlayerState->GetAbilitySystemComponent();
	AttributeSet = RadiancePlayerState->GetAttributeSet();
}
