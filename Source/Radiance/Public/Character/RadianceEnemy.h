// Copyright TPGames

#pragma once

#include "CoreMinimal.h"
#include "Character/RadianceCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "RadianceEnemy.generated.h"

/**
 * 
 */
UCLASS()
class RADIANCE_API ARadianceEnemy : public ARadianceCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	ARadianceEnemy();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:
	virtual void BeginPlay() override;
};
