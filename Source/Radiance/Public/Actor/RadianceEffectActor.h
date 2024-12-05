// Copyright TPGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RadianceEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class RADIANCE_API ARadianceEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	

	ARadianceEffectActor();


protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appied Effects") 
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appied Effects") 
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass; 
};
