// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IOSAppTrackingTransparencySettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UIOSAppTrackingTransparencySettings : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(Config, EditAnywhere, Category = "IOS")
	FString TrackingRequestDescription;
	
};
