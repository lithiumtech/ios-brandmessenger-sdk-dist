//
//  KBMMessageDBService.h
//  BrandMessengerCore
//
//  Created by Devashish on 21/09/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMConversationListRequest.h"
#import "KBMFileMetaInfo.h"
#import "KBMMessage.h"
#import "DB_FileMetaInfo.h"
#import "DB_Message.h"
#import <Foundation/Foundation.h>
#import "MessageListRequest.h"

@class KBMMessageService;

@protocol KBMMessagesDelegate <NSObject>

- (void)getMessagesArray:(NSMutableArray *)messagesArray;

- (void)updateMessageList:(NSMutableArray *)messagesArray;

@end

@interface KBMMessageDBService : NSObject

@property(nonatomic,weak) id <KBMMessagesDelegate>delegate;

@property(nonatomic, retain) KBMMessageService *messageService;

//Add Message APIS
- (NSMutableArray *)addMessageList:(NSMutableArray *)messages skipAddingMessageInDb:(BOOL)skip;
- (DB_Message *)addMessage:(KBMMessage *)message;
- (void)getMessages:(NSMutableArray *)subGroupList;
- (void)fetchConversationsGroupByContactId;
- (void)fetchAndRefreshQuickConversationWithCompletion:(void (^)(NSMutableArray *messages, NSError *error))completion;
- (void)fetchAndRefreshFromServerWithCompletion:(void(^)(NSMutableArray *messages, NSError *error)) completion;
- (void)getLatestMessagesWithCompletion:(void(^)(NSMutableArray *messages, NSError *error)) completion;

- (NSManagedObject *)getMeesageById:(NSManagedObjectID *)objectID;
- (NSManagedObject *)getMessageByKey:(NSString *)key value:(NSString *)value;

- (NSMutableArray *)getMessageListForContactWithCreatedAt:(MessageListRequest *)messageListRequest;

- (NSMutableArray *)getAllMessagesWithAttachmentForContact:(NSString *)contactId
                                             andChannelKey:(NSNumber *)channelKey
                                 onlyDownloadedAttachments:(BOOL)onlyDownloaded;

- (NSMutableArray *)getPendingMessages;

/**
 * Returns a list of last messages (Group by Contact)
 *
 * @param messageCount The Number of messages required.
 * @param received If YES, messages will be of type received. If NO, then messages can be of type received or sent.
 * @return An array containing the list of messages.
 */
- (NSArray *)getMessageList:(int)messageCount
    messageTypeOnlyReceived:(BOOL)received;

//update Message APIS
- (void)updateMessageDeliveryReport:(NSString *)messageKeyString withStatus:(int)status;
- (void)updateDeliveryReportForContact:(NSString *)contactId withStatus:(int)status;
- (void)updateMessageSyncStatus:(NSString *)keyString;
- (void)updateFileMetaInfo:(KBMMessage *)message;

//Delete Message APIS
- (NSError *)deleteMessageByKey:(NSString *)keyString;
- (NSError *)deleteAllMessagesByContact:(NSString *)contactId orChannelKey:(NSNumber *)key;

//Generic APIS
- (BOOL)isMessageTableEmpty;
- (void)deleteAllObjectsInCoreData;

- (DB_Message *)createMessageEntityForDBInsertionWithMessage:(KBMMessage *)message;
- (DB_FileMetaInfo *)createFileMetaInfoEntityForDBInsertionWithMessage:(KBMFileMetaInfo *)fileInfo;
- (KBMMessage *)createMessageEntity:(DB_Message *)dbMessage;
- (KBMMessage *)getMessageByKey:(NSString *)messageKey;

- (NSMutableArray *)fetchLatestConversationsGroupByContactId:(BOOL)isFetchOnCreatedAtTime;

- (void)fetchConversationfromServerWithCompletion:(void(^)(BOOL flag))completionHandler;

- (NSUInteger)getMessagesCountFromDBForUser:(NSString *)userId;

- (KBMMessage *)getLatestMessageForUser:(NSString *)userId;

- (KBMMessage *)getLatestMessageForChannel:(NSNumber *)channelKey excludeChannelOperations:(BOOL)flag;

- (void)updateMessageReplyType:(NSString *)messageKeyString replyType:(NSNumber *)type hideFlag:(BOOL)flag;

- (void)updateMessageSentDetails:(NSString *)messageKeyString
               withCreatedAtTime:(NSNumber *)createdAtTime
                   withDbMessage:(DB_Message *)dbMessage;

- (void)getLatestMessages:(BOOL)isNextPage withCompletionHandler:(void(^)(NSMutableArray *messages, NSError *error)) completion;

- (void)getLatestMessages:(BOOL)isNextPage
           withOnlyGroups:(BOOL)isGroup
    withCompletionHandler:(void(^)(NSMutableArray *messages, NSError *error)) completion;

- (KBMMessage *)handleMessageFailedStatus:(KBMMessage *)message;

- (DB_Message *)addAttachmentMessage:(KBMMessage *)message;

- (NSError *)updateMessageMetadataOfKey:(NSString *)messageKey withMetadata:(NSMutableDictionary *)metadata;

- (KBMMessage *)writeDataAndUpdateMessageInDB:(NSData *)data withMessage:(KBMMessage *)message withFileFlag:(BOOL)isFile;

/// Returns a list of last messages for group and contact based on the startTime or endTime
/// @param conversationListRequest Used for passing the startTime or endTime
- (NSMutableArray *)fetchLatestMessagesFromDatabaseWithRequestList:(KBMConversationListRequest *)conversationListRequest;

@end
