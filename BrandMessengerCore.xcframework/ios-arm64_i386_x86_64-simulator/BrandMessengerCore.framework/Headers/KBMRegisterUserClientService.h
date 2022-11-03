//
//  KBMRegisterUserClientService.h
//  BrandMessengerCore
//
//  Created by devashish on 18/09/2015.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//
#import "KBMAPIResponse.h"
#import "KBMConstant.h"
#import <Foundation/Foundation.h>
#import "KBMRegistrationResponse.h"
#import "KBMResponseHandler.h"
#import "KBMUser.h"

NS_ASSUME_NONNULL_BEGIN

/// `KBMRegisterUserClientService` used for registration and authentication of the user.
///
/// Basic methods it has :
///
/// * APN's or VOIP device token update to Messenger server,
/// * Update notification modes.
/// * Sync account status of Application.
/// * Logout user.
@interface KBMRegisterUserClientService : NSObject

/// `KBMResponseHandler` instance method is used for actual request call to API's. Default instance is created from `init` method of `KBMRegisterUserClientService`.
@property (nonatomic, strong) KBMResponseHandler *responseHandler;

/// Use this method to log in or register your `KBMUser`. This must be done before any other method of the SDK is used.
///
/// @param user An `KBMUser` object details for identifying the user on the server.
/// @param completion An KBMAPIResponse will have status `KBM_RESPONSE_SUCCESS` for successful otherwise an error describing the login failure
- (void)initWithCompletion:(KBMUser *)user withCompletion:(void(^)(KBMRegistrationResponse * _Nullable message, NSError * _Nullable error)) completion;

/// Updates an APNs device token to Messenger server for real-time updates on messages and other events to the device.
///
/// APN's device token which is generated from `didRegisterForRemoteNotificationsWithDeviceToken` method of `UIApplicationDelegate` in your AppDelegate file.
/// @param apnDeviceToken APN's device token is used for sending an APNs push notifications to iPhone device.
/// @param completion An `KBMAPIResponse` will have status `KBM_RESPONSE_SUCCESS` for successful otherwise an error describing the logout failure.
- (void)updateApnDeviceTokenWithCompletion:(NSString *)apnDeviceToken
                            withCompletion:(void(^)(KBMRegistrationResponse * _Nullable message, NSError * _Nullable error)) completion;

/// Updates notification modes the logged-in user can enable, disable sound, disable the notifications.
///
/// @param notificationMode An notification mode to update to Messenger server.
///
/// The list of notification modes are:
/// - KBM_NOTIFICATION_ENABLE_SOUND = 0, // Enables the notification sound.
/// - KBM_NOTIFICATION_DISABLE_SOUND = 1, // Disable the sound of APNs notifiaction.
/// - KBM_NOTIFICATION_ENABLE = 0, // Enables the notification.
/// - KBM_NOTIFICATION_DISABLE = 2 // Disables the notifications.
/// @param completion An `KBMAPIResponse` will have status `KBM_RESPONSE_SUCCESS` for successful otherwise an error describing the update notification failure.
+ (void)updateNotificationMode:(short)notificationMode
                withCompletion:(void(^)(KBMRegistrationResponse * _Nullable response, NSError * _Nullable error)) completion;

/// Logouts the user from Messenger server.
/// @param completion An `KBMAPIResponse` will have status `KBM_RESPONSE_SUCCESS` for successful otherwise an error describing the logout failure.
/// @note Logout user will clear locally stored data of Messenger logged-in user.
/// @warning Mostly  logout method `-[KBMRegisterUserClientService logoutWithCompletionHandler:]` needs to be called on your App logout success.
- (void)logoutWithCompletionHandler:(void(^)(KBMAPIResponse * _Nullable response, NSError * _Nullable error))completion;

/// Used for updating current Messenger App version code to apploizc server.
+ (BOOL)isAppUpdated;

/// Syncs the account pricing status of Application.
/// @param completion An `KBMRegistrationResponse` describing a successful account status synced or An error describing the sync account failure.
- (void)syncAccountStatusWithCompletion:(void(^)(KBMRegistrationResponse * _Nullable response, NSError * _Nullable error)) completion;

/// Used for updating logged-in user details to Messenger server.
///
/// @warning Instead use  `-[BrandMessengerClient updateUserDisplayName:andUserImage:userStatus:withCompletion:];` method to update.
/// @param updatedUser An `KBMUser` object.
/// @param completion An `KBMAPIResponse` will have status `KBM_RESPONSE_SUCCESS` for successful otherwise an error describing the update user failure.
- (void)updateUser:(KBMUser *)updatedUser withCompletion:(void(^)(KBMRegistrationResponse * _Nullable response, NSError * _Nullable error)) completion;

/// Update's APNs and VOIP token to Messenger server.
///
/// @param apnsOrVoipDeviceToken Pass APNs or VOIP token.
/// @param isAPNsToken Pass YES in case of APNs token, NO in case of VOIP token.
/// @param completion An `KBMAPIResponse` will have status `KBM_RESPONSE_SUCCESS` for successful otherwise an error describing the update APNs or VOIP device token failure.
/// @note The method  `-[KBMRegisterUserClientService updateAPNsOrVOIPDeviceToken:withApnTokenFlag:withCompletion:]` needs to used only in `AudioVideo` SDK for updating VOIP or APN;s device token to Messenger server.
- (void)updateAPNsOrVOIPDeviceToken:(NSString *)apnsOrVoipDeviceToken
                   withApnTokenFlag:(BOOL)isAPNsToken
                     withCompletion:(void(^)(KBMRegistrationResponse * _Nullable response, NSError * _Nullable error)) completion;

/// Accessing currently stored (APN's) or (VOIP) device token.
- (NSString *)getRegistrationId;
@end

NS_ASSUME_NONNULL_END
