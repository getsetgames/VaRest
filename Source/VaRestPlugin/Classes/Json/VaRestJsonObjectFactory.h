//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "VaRestJsonObjectFactory.generated.h"

UCLASS( CustomConstructor, CollapseCategories, HideCategories = Object)
class UVaRestJsonObjectFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
		
public:
	
	/** Default constructor */
	UVaRestJsonObjectFactory( const class FPostConstructInitializeProperties& PCIP );

	/* Begin UObject interface */
	virtual void PostInitProperties( );
	/* End UObject interface */

	/* Begin UFactory interface */
	virtual bool DoesSupportClass(UClass* Class) override;
	
	virtual UObject* FactoryCreateText( UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const TCHAR*& Buffer, const TCHAR* BufferEnd, FFeedbackContext* Warn ) override;

	/* End UFactory interface */
};

