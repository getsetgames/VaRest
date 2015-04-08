// Copyright 2014 Vladimir Alyamkin. All Rights Reserved.

#include "VaRestPluginPrivatePCH.h"
#include "Json/VaRestJsonObjectAssetTypeActions.h"

class FVaRestPlugin : public IVaRestPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{
		// @HACK Force classes to be compiled on shipping build
		UVaRestJsonObject::StaticClass();
		UVaRestJsonValue::StaticClass();
		UVaRestRequestJSON::StaticClass();
		UVaRestParseManager::StaticClass();
		
		// Register asset types
		if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
		{
			IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

			JsonObjectAssetTypeActions = MakeShareable(new FVaRestJsonObjectAssetTypeActions);
			AssetTools.RegisterAssetTypeActions(JsonObjectAssetTypeActions.ToSharedRef());
		}
	}

	virtual void ShutdownModule() override
	{
		if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
		{
			IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
			if (JsonObjectAssetTypeActions.IsValid())
			{
				AssetTools.UnregisterAssetTypeActions(JsonObjectAssetTypeActions.ToSharedRef());
			}
		}
	}
	
private:
	TSharedPtr<IAssetTypeActions> JsonObjectAssetTypeActions;
};

IMPLEMENT_MODULE( FVaRestPlugin, VaRestPlugin )

DEFINE_LOG_CATEGORY(LogVaRest);
