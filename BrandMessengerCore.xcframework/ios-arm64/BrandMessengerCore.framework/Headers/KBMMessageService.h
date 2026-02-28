//
// KBMMessageService.h
// BrandMessengerCore
//
// Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "KBMChannelService.h"
#import "KBMConstant.h"
#import "KBMConversationProxy.h"
#import "KBMMessage.h"
#import "KBMMessageClientService.h"
#import "KBMMessageInfoResponse.h"
#import "KBMMessageList.h"
#import "KBMMQTTConversationService.h"
#import "KBMRealTimeUpdate.h"
#import "KBMSyncMessageFeed.h"
#import "KBMUserDetail.h"
#import "KBMUserService.h"
#import "DB_FileMetaInfo.h"
#import <Foundation/Foundation.h>
#import "MessageListRequest.h"
#import "BrandMessengerClient.h"

NS_ASSUME_NONNULL_BEGIN

@protocol KBMAttachmentDelegate;

/// Used when a message needs to be modified just before sending
@protocol KBMConversationDelegate <NSObject>

/// modifies and returns a message object to be sent
-(KBMMessage *)modifyMessageBeforeSend: (KBMMessage *) message;

@end

/// Notification name for new message.
static NSString *const NEW_MESSAGE_NOTIFICATION = @"newMessageNotification";
/// Notification name for the message metadata update.
static NSString *const KBM_MESSAGE_META_DATA_UPDATE = @"messageMetaDataUpdateNotification";
/// Notification name for the single message deleted.
static NSString *const KBM_MESSAGE_DELETE_NOTIFICATION_KEY = @"kbmMessageDeletedNotification";

/// `KBMMessageService` class has major methods for message API's
@interface KBMMessageService : NSObject

+ (KBMMessageService *)sharedInstance;

@property (nonatomic, strong) KBMMessageClientService *messageClientService;
@property (nonatomic, strong) KBMUserService *userService;
@property (nonatomic, strong) KBMChannelService *channelService;

@property (nonatomic, weak) id<KBMAttachmentDelegate> _Nullable attachmentProgressDelegate;

@property (nonatomic, weak) id<KBMUpdatesDelegate> _Nullable delegate;
///
@property (nonatomic, weak) id<KBMConversationDelegate> _Nullable conversationDelegate;

+ (BOOL)getCurrentlySendingPendingMessagesFlag;

/// Sends text message in one to one or group conversation.
/// @param message Pass the KBMMessage object for sending a text message.
/// @param completion If success in sending a message the NSError will be nil; else, if there is an error in sending a message the NSError will not be nil.
- (void)sendMessages:(KBMMessage *)message withCompletion:(void(^)(NSString * _Nullable message, NSError * _Nullable error)) completion;

/// Gets the recent messages for contact or group.
/// @param isNextPage If you want to load the next set of messages pass YES or true to load else pass NO or false.
/// @param isGroup To get groups messages only then pass YES or true it will give group latest messages else
/// to get only user latest messages then pass NO or false.
/// @param completion Array of messages of type KBMMessage and error if failed to get the messages.
- (void)getLatestMessages:(BOOL)isNextPage
           withOnlyGroups:(BOOL)isGroup
    withCompletionHandler:(void(^)(NSMutableArray * _Nullable messages, NSError * _Nullable error)) completion;

/// Gets the messages for the one-to-one or group chat from the server.
/// @param messageListRequest Pass the MessageListRequest in case of one-to-one pass the userId or channelKey in case of a group.
/// @param setUnreadCount Pass true to set contact's unreadCount to 0 if server returns 0. Default behavior is, 0 is ignored.
/// @param completion If messages are fetched successfully, it will have a list of KBMMessage objects; else, it will have NSError in case any error comes.
- (void)getMessageListForUser:(MessageListRequest *)messageListRequest
               setUnreadCount:(BOOL)setUnreadCount
               withCompletion:(void (^)(NSMutableArray *messages, NSError *error, NSMutableArray *userDetailArray))completion;

