//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "VaRestPluginPrivatePCH.h"

#if WITH_EDITOR

/** Constructor */
UVaRestJsonObjectFactory::UVaRestJsonObjectFactory(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	SupportedClass = UVaRestJsonObject::StaticClass();

	Formats.Add(TEXT("json;JSON Object"));
	
	bText = true;
	bCreateNew = false;
	bEditorImport = true;
}

/** Post init properties */
void UVaRestJsonObjectFactory::PostInitProperties()
{
	Super::PostInitProperties();
}

/** Does support class*/
bool UVaRestJsonObjectFactory::DoesSupportClass(UClass* Class)
{
	return Class == UVaRestJsonObject::StaticClass();
}

UObject* UVaRestJsonObjectFactory::FactoryCreateText(UClass *InClass,
													 UObject *InParent,
													 FName InName,
													 EObjectFlags Flags,
													 UObject *Context,
													 const TCHAR *Type,
													 const TCHAR *&Buffer,
													 const TCHAR *BufferEnd,
													 FFeedbackContext *Warn)
{
	const FString CurrentFilename = UFactory::GetCurrentFilename();

	UVaRestJsonObject* JsonObject = NewNamedObject<UVaRestJsonObject>(InParent, InName, Flags);
	
	int32 NumChars = (BufferEnd - Buffer);
	bool success = JsonObject->DecodeJson(FString(NumChars,Buffer));
	
	return JsonObject;
}

#endif