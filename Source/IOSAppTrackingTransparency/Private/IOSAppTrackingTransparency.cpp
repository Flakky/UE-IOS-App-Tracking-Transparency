// Copyright Epic Games, Inc. All Rights Reserved.

#include "IOSAppTrackingTransparency.h"
#include "IOSAppTrackingTransparencySettings.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FIOSAppTrackingTransparencyModule"

void FIOSAppTrackingTransparencyModule::StartupModule()
{
	IOSAppTrackingTransparencySettings = NewObject<UIOSAppTrackingTransparencySettings>(GetTransientPackage(), "IOSAppTrackingTransparencySettings", RF_Standalone);
	IOSAppTrackingTransparencySettings->AddToRoot();

	// Register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "IOSAppTrackingTransparency",
            LOCTEXT("RuntimeSettingsName", "IOSAppTrackingTransparency"),
            LOCTEXT("RuntimeSettingsDescription", "Configure IOS App Tracking Transparency plugin"),
            IOSAppTrackingTransparencySettings);
	}
}

void FIOSAppTrackingTransparencyModule::ShutdownModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "IOSAppTrackingTransparency");
	}

	if (!GExitPurge)
	{
		// If we're in exit purge, this object has already been destroyed
		IOSAppTrackingTransparencySettings->RemoveFromRoot();
	}
	else
	{
		IOSAppTrackingTransparencySettings = nullptr;
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FIOSAppTrackingTransparencyModule, IOSAppTrackingTransparency)