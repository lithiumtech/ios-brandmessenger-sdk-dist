//
//  KBMConversationService.h
//  BrandMessengerCore
//
//  Created by Devashish on 27/02/16.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMConversationClientService.h"
#import "KBMConversationDBService.h"
#import "KBMConversationProxy.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMConversationService : NSObject

@property (nonatomic, strong) KBMConversationClientService *conversationClientService;

@property (nonatomic, strong) KBMConversationDBService *conversationDBService;

- (KBMConversationProxy * _Nullable)getConversationByKey:(NSNumber *)conversationKey;

- (void)addConversations:(NSMutableArray *)conversations;

- (KBMConversationProxy * _Nullable)convertAlConversationProxy:(DB_ConversationProxy *)dbConversation;

- (NSMutableArray * _Nullable)getConversationProxyListForUserID:(NSString *)userId;

- (NSMutableArray * _Nullable)getConversationProxyListForChannelKey:(NSNumber *)channelKey;

- (void)createConversation:(KBMConversationProxy *)conversationProxy
            withCompletion:(void(^)(NSError * _Nullable error, KBMConversationProxy * _Nullable conversationProxy))completion;

- (void)fetchTopicDetails:(NSNumber *)conversationProxyID withCompletion:(void(^)(NSError * _Nullable error, KBMConversationProxy * _Nullable conversationProxy))completion;

@end
NS_ASSUME_NONNULL_END
