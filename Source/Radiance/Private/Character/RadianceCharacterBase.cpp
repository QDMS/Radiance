// Copyright TPGames


#include "Character/RadianceCharacterBase.h"

ARadianceCharacterBase::ARadianceCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ARadianceCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ARadianceCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



