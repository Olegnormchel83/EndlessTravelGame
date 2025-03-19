// Author: Olegnormchel. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "ETHealthEnemyCalculation.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSTRAVEL_API UETHealthEnemyCalculation : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	float HealthModifier = 100.f;
};
