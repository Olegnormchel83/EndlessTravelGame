// Author: Olegnormchel. All rights reserved


#include "GAS/CalculationClasses/ETEnemyHealthCalculation.h"
#include "GAS/AttributeSet/ET_BaseAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"

UETEnemyHealthCalculation::UETEnemyHealthCalculation()
{
}

void UETEnemyHealthCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();

	if (!TargetASC) return;

	const UET_BaseAttributeSet* TargetAttributes = Cast<UET_BaseAttributeSet>(TargetASC->GetAttributeSet(UET_BaseAttributeSet::StaticClass()));
	if (!TargetAttributes) return;

	float Level = TargetAttributes->GetLevel();
	float FinalHealth = 0.f;

	if (Level == 1.f)
	{
		FinalHealth = 100.f;
	}
	else
	{
		float LevelSum = 0.f;
		for (int i = 1; i < Level; ++i)
		{
			LevelSum += i;
		}
		FinalHealth = LevelSum * HealthModifier;
	}

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UET_BaseAttributeSet::GetHealthAttribute(), EGameplayModOp::Additive, FinalHealth));
}
