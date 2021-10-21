# Unreal Engine IOS App Tracking Transparency Plugin
A plugin with App Tracking Transparency integration for an Unreal Engine project.

**UE Versions**: 4.25, 4.26, 4.27

## Usage

1. First of all, add this plugin to your project in Plugins folder (Ex. Project/Plugins/UEIOSAppTrackingTransparency).

2. Regenerate your project files and build editor dlls of your project in VS (or whatever IDE you use) or XCode. Or simply open the project, it will promt you to compile it.

3. Somewhere before analytics initialization call **RequestIOSAppTracking** from C++ or Blueprints.

4. In Project Settings > IOSAppTrackingTransparency setup a description, that will be shown to a user in request dialog window.

## Available functions

**RequestIOSAppTracking()** - Promts user to give IDFA usage permission. Should output EIOSAppTrackingAuthStatus with the result.

**GetIOSAppTrackingAuthStatus()** - Outputs the current status of user's permission to use analytics identifier (IDFA).
