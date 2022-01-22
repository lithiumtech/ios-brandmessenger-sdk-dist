//
//  KBMConversationClientService.h
//  BrandMessengerCore
//
//  Created by Divjyot Singh on 04/03/16.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMConstant.h"
#import "KBMConversationCreateResponse.h"
#import "KBMConversationProxy.h"
#import "KBMResponseHandler.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMConversationClientService` is used for conversation client methods like create, fetch conversation.
@interface KBMConversationClientService : NSObject

/// Instance method of `KBMResponseHandler` object.
@property (nonatomic, strong) KBMResponseHandler *responseHandler;

/// This method is used for creating a context based chat conversation on server.
/// @param conversationProxy Pass the `KBMConversationProxy` object.
/// @param completion If any error then NSError will not be nil and In `KBMConversationCreateResponse` if status is sucess is then conversation is created successfully otherwise there wil be error in status.
- (void)createConversation:(KBMConversationProxy *)conversationProxy
            withCompletion:(void(^)(NSError * _Nullable error, KBMConversationCreateResponse * _Nullable response))completion;

/// This method is used for fetching topic details from server.
/// @param conversationProxyID Pass the conversationId.
/// @param completion If any error then NSError will not be nil and In `KBMConversationCreateResponse` if status is sucess is then conversation is created successfully otherwise there wil be error in status.
- (void)fetchTopicDetails:(NSNumber *)conversationProxyID andCompletion:(void (^)(NSError * _Nullable error , KBMAPIResponse * _Nullable response))completion;
@end

NS_ASSUME_NONNULL_END
