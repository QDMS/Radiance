// Copyright TPGames


#include "UI/HUD/RadianceHUD.h"
#include "UI/Widget/RadianceUserWidget.h" 
#include "Blueprint/UserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* ARadianceHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (!OverlayWidgetControllerClass)
	{
		UE_LOG(LogTemp, Error, TEXT("Overlay Widget Controller Class is not set"));
		return nullptr;
	}

	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		if (!OverlayWidgetController)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to create Overlay Widget Controller"));
			return nullptr;
		}

		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallBacksToDependencies();

		return OverlayWidgetController;
	}

	return OverlayWidgetController;
}


void ARadianceHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_RadianceHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_RadianceHUD"));
    
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	if (!Widget)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create Overlay Widget"));
		return;
	}

	OverlayWidget = Cast<URadianceUserWidget>(Widget);
	if (!OverlayWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("Overlay Widget is not of type URadianceUserWidget"));
		return;
	}

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	if (!WidgetController)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to initialize Overlay Widget Controller"));
		return;
	}

	OverlayWidget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}

