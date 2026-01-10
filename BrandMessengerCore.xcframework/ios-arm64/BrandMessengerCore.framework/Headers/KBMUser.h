//
//  KBMUser.h
//  BrandMessengerCore
//
//  Created by devashish on 18/09/2015.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Used to tell the backend what kind of authentication the user wishes to use to be authenticated. See the types for details.
typedef enum
{
    /// Tells Messenger server that you will handle authentication yourself using `password`.
    CLIENT = 0,
    /// Tells Messenger server to handle the authentication itself. Use this if you do not know what you should be using.
    BRAND_MESSENGER = 1,
} AuthenticationType;

/// `KBMUser` is an authenticated entity that can use chat functionality.
///
/// A user is identified by its `userId` which is unique for an `applicationId`.
///
/// When creating an user you need to set the fields `userId`, `authenticationTypeId`
/// user is can register or login using `-[KBMRegisterUserClientService initWithCompletion:withCompletion:]` or `-[BrandMessengerClient loginUser:withCompletion:]` method.
///
/// - SeeAlso : `KBMContact`
@interface KBMUser : KBMJson

/// An unique userId to login to Messenger server.
/// @note +,*,? are not allowed chars in userId.
@property (nonatomic, strong) NSString *userId;

/// :nodoc:
@property (nonatomic, strong) NSString * _Nullable email;

/// :nodoc:
@property (nonatomic, strong) NSString * _Nullable password;

/// Sets the user name.
@property (nonatomic, strong) NSString * _Nullable displayName;

/// An APN's or VOIP device token.
@property (nonatomic, strong) NSString * _Nullable registrationId;

/// Messenger APP-ID you can get it from console.
@property (nonatomic, strong) NSString * _Nullable applicationId;

/// User contact number.
@property (nonatomic, strong) NSString * _Nullable contactNumber;

/// Sets the code of the country in which the user resides.
@property (nonatomic, strong) NSString * _Nullable countryCode;

/// Sets the email verified for this user.
@property (nonatomic) Boolean emailVerified;

/// :nodoc:
@property (nonatomic, strong) NSString * _Nullable timezone;

/// For internal use only.
@property (nonatomic) short appVersionCode;

/// Roles give your user certain privileges.
@property (nonatomic, strong) NSString * _Nullable roleName;

/// Sets the device type for identifying on the Messenger server.
///
/// The types of devices and their values are:
/// WEB = 0,
/// ANDROID = 1,
/// IOS = 4
@property (nonatomic) short deviceType;

/// User profile image URL.
@property (nonatomic, strong) NSString * _Nullable imageLink;

/// App module name is used when two different apps are communicating with different app modules and the same APP-ID.
///
/// Use this settings `[KBMUserDefaultsHandler setAppModuleName:@"NAME-OF-MODULE-HERE"];` to pass the module name`.
@property (nonatomic, strong) NSString * _Nullable appModuleName;

/// Internally sets the notification mode.
///
/// Use the method `[KBMUserDefaultsHandler setNotificationMode:BELOW-TyPE];` to set the notification mode :
/// KBM_NOTIFICATION_ENABLE = 0,
/// KBM_NOTIFICATION_DISABLE_SOUND = 1,
/// KBM_NOTIFICATION_DISABLE = 2
@property (nonatomic) short notificationMode;

/// Used to tell the backend what kind of authentication the user wishes to use to be authenticated see the `AuthenticationType`.
@property (nonatomic) short authenticationTypeId;

/// App unread badge count.
///
/// Types: 0: For disable badge count, 1: For enable badge count.
@property (nonatomic) short unreadCountType;

/// For identifying the current user login from Debug or Release mode for sending APNs notification based on this.
/// @note This is set internally not required to set.
@property short deviceApnsType;

/// Enables the message encryption user.
@property (nonatomic) BOOL enableEncryption;

/// :nodoc:
@property (nonatomic) short pushNotificationFormat;

/// Sets the added features that Messenger provides.
///
/// Features are functionalities that are advanced enough to require added set up for them to work.
/// In the case of "100" audio calls and "101" video calls you will need to use `AudioVideo` Call SDK that works with the Chat SDK.
@property (nonatomic, strong) NSMutableArray * _Nullable features;

/// APN's message notification sound name.
@property (nonatomic, strong) NSString * _Nullable notificationSoundFileName;

/// Extra information can be stored in the user.
///
/// Example: Use the below code to set the metadata
///
/// @code
///
/// // User metadata dictionary
/// NSMutableDictionary *userMetaData = [[NSMutableDictionary alloc] init];
/// [userMetaData setValue:@"Software engineer" forKey:@"designation"];
/// [userMetaData setValue:@"Bengaluru" forKey:@"city"];
/// [userMetaData setValue:@"India" forKey:@"country"];
///
/// // Set the metadata in `KBMUser` object
/// [user setMetadata:userMetaData];
///
/// @endcode
@property (nonatomic, strong) NSMutableDictionary * _Nullable metadata;

/// Get an `KBMUser` object with given userId, password, email and display name of user.
/// @param userId An unique userId to login to Messenger server.
/// @param password User password/access token.
/// @param email Email id of the user.
/// @param displayName Name of the user to show in chat conversation.
- (instancetype)initWithUserId:(NSString *)userId
                      password:(NSString * _Nullable)password
                         email:(NSString * _Nullable)email
                andDisplayName:(NSString * _Nullable)displayName;

/// Validates the user data
-(void)softValidateUser;
@end

NS_ASSUME_NONNULL_END
