//
//  KBMAppLocalNotifications.h
//  BrandMessengerCore
//
//  Created by devashish on 07/01/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMMessageService.h"
#import "KBMReachability.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const KBMConversationLoadDidFinishNotification;

@interface KBMAppLocalNotifications : NSObject

@property(strong) KBMReachability * _Nullable googleReach;
@property(strong) KBMReachability * _Nullable localWiFiReach;
@property(strong) KBMReachability * _Nullable internetConnectionReach;
@property (nonatomic) BOOL flag;

+ (KBMAppLocalNotifications *)appLocalNotificationHandler;
- (void)dataConnectionNotificationHandler;
- (void)reachabilityChanged:(NSNotification *)note;
- (void)proactivelyConnectMQTT;
- (void)proactivelyDisconnectMQTT;

@end
NS_ASSUME_NONNULL_END
