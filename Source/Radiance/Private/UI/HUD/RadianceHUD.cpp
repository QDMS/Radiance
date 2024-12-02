// Copyright TPGames


#include "UI/HUD/RadianceHUD.h"
#include "UI/Widget/RadianceUserWidget.h" 
#include "Blueprint/UserWidget.h"

void ARadianceHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
