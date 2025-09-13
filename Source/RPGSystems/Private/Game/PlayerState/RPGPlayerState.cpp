// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PlayerState/RPGPlayerState.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/Attributes/RPGAttributeSet.h"

ARPGPlayerState::ARPGPlayerState()
{
	SetNetUpdateFrequency(100.0f);
	SetMinNetUpdateFrequency(60.0f);

	RPGAbilitySystemComp = CreateDefaultSubobject<URPGAbilitySystemComponent>("AbilitySystemComp");
	RPGAbilitySystemComp->SetIsReplicated(true);
	RPGAbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	RPGAttributeset = CreateDefaultSubobject<URPGAttributeSet>("Attributeset");
}

UAbilitySystemComponent* ARPGPlayerState::GetAbilitySystemComponent() const
{
	return RPGAbilitySystemComp;
}

URPGAbilitySystemComponent* ARPGPlayerState::GetRPGAbilitySystemComponent() const
{
	return RPGAbilitySystemComp;
}

URPGAttributeSet* ARPGPlayerState::GetRPGAttributeSet() const
{
	return RPGAttributeset;
}
