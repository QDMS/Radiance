// Copyright TPGames


#include "Player/RadiancePlayerState.h"

#include "AbilitySystem/RadianceAbilitySystemComponent.h"
#include "AbilitySystem/RadianceAttributeSet.h"

ARadiancePlayerState::ARadiancePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<URadianceAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<URadianceAttributeSet>("AttributeSet");
	// Use the setter method to configure the net update frequency
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* ARadiancePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
