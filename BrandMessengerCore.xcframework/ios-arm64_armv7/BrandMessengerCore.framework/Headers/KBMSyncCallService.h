//
//  KBMSyncCallService.h
//  BrandMessengerCore
//
//  Created by Sunil on 12/14/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMMessage.h"
#import "KBMRealTimeUpdate.h"
#import "KBMUserDetail.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMSyncCallService : NSObject

- (void)updateMessageDeliveryReport:(NSString *)messageKey withStatus:(int)status withTimestamp:(NSNumber* _Nullable )timestamp;

- (void)updateDeliveryStatusForContact:(NSString *)contactId withStatus:(int)status withTimestamp:(NSNumber* _Nullable )timestamp;

- (void)updateConnectedStatus:(KBMUserDetail *)userDetail;

- (void)updateTableAtConversationDeleteForContact:(NSString * _Nullable)contactID
                                   ConversationID:(NSString * _Nullable)conversationID
                                       ChannelKey:(NSNumber * _Nullable)channelKey;
- (void)syncMessageMetadata;

@end

NS_ASSUME_NONNULL_END
