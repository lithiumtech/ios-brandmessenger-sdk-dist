//
//  KBMConversationProxy.h
//  BrandMessengerCore
//
//  Created by devashish on 07/01/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"
#import "KBMTopicDetail.h"
#import "DB_ConversationProxy.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// `KBMConversationProxy` class is used parsing JSON response of context based chat.
@interface KBMConversationProxy : KBMJson

/// Sets the conversation id.
@property (nonatomic, strong) NSNumber * _Nullable Id;

/// Sets the topicId.
@property (nonatomic, strong) NSString * _Nullable topicId;

/// Topic detail json string.
@property (nonatomic, strong) NSString * _Nullable topicDetailJson;

/// Sets the groupId of conversation.
@property (nonatomic, strong) NSNumber * _Nullable groupId;

/// Sets the userId for the conversation for topic.
@property (nonatomic, strong) NSString * _Nullable userId;

/// :nodoc:
@property (nonatomic, strong) NSArray * _Nullable supportIds;

/// :nodoc:
@property (nonatomic, strong) NSMutableArray * _Nullable fallBackTemplatesListArray;

/// :nodoc:
@property (nonatomic, strong) NSMutableDictionary * _Nullable fallBackTemplateForSENDER;

/// :nodoc:
@property (nonatomic, strong) NSMutableDictionary * _Nullable fallBackTemplateForRECEIVER;

/// :nodoc:
@property (nonatomic) BOOL created;

/// :nodoc:
@property (nonatomic) BOOL closed;

/// This method is used for parsing the context based conversation.
/// @param messageDictonary Pass the JSON Dictionary.
- (id)initWithDictonary:(NSDictionary *)messageDictonary;

/// Returns the topic detail.
- (KBMTopicDetail * _Nullable)getTopicDetail;

/// Gets the dictionary from `KBMConversationProxy`.
/// @param conversationProxy Pass the `KBMConversationProxy` object.
+ (NSMutableDictionary *)getDictionaryForCreate:(KBMConversationProxy *)conversationProxy;

/// :nodoc:
- (void)setSenderSMSFormat:(NSString *)senderFormatString;

/// :nodoc:
- (void)setReceiverSMSFormat:(NSString *)recieverFormatString;

@end

NS_ASSUME_NONNULL_END
