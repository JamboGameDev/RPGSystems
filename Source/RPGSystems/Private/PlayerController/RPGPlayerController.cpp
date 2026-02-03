// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/RPGPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Inventory/InventoryComponent.h"
#include "Net/UnrealNetwork.h"

ARPGPlayerController::ARPGPlayerController()
{
	bReplicates = true;

	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>("InventoryComponent");
	InventoryComponent->SetIsReplicated(true);
}

void ARPGPlayerController::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ARPGPlayerController, InventoryComponent);
}

UAbilitySystemComponent* ARPGPlayerController::GetAbilitySystemComponent() const
{
	return UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn());
}
