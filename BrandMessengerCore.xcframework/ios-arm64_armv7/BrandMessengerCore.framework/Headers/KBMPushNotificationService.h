//
//  KBMPushNotificationService.h
//  BrandMessengerCore
//
//  Created by devashish on 28/09/2015.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "KBMMessage.h"
#import "KBMMQTTConversationService.h"
#import "KBMRealTimeUpdate.h"
#import "KBMSyncCallService.h"
#import "KBMUserDetail.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// NEW CODES FOR VERSION CODE 105...
typedef enum
{
    KBM_SYNC = 0,
    KBM_DELIVERED,
    KBM_DELETE_MESSAGE,
    KBM_CONVERSATION_DELETED,
    KBM_MESSAGE_READ,
    KBM_MESSAGE_DELIVERED_AND_READ,
    KBM_CONVERSATION_READ,
    KBM_CONVERSATION_DELIVERED_AND_READ,
    KBM_USER_CONNECTED,
    KBM_USER_DISCONNECTED,
    KBM_MESSAGE_SENT,
    KBM_USER_BLOCK,
    KBM_USER_UNBLOCK,
    KBM_TEST_NOTIFICATION,
    KBM_MTEXTER_USER,
    KBM_CONTACT_VERIFIED,
    KBM_DEVICE_CONTACT_SYNC,
    KBM_MT_EMAIL_VERIFIED,
    KBM_DEVICE_CONTACT_MESSAGE,
    KBM_CANCEL_CALL,
    KBM_MESSAGE,
    KBM_DELETE_MULTIPLE_MESSAGE,
    KBM_SYNC_PENDING,
    KBM_GROUP_CONVERSATION_READ,
    KBM_USER_MUTE_NOTIFICATION,
    KBM_USER_DETAIL_CHANGED,
    KBM_USER_DELETE_NOTIFICATION,
    KBM_GROUP_CONVERSATION_DELETED,
    KBM_CONVERSATION_DELETED_NEW,
    KBM_MESSAGE_METADATA_UPDATE,
    KBM_NOTFICATION_COUNT,
    KBM_GROUP_MUTE_NOTIFICATION,
    KBM_USER_ACTIVATED,
    KBM_USER_DEACTIVATED
} KBM_PUSH_NOTIFICATION_TYPE;

/// Khoros notifications key name.
static NSString *const BRAND_MESSANGER_PREFIX = @"BRANDMESSENGER_";

@interface KBMPushNotificationService : NSObject

@property (nonatomic, weak) id<KBMUpdatesDelegate> _Nullable realTimeUpdate;
@property(nonatomic,strong) KBMSyncCallService *syncCallService;

- (BOOL)isBrandMessengerChatNotification:(NSDictionary *)dictionary;
- (BOOL)processPushNotification:(NSDictionary *)dictionary updateUI:(NSNumber *)updateUI;
- (void)notificationArrivedToApplication:(UIApplication *)application withDictionary:(NSDictionary *)userInfo;
+ (void)applicationEntersForeground;
+ (void)userSync;
- (BOOL)checkForLaunchNotification:(NSDictionary *)dictionary;
- (void)clearDeliveredNotificationsFromNotificationCenter;
- (NSDictionary * _Nullable)notificationTypes;
@end

NS_ASSUME_NONNULL_END
