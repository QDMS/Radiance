// Copyright TPGames


#include "Character/RadianceCharacterBase.h"

ARadianceCharacterBase::ARadianceCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ARadianceCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



