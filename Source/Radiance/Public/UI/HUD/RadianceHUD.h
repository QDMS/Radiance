// Copyright TPGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RadianceHUD.generated.h"

class URadianceUserWidget;
/**
 * 
 */
UCLASS()
class RADIANCE_API ARadianceHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<URadianceUserWidget> OverlayWidget;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "HUD")
	TSubclassOf<URadianceUserWidget> OverlayWidgetClass;
};
