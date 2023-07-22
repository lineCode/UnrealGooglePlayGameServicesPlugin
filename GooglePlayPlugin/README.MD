#  Google Play Plugin

#### Description

This plugin serves as an interface for the [Google Play Game Services V2](https://developers.google.com/games/services/android/quickstart) Java SDK in Unreal Engine. Currently, it only implements the authentication functionality.

#### How does it work?

It works by utilizing [UPL](https://gist.github.com/TimTinkers/31b35a50e3aaddb5889137fc87fea1d5) (Unreal Plugin Language) to modify Android's engine source files (Manifest.XML, AAR_Imports.txt, GameActivity.Java) during the build process.

#### Oh no, it's not working! What can I do?

1. Check if the current version of the SDK under `GooglePlayPlugin/Source/GooglePlay_APL.XML` is valid.

2. Ensure that your app is configured to be signed and check the "for distribution" checkbox under project settings.

3. Verify if the OAuth configuration has the same signature as your app. You can use [`print-apk-signature`](https://github.com/warren-bank/print-apk-signature) to check if your `.apk` is being signed correctly.

4. Compare your project with Bacon Run and check what is different.

5. Check if you configured it in the portal as the [documentation](https://developers.google.com/games/services/console/enabling) said.

#### Extending the Plugin

To add new functionalities to the plugin, you can follow [this article](https://isaratech.com/ue4-making-a-android-plugin-in-10-minutes/).