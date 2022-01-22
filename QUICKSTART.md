# Quickstart Guide
In the BrandMessengerUI framework, there is a BrandMessengerManager class that encapsulates certain complexities to make integrating the SDK much more simple.

## Basics
### Initialization
Initialize BrandMessengerManager class providing the companyKey and applicationKey, preferably somewhere in application:didFinishLaunchingWithOptions

    BrandMessengerManager(companyKey: "company key", applicationKey: "application id")

### Authentication (Incomplete feature)
Login by providing the bearerToken.
**Current version does not integrate custom auth yet. Pass in username instead.**

    BrandMessengerManager.login("accessToken") { response, error in
    }

Logout 

    BrandMessengerManager.logoutUser { success in
    }

### Conversation
To start conversation with agent.

    BrandMessengerManager.show(viewController)
or

    BrandMessengerManager.show()
If `viewController` is provide, SDK will present conversation screen from `viewController`. Otherwise, SDK will try to find keyWindow's rootViewController's topViewController and present from there.


## AppDelegate
*In comparison to the older SDK, the new SDK no-longer swizzles AppDelegate methods, hence some additions need to be put into the AppDelegate class.*

didFinishLaunchingWithOptions

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
	...
	// This will handle requesting for push-notification registeration, and opening app from push-notification
		BrandMessengerManager.application(application, didFinishLaunchingWithOptions: launchOptions)
	...
    }
applicationWillEnterForeground

    func applicationWillEnterForeground(_ application: UIApplication) {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    	BrandMessengerManager.applicationWillEnterForeground(application)
    }
applicationWillTerminate

    func applicationWillTerminate(_ application: UIApplication) {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    	BrandMessengerManager.applicationWillTerminate(application)
    }
application didRegisterForRemoteNotificationsWithDeviceToken

    func application(_ application: UIApplication,
                 didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
    	BrandMessengerManager.application(application, didRegisterForRemoteNotificationsWithDeviceToken: deviceToken)
    }
application didReceiveRemoteNotification

    func application(_ application: UIApplication,
                              didReceiveRemoteNotification userInfo: [AnyHashable : Any],
                              fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
    	BrandMessengerManager.application(application, didReceiveRemoteNotification: userInfo, fetchCompletionHandler: completionHandler)
    }

In UNUserNotificationCenterDelegate:

    // iOS10+, called when presenting notification in foreground
    func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping () -> Void) {
    completionHandler()
    // Handle foreground notification
    	BrandMessengerManager.userNotificationCenter(center, willPresent: notification) { options in
        }
    }

    // iOS10+, called when received response (default open, dismiss or custom action) for a notification
    func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
    completionHandler([.alert])
    //TODO: Handle background notification
	    BrandMessengerManager.userNotificationCenter(center, didReceive: response) {

    	}
    }