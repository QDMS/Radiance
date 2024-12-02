// Copyright TPGames


#include "UI/WidgetController/RadianceWidgetController.h"
#include "GameFramework/PlayerController.h"

FWidgetControllerParams::FWidgetControllerParams()
	: PlayerController(nullptr),
	  PlayerState(nullptr),
	  AbilitySystemComponent(nullptr),
	  AttributeSet(nullptr) {}

void URadianceWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void URadianceWidgetController::BroadcastInitialValues()
{
	
}

void URadianceWidgetController::BindCallBacksToDependencies()
{
	
}
