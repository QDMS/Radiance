// Copyright TPGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "RadianceCharacterBase.generated.h"



class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class RADIANCE_API ARadianceCharacterBase : public ACharacter, public IAbilitySystemInterface  
{
	GENERATED_BODY()

public:
	ARadianceCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet;}
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category= "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
