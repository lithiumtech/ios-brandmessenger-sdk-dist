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

## Build toolchain & Xcode compatibility

These are **pre-compiled binary Swift `.xcframework`s** built with module stability
(`BUILD_LIBRARY_FOR_DISTRIBUTION=YES`); each ships a textual `.swiftinterface`
(no binary `.swiftmodule`). Swift module stability is **asymmetric**:

- ✅ **Newer Xcode consuming an older-built framework works.** A newer Swift
  compiler rebuilds the framework's `.swiftinterface`. Verified: `1.16.11`
  (built with Swift 6.1.2) imports and builds successfully under **Xcode 26.5 /
  Swift 6.3.2** (eng-maintenance#20609).
- ⚠️ **Older Xcode consuming a newer-built framework fails.** An older compiler
  cannot consume an interface produced by a newer one, surfacing as
  `this SDK is not supported by the compiler`. This is why `1.16.8` / `1.16.10`
  (built with Swift 6.2.3) failed on Xcode 16.x and were replaced by `1.16.11`.

Each release records its producing toolchain in `BUILD_TOOLCHAIN.txt`.

| SDK version | Built with (Xcode / Swift) | Notes |
|-------------|----------------------------|-------|
| `1.16.11` (latest stable) | Xcode 16.4 / Swift 6.1.2 | Verified to build under Xcode 16.x **and** Xcode 26.5 / Swift 6.3.2. |
| `2.0.3` | Xcode 26.2 / Swift 6.2.3 | Built with Swift 6.2.3 (earlier "Xcode 16.0" note was inaccurate). Requires Xcode 26.x. |
| `1.16.8`, `1.16.10` | Xcode 26.2 / Swift 6.2.3 | Superseded — failed on Xcode 16.x; replaced by `1.16.11`. |
| `≤ 1.16.4` | Xcode 16.0 or earlier | Legacy. |

> **If a build fails with `this SDK is not supported by the compiler`** on a
> **newer** Xcode than the framework was built with, the framework binary itself
> is not the cause (the forward direction is verified to work). Check for a stale
> `DerivedData` / module cache, a non-standard packaging step (e.g. a private SPM
> wrapper that re-zips the frameworks), or a mismatched toolchain selection, and
> retry on the supported CocoaPods integration. Official SPM support is tracked
> separately under KHOROSPEF-1380.
