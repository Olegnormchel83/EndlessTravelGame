// Author: Olegnormchel. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "ETDamageCalculation.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSTRAVEL_API UETDamageCalculation : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	float DefenceCoeff = 0.2f;
};
