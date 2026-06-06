# [Khoros BrandMessenger](https://www.khoros.com)


[![Platform](https://img.shields.io/badge/Platform-iOS-8e8e8e)](https://github.com/lithiumtech/ios-brandmessenger-sdk-dist)
[![Privacy](https://img.shields.io/badge/Privacy-Website-8e8e8e)](https://www.khoros.com/privacy)

Khoros BrandMessenger iOS SDK


Add BrandMessenger to podfile:

    pod 'BrandMessenger', '<version>'

Import BrandMessenger:

```Swift
    import BrandMessengerUI
    import BrandMessengerCore
```

Use:

```Swift
BrandMessengerManager(companyKey: "YOUR_COMPANY_KEY", applicationKey: "YOUR_APPLICATION_ID", widgetId: "YOUR_WIDGET_ID") { response, error in }
BrandMessengerManager.login("YOUR_ACCESS_TOKEN") { response, error in }
BrandMessengerManager.show()
```

## Supported Xcode / Swift toolchain

These frameworks are distributed as **pre-compiled binary Swift `.xcframework`s**.
A binary Swift framework is coupled to the Swift toolchain that produced it.
The frameworks enable module stability (library evolution) and ship a textual
`.swiftinterface`, but the practical compatibility window does **not** span large
Xcode/Swift jumps. Building the SDK with an Xcode whose Swift compiler differs
significantly from the one the framework was built with fails at compile time
with:

```
failed to build module 'BrandMessengerUI'; this SDK is not supported by the compiler
(the SDK is built with 'Apple Swift version X', while this compiler is 'Apple Swift version Y').
Please select a toolchain which matches the SDK.
```

To avoid this, use a release built with the same Xcode major line you build your
app with. Each release records its producing toolchain in `BUILD_TOOLCHAIN.txt`.

| SDK version | Built with (Xcode / Swift) | Notes |
|-------------|----------------------------|-------|
| `1.16.11` (latest stable) | Xcode 16.4 / Swift 6.1.2 | Use with Xcode 16.x. Does **not** import under Xcode 26.x (Swift 6.3.x). |
| `2.0.3` | Xcode 26.2 / Swift 6.2.3 | Built with Swift 6.2.3 (earlier notes saying "Xcode 16.0" were inaccurate). |
| `1.16.8`, `1.16.10` | Xcode 26.2 / Swift 6.2.3 | Superseded — caused build failures on Xcode 16.x; replaced by `1.16.11`. |
| `≤ 1.16.4` | Xcode 16.0 or earlier | Legacy. |

> **Xcode 26.5 / Swift 6.3.2:** no published release is built on this toolchain
> yet. A build is required for apps on the latest Xcode — tracked in
> eng-maintenance#20609. Until then, build your app with the Xcode line that
> matches the release above.
