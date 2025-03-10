// Author: Olegnormchel. All rights reserved


#include "GAS/ETDamageCalculation.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GAS/AttributeSet/ET_BaseAttributeSet.h"

DEFINE_LOG_CATEGORY_STATIC(LogETDamageCalculation, All, All);

float UETDamageCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	UAbilitySystemComponent* TargetASC = Spec.GetContext().GetInstigatorAbilitySystemComponent();
	if (!TargetASC) return 0.f;

	const UET_BaseAttributeSet* TargetAttributes = Cast<UET_BaseAttributeSet>(TargetASC->GetAttributeSet(UET_BaseAttributeSet::StaticClass()));
	if (!TargetAttributes) return 0.f;

	UAbilitySystemComponent* SourceASC = Spec.GetEffectContext().GetInstigatorAbilitySystemComponent();
	if (!SourceASC) return 0.f;

	const UET_BaseAttributeSet* SourceAttributes = Cast<UET_BaseAttributeSet>(SourceASC->GetAttributeSet(UET_BaseAttributeSet::StaticClass()));
	if (!SourceAttributes) return 0.f;

	FAggregatorEvaluateParameters EvalParams;
	EvalParams.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvalParams.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float TargetArmor = TargetAttributes->GetArmor();
	float TargetEvasion = TargetAttributes->GetEvasion();

	float SourceCritChance = SourceAttributes->GetCriticalChance();
	float SourceCritDamage = SourceAttributes->GetCriticalDamage();

	float BaseDamage = Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Effect.Ability.Shoot.Damage")), false, 0.f);

	if (FMath::RandRange(0.f, 100.f) < TargetEvasion)
	{
		UE_LOG(LogETDamageCalculation, Display, TEXT("Target Evasion worked"));
		return 0.f;
	}

	bool bIsCriticalHit = FMath::RandRange(0.f, 100.f) < SourceCritChance;
	float FinalDamage = BaseDamage;

	if (bIsCriticalHit)
	{
		UE_LOG(LogETDamageCalculation, Display, TEXT("Source crit worked"));
		FinalDamage = BaseDamage * SourceCritDamage;
	}

	FinalDamage *= (100.f / (100.f + TargetArmor * DefenceCoeff));
	UE_LOG(LogETDamageCalculation, Display, TEXT("Final damage: %.2f"), FinalDamage);

	return FinalDamage;
}
