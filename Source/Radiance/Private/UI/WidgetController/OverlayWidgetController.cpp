// Copyright TPGames


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/RadianceAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	URadianceAttributeSet* RadianceAttributeSet = CastChecked<URadianceAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(RadianceAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(RadianceAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(RadianceAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(RadianceAttributeSet->GetMaxMana());

	
}

void UOverlayWidgetController::BindCallBacksToDependencies()
{
	URadianceAttributeSet* RadianceAttributeSet = CastChecked<URadianceAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(RadianceAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(RadianceAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(RadianceAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(RadianceAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
