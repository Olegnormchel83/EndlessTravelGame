// Author: Olegnormchel. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

#include "ET_BaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class ENDLESSTRAVEL_API UET_BaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	//Health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Health", 
		meta = (ClampMin = "0", UIMin = "0"))
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, Health)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Health", 
		meta = (ClampMin = "0", UIMin = "0"))
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, MaxHealth)

	//Mana
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Mana", 
		meta = (ClampMin = "0", UIMin = "0"))
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, Mana)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Mana", 
		meta = (ClampMin = "0", UIMin = "0"))
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, MaxMana)

	//Stamina
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Stamina", 
			meta = (ClampMin = "0", UIMin = "0"))
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, Stamina)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Stamina", 
		meta = (ClampMin = "0", UIMin = "0"))
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, MaxStamina)

	//Stealth
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Stealth", 
			meta = (ClampMin = "5", UIMin = "5"))
	FGameplayAttributeData StealthDuration;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, StealthDuration)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Stealth", 
			meta = (ClampMin = "0", ClampMax = "1", UIMin = "0", UIMax = "1"))
	FGameplayAttributeData StealthPower;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, StealthPower)

	//Functions
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
