//
//  KBMConversationDBService.h
//  BrandMessengerCore
//
//  Created by Devashish on 27/02/16.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMConversationProxy.h"
#import "DB_ConversationProxy.h"
#import <Foundation/Foundation.h>

@interface KBMConversationDBService : NSObject

- (void)insertConversationProxy:(NSMutableArray *)proxyArray;

- (DB_ConversationProxy *)createConversationProxy:(KBMConversationProxy *)conversationProxy;

- (DB_ConversationProxy *)getConversationProxyByKey:(NSNumber *)Id;

- (NSArray*)getConversationProxyListFromDBForUserID:(NSString *)userId;
- (NSArray*)getConversationProxyListFromDBWithChannelKey:(NSNumber *)channelKey;

- (void)insertConversationProxyTopicDetails:(NSMutableArray *)proxyArray;

- (NSArray*)getConversationProxyListFromDBForUserID:(NSString *)userId andTopicId:(NSString *)topicId;

@end
