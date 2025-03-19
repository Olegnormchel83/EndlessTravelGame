// Author: Olegnormchel. All rights reserved


#include "GAS/CalculationClasses/ETHealthEnemyCalculation.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GAS/AttributeSet/ET_BaseAttributeSet.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthCalculation, All, All);

float UETHealthEnemyCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayEffectContextHandle& Context = Spec.GetContext();
	UAbilitySystemComponent* ASC = Context.GetOriginalInstigatorAbilitySystemComponent();
	if (!ASC)
	{
		UE_LOG(LogHealthCalculation, Warning, TEXT("ASC = nullptr, return default value 100"));
		return 100.f;
	}

	const UET_BaseAttributeSet* Attributes = Cast<UET_BaseAttributeSet>(ASC->GetAttributeSet(UET_BaseAttributeSet::StaticClass()));
	if (!Attributes)
	{
		UE_LOG(LogHealthCalculation, Warning, TEXT("Attributes = nullptr, return default value 100"));
		return 100.f;
	}

	float Level = Attributes->GetLevel();
	UE_LOG(LogHealthCalculation, Warning, TEXT("InLevel: %.0f"), Level);
	float FinalHealth = 0.f;

	if (Level == 1.f)
	{
		FinalHealth = 100.f;
	}
	else
	{
		float LevelsSum = 0.f;
		for (int i = 1; i <= Level; ++i)
		{
			LevelsSum += i;
		}
		FinalHealth = LevelsSum * HealthModifier;
	}

	UE_LOG(LogHealthCalculation, Warning, TEXT("EnemyLevel: %.0f"), Level);
	UE_LOG(LogHealthCalculation, Warning, TEXT("EnemyHealth: %.0f"), FinalHealth);

	return FinalHealth;
}
