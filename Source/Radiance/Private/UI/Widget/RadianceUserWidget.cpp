// Copyright TPGames


#include "UI/Widget/RadianceUserWidget.h"

void URadianceUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
