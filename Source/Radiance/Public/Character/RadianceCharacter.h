// Copyright TPGames

#pragma once

#include "CoreMinimal.h"
#include "Character/RadianceCharacterBase.h"
#include "RadianceCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RADIANCE_API ARadianceCharacter : public ARadianceCharacterBase
{
	GENERATED_BODY()
public:
	ARadianceCharacter();
	virtual  void PossessedBy(AController* NewController) override;
	virtual  void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