/// Gets the messages for the one-to-one or group chat from the server.
/// @param messageListRequest Pass the MessageListRequest in case of one-to-one pass the userId or channelKey in case of a group.
/// @param completion If messages are fetched successfully, it will have a list of KBMMessage objects; else, it will have NSError in case any error comes.
- (void)getMessageListForUser:(MessageListRequest *)messageListRequest
               withCompletion:(void(^)(NSMutableArray * _Nullable messages, NSError * _Nullable error, NSMutableArray * _Nullable userDetailArray)) completion;

/// Gets the message information which will have delivered and read for users in group chat.
/// @param messageKey Pass the message key from the message object.
/// @param completion If success in fetching the message information then NSError will be nil else on failure in fetching message information then NSError will not be nil.
- (void)getMessageInformationWithMessageKey:(NSString *)messageKey
                      withCompletionHandler:(void(^)(KBMMessageInfoResponse * _Nullable messageInfoResponse, NSError * _Nullable error))completion;

/// Deletes the conversation thread in a one-to-one or group chat.
/// @param contactId Pass the userId in case deleting the conversation for one-to-one; otherwise, it will be nil.
/// @param channelKey Pass the channelKey in case of deleting conversation for group chat, else it will be nil.
/// @param completion If success in deleting the thread then NSError is nil; else, if failure in deleting then NSError will not be nil.
- (void)deleteMessageThread:(NSString * _Nullable )contactId
               orChannelKey:(NSNumber * _Nullable )channelKey
             withCompletion:(void (^)(NSString * _Nullable response, NSError * _Nullable error))completion;

/// Deletes the message for given message key.
/// @param keyString Pass the message key from the message object to delete the message.
/// @param contactId Pass it as nil.
/// @param completion If success in deleting the message then error is nil else on failure in deleting NSError will not be nil.
- (void)deleteMessage:(NSString *)keyString
         andContactId:(NSString * _Nullable )contactId
       withCompletion:(void (^)(NSString * _Nullable response, NSError * _Nullable error))completion;

/// Updates message metadata for given message key.
/// @param messageKey Pass the message key for updating message meta data.
/// @param metadata Pass the updated message metadata for updating.
/// @param completion If an error in deleting a message for all then NSError will not be nil else on successful delete error will be nil.
- (void)updateMessageMetadataOfKey:(NSString *)messageKey
                      withMetadata:(NSMutableDictionary *)metadata
                    withCompletion:(void(^)(KBMAPIResponse * _Nullable apiResponse, NSError * _Nullable error)) completion;

/// Gets reply messages by message keys and updates the reply flag.
/// @param keys Pass the array of message keys.
/// @param completion If there is no error in fetching messages, then it will have an array of messages. else it will have nil.
- (void)fetchReplyMessages:(NSMutableArray<NSString *> *)keys withCompletion: (void(^)(NSMutableArray<KBMMessage *> * _Nullable messages))completion;

/// Gets messages by message keys.
/// @param keys Pass the array of message keys.
/// @param completion If there is no error in fetching messages, then it will have an array of messages. otherwise an error describe the failure.
- (void)getMessagesWithkeys:(NSMutableArray<NSString *> *)keys
             withCompletion: (void(^)(NSMutableArray<KBMMessage *> * _Nullable messages, NSError * _Nullable error))completion;

/// Deletes the message for all in channel conversation.
/// @param keyString Pass the message key from KBMMessage object.
/// @param completion If an error in deleting a message for all then NSError will not be nil else on successful delete error will be nil.
- (void)deleteMessageForAllWithKey:(NSString *)keyString
                    withCompletion:(void (^)(KBMAPIResponse * _Nullable apiResponse, NSError * _Nullable error))completion;

/// Total unread message count.
/// @param completion will have a total unread message count if there is no error in fetching.
- (void)getTotalUnreadMessageCountWithCompletionHandler:(void (^)(NSUInteger unreadCount, NSError * _Nullable error))completion;

/// Total unread conversation count.
/// @param completion will have a total unread conversation count if there is no error in fetching.
- (void)getTotalUnreadConversationCountWithCompletionHandler:(void (^)(NSUInteger conversationUnreadCount, NSError * _Nullable error))completion;

/// Returns `KBMMessage` object for given message key.
- (KBMMessage * _Nullable)getMessageByKey:(NSString *)messageKey;

