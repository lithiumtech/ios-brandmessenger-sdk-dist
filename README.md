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