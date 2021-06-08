// Copyright Epic Games, Inc. All Rights Reserved.

#include "IOSAppTrackingTransparencyLib.h"

#if PLATFORM_IOS
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>
#endif

EIOSAppTrackingAuthStatus UIOSAppTrackingTransparencyLib::RequestIOSAppTracking()
{
#if PLATFORM_IOS
	if(@available(iOS 14.0, *))
	{
		[ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {}];
    }
#endif
	return GetIOSAppTrackingAuthStatus();
}

EIOSAppTrackingAuthStatus UIOSAppTrackingTransparencyLib::GetIOSAppTrackingAuthStatus()
{
#if PLATFORM_IOS
	if(@available(iOS 14.0, *))
	{
		switch ([ATTrackingManager trackingAuthorizationStatus])
		{
		case ATTrackingManagerAuthorizationStatusAuthorized:
			return EIOSAppTrackingAuthStatus::Authorized;
			break;
		case ATTrackingManagerAuthorizationStatusDenied:
			return EIOSAppTrackingAuthStatus::Denied;
			break;
		case ATTrackingManagerAuthorizationStatusRestricted:
			return EIOSAppTrackingAuthStatus::Restricted;
			break;
		case ATTrackingManagerAuthorizationStatusNotDetermined:
			return EIOSAppTrackingAuthStatus::NotDetermined;
			break;
		}
	}
#endif
	return EIOSAppTrackingAuthStatus::Restricted;
}
