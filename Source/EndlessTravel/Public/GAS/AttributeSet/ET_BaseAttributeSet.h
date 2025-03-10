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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, Health)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, MaxHealth)

	//Mana
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Mana")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, Mana)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Mana")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, MaxMana)

	//Stamina
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Stamina")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, Stamina)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Stamina")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, MaxStamina)

	//Armor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Armor")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, Armor)

	//Evasion
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Evasion")
	FGameplayAttributeData Evasion;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, Evasion)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Evasion")
	FGameplayAttributeData MaxEvasion;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, MaxEvasion)

	//Stealth
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Stealth")
	FGameplayAttributeData StealthDuration;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, StealthDuration)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Stealth")
	FGameplayAttributeData StealthPower;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, StealthPower)

	//Combat
	//Combat|Crit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Combat|Crit")
	FGameplayAttributeData CriticalChance;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, CriticalChance)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Combat|Crit")
	FGameplayAttributeData CriticalDamage;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, CriticalDamage)

	//Combat|Weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Combat|Weapon")
	FGameplayAttributeData WeaponDamage;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, WeaponDamage)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Combat|Weapon")
	FGameplayAttributeData WeaponDistance;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, WeaponDistance)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Combat|Weapon")
	FGameplayAttributeData ShellCount;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, ShellCount)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Combat|Weapon")
	FGameplayAttributeData FireRate;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, FireRate)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Combat|Weapon")
	FGameplayAttributeData CurrentPatronsCount;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, CurrentPatronsCount)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Combat|Weapon")
	FGameplayAttributeData MaxPatronsCount;
	ATTRIBUTE_ACCESSORS(UET_BaseAttributeSet, MaxPatronsCount)

	//Functions
		virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

		//virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};