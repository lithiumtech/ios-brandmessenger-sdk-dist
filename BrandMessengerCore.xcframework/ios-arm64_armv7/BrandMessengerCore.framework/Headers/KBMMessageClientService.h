//
//  KBMMessageClientService.h
//  BrandMessengerCore
//
//  Created by devashish on 02/10/2015.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "KBMContactDBService.h"
#import "KBMMessage.h"
#import "KBMMessageInfoResponse.h"
#import "KBMMessageList.h"
#import "KBMResponseHandler.h"
#import "KBMSearchRequest.h"
#import "KBMSyncMessageFeed.h"
#import <Foundation/Foundation.h>
#import "MessageListRequest.h"

@interface KBMMessageClientService : NSObject

@property (nonatomic, strong) KBMResponseHandler *responseHandler;

- (void)addWelcomeMessage:(NSNumber *)channelKey;

- (void)getLatestMessageGroupByContact:(NSUInteger)mainPageSize
                             startTime:(NSNumber *)startTime
                        withCompletion:(void(^)(KBMMessageList *messageList, NSError *error))completion;

- (void)getMessagesListGroupByContactswithCompletion:(void(^)(NSMutableArray *messages, NSError *error)) completion;

- (void)getMessageListForUser:(MessageListRequest *)messageListRequest
               withCompletion:(void (^)(NSMutableArray *messages, NSError *error, NSMutableArray *userDetailArray))completion;

- (void)sendPhotoForUserInfo:(NSDictionary *)messageDictionary withCompletion:(void(^)(NSString *message, NSError *error)) completion;

- (void)getLatestMessageForUser:(NSString *)deviceKeyString withCompletion:(void (^)(KBMSyncMessageFeed *syncMessageFeed, NSError *error))completion;

- (void)deleteMessage:(NSString *)keyString
         andContactId:(NSString *)contactId
       withCompletion:(void (^)(NSString *response, NSError *error))completion;

- (void)deleteMessageThread:(NSString *)contactId
               orChannelKey:(NSNumber *)channelKey
             withCompletion:(void (^)(NSString *response, NSError *error))completion;

- (void)sendMessage:(NSDictionary *)userInfo withCompletionHandler:(void(^)(id jsonResponse, NSError *error))completion;

- (void)getCurrentMessageInformation:(NSString *)messageKey
               withCompletionHandler:(void(^)(KBMMessageInfoResponse *messageInfoResponse, NSError *error))completion;

- (void)getMessageListForUser:(MessageListRequest *)messageListRequest
                withOpenGroup:(BOOL)isOpenGroup
               withCompletion:(void (^)(NSMutableArray *messages, NSError *error, NSMutableArray *userDetails))completion;

- (void)downloadImageUrl:(NSString *)blobKey withCompletion:(void(^)(NSString *fileURL, NSError *error)) completion;

- (void)downloadImageThumbnailUrl:(NSString *)url
                          blobKey:(NSString *)blobKey
                       completion:(void(^)(NSString *fileURL, NSError *error)) completion;

- (void)getLatestMessageForUser:(NSString *)deviceKeyString
               withMetaDataSync:(BOOL)isMetaDataUpdate
                 withCompletion:(void (^)(KBMSyncMessageFeed *syncMessageFeed, NSError *error))completion;

- (void)updateMessageMetadataOfKey:(NSString *)messageKey
                      withMetadata:(NSMutableDictionary *)metadata
                    withCompletion:(void(^)(id jsonResponse, NSError *error))completion;

- (void)getMessageListForUser:(MessageListRequest *)messageListRequest
                     isSearch:(BOOL)flag
               withCompletion:(void (^)(NSMutableArray<KBMMessage *> *messages, NSError *error))completion;

- (void)searchMessage:(NSString *)key withCompletion:(void (^)(NSMutableArray<KBMMessage *> *messages, NSError *error))completion;

- (void)searchMessageWith:(KBMSearchRequest *)request withCompletion:(void (^)(NSMutableArray<KBMMessage *> *messages, NSError *error))completion;

- (void)getMessagesWithkeys:(NSMutableArray<NSString *> *)keys
             withCompletion:(void(^)(KBMAPIResponse *response, NSError *error))completion;

- (void)deleteMessageForAllWithKey:(NSString *)keyString
                    withCompletion:(void (^)(KBMAPIResponse *apiResponse, NSError *error))completion;

-(void)mailTranscriptWithEmail:(NSString *)email
                 withBrandName:(NSString *)brandName
                withCompletion:(void (^)(KBMAPIResponse *apiResponse, NSError *error))completion;

@end
