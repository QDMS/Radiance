// Copyright TPGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RadianceCharacterBase.generated.h"


UCLASS(Abstract)
class RADIANCE_API ARadianceCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ARadianceCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category= "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
