// Copyright TPGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RadiancePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class RADIANCE_API ARadiancePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ARadiancePlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> RadianceContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};