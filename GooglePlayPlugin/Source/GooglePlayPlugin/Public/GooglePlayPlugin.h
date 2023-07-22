// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FGooglePlayPluginModule : public IModuleInterface
{
public:
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


};
