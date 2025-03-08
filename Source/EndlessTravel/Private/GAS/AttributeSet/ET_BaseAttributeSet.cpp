// Author: Olegnormchel. All rights reserved


#include "GAS/AttributeSet/ET_BaseAttributeSet.h"
#include "GameplayEffectExtension.h"

void UET_BaseAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0, GetMaxStamina()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0, GetMaxMana()));
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
