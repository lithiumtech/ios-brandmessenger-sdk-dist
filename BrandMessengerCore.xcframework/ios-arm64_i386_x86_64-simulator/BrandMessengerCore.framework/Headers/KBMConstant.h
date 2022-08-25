//
//  KBMConstant.h
//  BrandMessengerCore
//
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "KBMUserDefaultsHandler.h"

#define KBASE_URL ([KBMUserDefaultsHandler getBASEURL])
#define MQTT_URL ([KBMUserDefaultsHandler getMQTTURL])
#define KBASE_FILE_URL ([KBMUserDefaultsHandler getFILEURL])
#define MQTT_PORT ([KBMUserDefaultsHandler getMQTTPort])
#define MQTT_IS_TLS ([KBMUserDefaultsHandler isMQTTTLS])

NS_ASSUME_NONNULL_BEGIN

static NSString *const KBM_IMAGE_UPLOAD_URL = @"/rest/ws/upload/file";
static NSString *const KBM_IMAGE_UPLOAD_ENDPOINT = @"/files/upload/";
static NSString *const KBM_CUSTOM_STORAGE_IMAGE_UPLOAD_ENDPOINT = @"/rest/ws/upload/image?aclsPrivate=true";
static NSString *const KBM_GOOGLE_CLOUD_STORAGE_IMAGE_UPLOAD_ENDPOINT = @"/rest/ws/upload/image";
static NSString *const KBM_IMAGE_THUMBNAIL_ENDPOIT = @"/files/";
static NSString *const KBM_IMAGE_DOWNLOAD_ENDPOINT = @"/files/get/";
static NSString *const KBM_EMPTY_JSON_STRING = @"\"EMPTY_LIST\"";

/// Source type used in `KBMMessage`.
static int const KBM_SOURCE_IOS = 3;

/// Message status types for identifying the messgae is delivered, read and delivered, sent.
/// It has outbox type status for sent message and inbox type status for received message.
typedef enum {
    /// OUTBOX types
    /// Sent message type
    SENT = 3,
    /// Message which is sent in chat has been delivered.
    DELIVERED = 4,
    /// Message which is sent in chat has been delivered and read.
    DELIVERED_AND_READ = 5,

    /// INBOX types
    /// :nodoc:
    PENDING = 2,
    /// :nodoc:
    UNREAD = 0,
    /// :nodoc:
    READ = 1
} MessageStatus;

/// User type for internal use for identifying the type of user is login.
typedef enum {
    /// Bot type user.
    KBM_BOT  = 1,
    /// Main Admin of the application.
    KBM_APPLICATION_ADMIN =   2,
    /// Chat user in app.
    KBM_USER_ROLE  =  3,
    /// Admin of application AppId.
    KBM_ADMIN_ROLE  = 4,
    /// Business user of application.
    KBM_BUSINESS =  5,
    /// Business user of application.
    KBM_APPLICATION_BROADCASTER =  6,
    /// Support user of application.
    KBM_SUPPORT  = 7,
    /// Dashboard admin of application.
    KBM_APPLICATION_WEB_ADMIN =8
} KBMUSER_ROLE_TYPE;

/// App state flags for identifying the notification is from background, active or inactive state.
typedef enum {
    /// App state is background.
    APP_STATE_BACKGROUND = -1,
    /// App state is inactive.
    APP_STATE_INACTIVE   = 0,
    /// App state is active.
    APP_STATE_ACTIVE     = 1
} APP_TRI_STATE;

/// User notification type is used for identifying the logged-in user notification is disabled, enabled, disable sound, enable the sound in APNs notification.
typedef enum {
    /// Enables the APN's notification sound.
    KBM_NOTIFICATION_ENABLE_SOUND = 0,
    /// Disable the APN's notification sound.
    KBM_NOTIFICATION_DISABLE_SOUND = 1,
    /// Enable the notifications.
    KBM_NOTIFICATION_ENABLE = 0,
    /// Dsiable the notifications.
    KBM_NOTIFICATION_DISABLE = 2
} KBM_NOTIFICATION_TYPE_MODE;

/// Pricing package type for identifying the App-ID is in which pricing package it is using currently.
typedef enum {
    /// APP-ID is closed then the Pricing will be -1.
    KBM_CLOSED = -1,
    /// APP-ID is beta then the Pricing will be 0.
    KBM_BETA = 0,
    /// APP-ID is starter plan then the Pricing will be 1.
    KBM_STARTER = 1,
    /// APP-ID is launch plan then the Pricing will be 2.
    KBM_LAUNCH = 2,
    /// APP-ID is growth plan then the Pricing will be 3.
    KBM_GROWTH = 3,
    /// APP-ID is enterprise plan then the Pricing will be 4.
    KBM_ENTERPRISE = 4,
    /// APP-ID is suspended plan then the Pricing will be 6.
    KBM_SUSPENDED = 6
} KBM_PRICING_PACKAGE;

/// This call content type are for identifying call message notification is hidden or will show in chat.
/// 102 (Notification Only).
/// 103 (Show Message Content in chat).
typedef enum {
    /// Call notification where message is hidden in chat.
    AV_CALL_HIDDEN_NOTIFICATION = 102,
    /// Call message which will be disaplyed in chat.
    AV_CALL_MESSAGE = 103
} CALL_CONTENT_TYPE;

typedef enum {
    /// Tells that to use default message content text in notification.
    KBM_DEFAULT_NOTIFICATION = 0,
    /// Tells that to use generic content text in notification.
    KBM_GENERIC_NOTIFICATION = 1
} KBM_DEVICE_NOTIFICATION_MESSAGE_TYPE;

NS_ASSUME_NONNULL_END
