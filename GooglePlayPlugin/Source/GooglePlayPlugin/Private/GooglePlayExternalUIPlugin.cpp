// Copyright Epic Games, Inc. All Rights Reserved.

#include "..\Public\GooglePlayPlugin.h"
#include "Core.h"
#include "Modules/ModuleManager.h"


IMPLEMENT_MODULE(FGooglePlayPluginModule, GooglePlayPlugin)

void FGooglePlayPluginModule::StartupModule()
{
#if PLATFORM_ANDROID
	UJavaFunctionLibrary::InitJavaFunctions();
#endif
}

void FGooglePlayPluginModule::ShutdownModule()
{
	
}

