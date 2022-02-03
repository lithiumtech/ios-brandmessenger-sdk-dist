# [Khoros BrandMessenger](https://www.khoros.com)


[![Pod Version](https://img.shields.io/badge/Version-0.1.3-8e8e8e)](https://github.com/lithiumtech/ios-brandmessenger-sdk-dist)
[![Platform](https://img.shields.io/badge/Platform-iOS-8e8e8e)](https://github.com/lithiumtech/ios-brandmessenger-sdk-dist)
[![Privacy](https://img.shields.io/badge/Privacy-Website-8e8e8e)](https://www.khoros.com/privacy)

Khoros BrandMessenger iOS SDK


Add BrandMessenger to podfile:

    pod 'BrandMessenger', :git => 'git@github.com:lithiumtech/ios-brandmessenger-sdk-dist.git', :tag => '0.1.3'

Import BrandMessenger:

```Swift
    import BrandMessengerUI
    import BrandMessengerCore
```

Use:

```Swift
BrandMessengerManager(companyKey: "YOUR_COMPANY_KEY", applicationKey: "YOUR_APPLICATION_ID")
BrandMessengerManager.login("YOUR_ACCESS_TOKEN") { response, error in }
BrandMessengerManager.show()
```