/// Returns an `KBMMessage` object for key and value.
+ (KBMMessage * _Nullable)getMessagefromKeyValuePair:(NSString *)key andValue:(NSString *)value;

+ (void)getMessageListForContactId:(NSString * _Nullable)contactIds
                           isGroup:(BOOL)isGroup
                        channelKey:(NSNumber * _Nullable)channelKey
                    conversationId:(NSNumber * _Nullable)conversationId
                        startIndex:(NSInteger)startIndex
                    withCompletion:(void (^)(NSMutableArray * _Nullable messages))completion;

/// Sends the pending messages.
- (void)processPendingMessages;

+ (void)multiUserSendMessage:(KBMMessage *)message
                  toContacts:(NSMutableArray *)contactIdsArray
                    toGroups:(NSMutableArray *)channelKeysArray
              withCompletion:(void(^)(NSString * _Nullable jsonResponse, NSError * _Nullable error)) completion;

+ (void)getMessageSENT:(KBMMessage *)message withCompletion:(void (^)(NSMutableArray * _Nullable messages, NSError * _Nullable error))completion;

+ (void)getMessageSENT:(KBMMessage *)message
          withDelegate:(id<KBMUpdatesDelegate> _Nullable)delegate
        withCompletion:(void (^)(NSMutableArray * _Nullable messages, NSError * _Nullable error))completion;

+ (KBMMessage * _Nullable)createCustomTextMessageEntitySendTo:(NSString *)to withText:(NSString *)text;

- (void)getMessageListForUserIfLastIsHiddenMessageinMessageList:(KBMMessageList *)messageList
                                                 withCompletion:(void (^)(NSMutableArray * _Nullable messages,
                                                                          NSError * _Nullable error,
                                                                          NSMutableArray * _Nullable userDetailArray))completion;

- (void)getMessagesListGroupByContactswithCompletionService:(void(^)(NSMutableArray * _Nullable messages, NSError * _Nullable error))completion;

+ (KBMMessage * _Nullable)createHiddenMessageEntitySentTo:(NSString *)to withText:(NSString *)text;

+ (KBMMessage * _Nullable)createMessageWithMetaData:(NSMutableDictionary *)metaData
                                    andContentType:(short)contentType
                                     andReceiverId:(NSString *)receiverId
                                    andMessageText:(NSString *)messageText;


/// Returns total number of messages.
/// @param userId Pass the receiver userId.
- (NSUInteger)getMessagsCountForUser:(NSString *)userId;

- (KBMMessage * _Nullable)getLatestMessageForUser:(NSString *)userId;

- (KBMMessage * _Nullable)getLatestMessageForChannel:(NSNumber *)channelKey excludeChannelOperations:(BOOL)flag;

+ (void)syncMessages;

+ (void)getLatestMessageForUser:(NSString *)deviceKeyString withCompletion:(void(^)(NSMutableArray * _Nullable messages, NSError * _Nullable error)) completion;
+ (void)getLatestMessageForUser:(NSString *)deviceKeyString
                   withDelegate:(id<KBMUpdatesDelegate> _Nullable )delegate
                 withCompletion:(void (^)(NSMutableArray * _Nullable messages, NSError * _Nullable error))completion;

/// Syncs the messages where metadata is updated.
/// @param deviceKeyString Pass the [KBMUserDefaultsHandler getDeviceKeyString].
/// @param completion If error in syncing a updated meta data messages then NSError will be their else a array of messages if their is no error in syncing a updated meta data messages.
+ (void)syncMessageMetaData:(NSString *)deviceKeyString withCompletion:(void (^)(NSMutableArray * _Nullable messages, NSError * _Nullable error))completion;

+ (void)addOpenGroupMessage:(KBMMessage *)message
               withDelegate:(id<KBMUpdatesDelegate> _Nullable )delegate
             withCompletion:(void (^)(BOOL success))completion;

- (KBMMessage * _Nullable)handleMessageFailedStatus:(KBMMessage *)message;

+ (KBMMessage * _Nullable)processFileUploadSucess:(KBMMessage *)message;

@end

NS_ASSUME_NONNULL_END
