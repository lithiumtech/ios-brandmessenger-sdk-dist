Created by Unknown User (pkwak), last modified by Unknown User (sunil.k) on Jan 22, 2024
(Instructions from 2024, Jan 22)

Prerequisites

Install the following:

Install Xcode Xcode you can download Xcode from https://developer.apple.com/download/all/?q=xcode need to log in to Apple Developer with an account for downloading or on Your laptop search for the self-service app and search for Xcode 
install CocoaPods from here https://cocoapods.org/ 
Checkout code
Check out the Ecohaus demo app, anywhere that makes sense.

https://github.com/lithiumtech/lithium-ios-sdk-demo and checkout branch PK-WIP

First, checkout all these repositories under the lithium-ios-sdk-demo directory. Lets name this directory "New Brand Messenger iOS". You'll also add a buildscript and some podspec files to make development easier.

https://github.com/lithiumtech/ios-brandmessenger-core (Required)
Source code for the core functionality of BrandMessenger. Use 'khoros-master' as our main branch. 'main' is reserved for Applozic to push updates to.
https://github.com/lithiumtech/ios-brandmessenger-ui (Required)
Source code for the default UI classes, built using Core. Includes RichMessageKit. Use 'khoros-master' as our main branch. 'main' is reserved for Applozic to push updates to.
https://github.com/onevcat/Kingfisher (Optional)
3rd party code. Not necessary but our build steps including rebuilding this.
https://github.com/isaced/ISEmojiView (Optional)
3rd party code. Not necessary but our build steps including rebuilding this.
https://github.com/lithiumtech/ios-brandmessenger-demo (Optional)
Demo app using the above. Not necessary since we're using our own demo app.
https://github.com/lithiumtech/ios-brandmessenger-sdk-dist (Required)
The repository where the built xcframeworks go, and where customers podfile point to.
With the other files added, the folder should look like:



Adding SDK from github repository (as customers would)
In the Ecohaus app's Podfile, the following grabs the framework from released distribution.

pod 'BrandMessenger', :git => 'git@github.com:lithiumtech/ios-brandmessenger-sdk-dist.git', :tag => '0.1.3'

Adding SDK from local dist repository
The following will add the frameworks from local ios-brandmessenger-sdk-dist folder that was checked out earlier. It looks for 'BrandMessenger.podspec' file in the directory.

pod 'BrandMessenger', :path => '../../New Brand Messenger iOS/ios-brandmessenger-sdk-dist'

Adding SDK as sourcecode for development.
The following code, along with the attached .podspec files will add BrandMessengerUI, BrandMessengerCore, and RickMessageKit as source-code development pods to Ecohaus

  pod 'BrandMessenger', :path => '../New Brand Messenger iOS'

  pod 'BrandMessengerCore', :path => '../New Brand Messenger iOS'

  pod 'RichMessageKit', :path => '../New Brand Messenger iOS'

  pod 'BrandMessengerUI', :path => '../New Brand Messenger iOS'

BrandMessenger.podspec removes BrandMessengerUI, BrandMessengerCore and RichMessageKit so they can be added separately.

BrandMessengerCore.podspec, BrandMessengerUI.podspec and RichMessageKit.podspec include their respective source files and resources. Have a look through them and compare with BrandMessenger.podspec to see what's different.

This way, you can make changes to BrandMessengerCore, BrandMessengerUI and RichMessageKit during development, without needing to build them to xcframework after each change.

BrandMessenger.podspec
BrandMessengerCore.podspec
BrandMessengerUI.podspec
RichMessageKit.podspec


Add these to New Brand Messenger iOS folder as show in directory example image above.

Next Go to lithium-ios-sdk-demo/Ecohaus in terminal and do 

pod install

To run Open lithium-ios-sdk-demo/Ecohaus/Ecohaus.xcworkspace.

Comment this line if you get an error while running the demo app

 //defaultHeaders["User-Agent"] = userAgent()


Building xcframework for SDK release only:
The following is the buildxcframework.sh script OR build script can be found https://github.com/lithiumtech/ios-brandmessenger-ui/blob/khoros-main/buildxcframework.sh as well download. Add it to New Brand Messenger iOS folder as well.

buildxcframework.sh



It goes into each source project, builds the xcframework, then copies them to both the ios-brandmessenger-ui/Frameworks/ directory and ios-brandmessenger-sdk-dist/ directory. It has SwipeCellKit and Kingfisher commented out as we don't expect those to change, but you can uncomment them if you need.

The script also leave behind directories like archives-BrandMessengerUI. Update the script to remove them afterwards if you want.

Modify the script as needed to fit your development needs, as it will be different for each developer.

Releasing Updates
After the xcframework files are updated in ios-brandmessenger-sdk-dist directory, do the following:

Update ios-brandmessenger-sdk-dist/BrandMessenger.podspec with new version number.
Update ios-brandmessenger-sdk-dist/README.md with new version number in shield.io badge and code reference.
Commit, tag, push.
Update Ecohaus podfile to get from github repository with new version number and test.
Now the update release should be available for customers as well.

