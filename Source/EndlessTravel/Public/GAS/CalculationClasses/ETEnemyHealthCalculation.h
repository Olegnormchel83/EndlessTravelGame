// Author: Olegnormchel. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ETEnemyHealthCalculation.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSTRAVEL_API UETEnemyHealthCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UETEnemyHealthCalculation();

	virtual void Execute_Implementation(
		const FGameplayEffectCustomExecutionParameters& ExecutionParams, 
		FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

private:
	float HealthModifier = 100.f;
};
