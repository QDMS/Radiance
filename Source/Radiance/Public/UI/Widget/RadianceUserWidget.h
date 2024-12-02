 // Copyright TPGames

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RadianceUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class RADIANCE_API URadianceUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
