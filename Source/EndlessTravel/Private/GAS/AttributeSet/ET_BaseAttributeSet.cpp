// Author: Olegnormchel. All rights reserved


#include "GAS/AttributeSet/ET_BaseAttributeSet.h"
#include "GameplayEffectExtension.h"

DEFINE_LOG_CATEGORY_STATIC(LogAttributeSet, All, All)


void UET_BaseAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.f, GetMaxStamina()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}

	if (Data.EvaluatedData.Attribute == GetStealthDurationAttribute())
	{
		SetStealthDuration(GetStealthDuration());
	}

	if (Data.EvaluatedData.Attribute == GetStealthPowerAttribute())
	{
		SetStealthPower(GetStealthPower());
	}
}

/*
void UET_BaseAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if (Attribute == GetHealthAttribute())
	{
		//UE_LOG(LogAttributeSet, Warning, TEXT("Health Change: Old=%.1f, New=%.1f, Max=%.1f"), GetHealth(), NewValue, GetMaxHealth());
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}

	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
		//UE_LOG(LogAttributeSet, Warning, TEXT("ManaAttributeChanged, NewValue: %.1f"), NewValue);
	}

	if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
		//UE_LOG(LogAttributeSet, Warning, TEXT("StaminaAttributeChanged, NewValue: %.1f"), NewValue);
	}
}
*/
