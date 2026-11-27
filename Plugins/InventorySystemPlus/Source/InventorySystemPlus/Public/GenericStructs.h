// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericStructs.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8 // Decides what type of item it is, and how this item will be used in the game.
{
	Consumable UMETA(DisplayName = "Consumable"),
	Equipment UMETA(DisplayName = "Equipment"),
	Miscellaneous UMETA(DisplayName = "Miscellaneous")
};

UENUM(BlueprintType)
enum class EItemCategory : uint8 // Decides what inventory tab the item will be placed in, and what type of item it is.
{
	Loot UMETA(DisplayName = "Loot"),
	Placeable UMETA(DisplayName = "Placeable"),
	Material UMETA(DisplayName = "Material")
};

UENUM(BlueprintType)
enum class EItemRarity : uint8 // Decides the rarity of the item, affecting its value and drop chances.
{
	Standard UMETA(DisplayName = "Standard"),
	Common UMETA(DisplayName = "Common"),
	Rare UMETA(DisplayName = "Rare"),
	Epic UMETA(DisplayName = "Epic"),
	Legendary UMETA(DisplayName = "Legendary"),
	Unique UMETA(DisplayName = "Unique")
};

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	// The name of the item.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FString ItemName; 

	// The unique identifier for the item.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 ItemID; 

	// The icon representing the item in the inventory.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UTexture2D* ItemIcon;

	// The rarity of the item.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	EItemRarity ItemRarity; 

	// The type of the item.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	EItemType ItemType; 

	// The category of the item.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	EItemCategory ItemCategory; 

	// The size of the item in the inventory grid (width, height).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FVector SlotSize; 

	// The quantity of the item in the inventory.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 Quantity; 


	FInventoryItem()
		: ItemName(TEXT("")), ItemID(0), ItemIcon(nullptr), ItemRarity(EItemRarity::Standard), ItemType(EItemType::Miscellaneous), ItemCategory(EItemCategory::Material), SlotSize(FVector::OneVector), Quantity(0)
	{
	}
	/*FInventoryItem(FString Name, int32 ID, UTexture2D* Icon, EItemRarity InItemRarity, EItemType InItemType, EItemCategory InItemCategory, FVector InSlotSize, int32 Qty)
		: ItemName(Name), ItemID(ID), ItemIcon(Icon), ItemRarity(InItemRarity), ItemType(InItemType), ItemCategory(InItemCategory), SlotSize(InSlotSize), Quantity(Qty)
	{
	}
	*/
};

/**
 * 
 */
class INVENTORYSYSTEMPLUS_API GenericStructs
{
public:
	GenericStructs();
	~GenericStructs();
};
