Pod::Spec.new do |s|
  s.name         = "BrandMessenger"
  s.version      = "1.14.3"
  s.summary      = "BrandMessenger"
  s.description  = "Messaging and Chat API for Mobile Apps and Websites"
  s.homepage     = "https://khoros.com"
  s.license      = "Commercial"
  s.authors = { 'Khoros, LLC.' => 'support@khoros.com' }
  s.source       = { :git => "https://github.com/lithiumtech/ios-brandmessenger-sdk-dist.git", :tag => "#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, "12.0"
  s.ios.vendored_frameworks = 'BrandMessengerUI.xcframework', 'BrandMessengerCore.xcframework','RichMessageKit.xcframework', 'Kingfisher.xcframework', 'ISEmojiView.xcframework'
  s.ios.frameworks = ["UIKit", "Security", "Foundation", "Network", "MobileCoreServices", "SystemConfiguration", "CoreFoundation"]
end
