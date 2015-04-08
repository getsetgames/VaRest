// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "VaRestPluginPrivatePCH.h"
#include "VaRestJsonObjectAssetTypeActions.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

//////////////////////////////////////////////////////////////////////////
// FPaperSpriteSheetImportAssetTypeActions

FText FVaRestJsonObjectAssetTypeActions::GetName() const
{
	return LOCTEXT("FJsonObjectAssetTypeActionsName", "JSON Object");
}

FColor FVaRestJsonObjectAssetTypeActions::GetTypeColor() const
{
	return FColorList::BrightGold;
}

UClass* FVaRestJsonObjectAssetTypeActions::GetSupportedClass() const
{
	return UVaRestJsonObject::StaticClass();
}

uint32 FVaRestJsonObjectAssetTypeActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

bool FVaRestJsonObjectAssetTypeActions::IsImportedAsset() const
{
	return true;
}

#undef LOCTEXT_NAMESPACE

