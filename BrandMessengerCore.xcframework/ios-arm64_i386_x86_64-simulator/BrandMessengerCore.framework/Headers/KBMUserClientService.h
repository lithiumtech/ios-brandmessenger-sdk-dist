//
//  KBMUserClientService.h
//  BrandMessengerCore
//
//  Created by Devashish on 21/12/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import "KBMContact.h"
#import "KBMContactsResponse.h"
#import "KBMLastSeenSyncFeed.h"
#import "KBMMuteRequest.h"
#import "KBMResponseHandler.h"
#import "KBMUserDetailListFeed.h"
#import <Foundation/Foundation.h>

@interface KBMUserClientService : NSObject

@property (nonatomic, strong) KBMResponseHandler *responseHandler;

- (void)userLastSeenDetail:(NSNumber *)lastSeenAtTime withCompletion:(void(^)(KBMLastSeenSyncFeed *lastSeenSyncFeed))completionMark;

- (void)userDetailServerCall:(NSString *)userId withCompletion:(void(^)(KBMUserDetail *userDetail))completionMark;

- (void)updateUserDisplayName:(KBMContact *)contact withCompletion:(void(^)(id jsonResponse, NSError *error))completion;

- (void)markConversationAsReadforContact:(NSString *)userId withCompletion:(void (^)(NSString *jsonResponse, NSError *error))completion;

- (void)userBlockServerCall:(NSString *)userId withCompletion:(void (^)(NSString *jsonResponse, NSError *error))completion;

- (void)userBlockSyncServerCall:(NSNumber *)lastSyncTime withCompletion:(void (^)(NSString *jsonResponse, NSError *error))completion;

- (void)userUnblockServerCall:(NSString *)userId withCompletion:(void (^)(NSString *jsonResponse, NSError *error))completion;

- (void)markMessageAsReadforPairedMessageKey:(NSString *)pairedMessageKey
                              withCompletion:(void (^)(NSString *jsonResponse, NSError *error))completion;

- (void)multiUserSendMessage:(NSDictionary *)messageDictionary
                  toContacts:(NSMutableArray *)contactIdsArray
                    toGroups:(NSMutableArray *)channelKeysArray
              withCompletion:(void (^)(NSString *jsonResponse, NSError *error))completion;

- (void)getListOfRegisteredUsers:(NSNumber *)startTime
                     andPageSize:(NSUInteger)pageSize
                  withCompletion:(void(^)(KBMContactsResponse *response, NSError *error))completion;

- (void)fetchOnlineContactFromServer:(NSUInteger)limit withCompletion:(void (^)(id jsonResponse, NSError *error))completion;

- (void)subProcessUserDetailServerCall:(NSString *)paramString
                        withCompletion:(void(^)(NSMutableArray *userDetailArray, NSError *error))completionMark;
- (void)updateUserDisplayName:(NSString *)displayName
             andUserImageLink:(NSString *)imageLink
                   userStatus:(NSString *)status
                     metadata:(NSMutableDictionary *)metadata
               withCompletion:(void (^)(id jsonResponse, NSError *error))completionHandler;

- (void)updateUser:(NSString *)phoneNumber
             email:(NSString *)email
            ofUser: (NSString *)userId
    withCompletion:(void(^)(id jsonResponse, NSError *error))completion;

- (void)subProcessUserDetailServerCallPOST:(KBMUserDetailListFeed *)userDetailListFeed
                            withCompletion:(void(^)(NSMutableArray *userDetailArray, NSError *error))completionMark;

- (void)updatePassword:(NSString *)oldPassword
      withNewPassword:(NSString *)newPassword
        withCompletion:(void (^)(KBMAPIResponse *apiResponse, NSError *error))completion;

- (void)getListOfUsersWithUserName:(NSString *)userName withCompletion:(void(^)(KBMAPIResponse *response, NSError *error))completion;

- (void)getMutedUserListWithCompletion:(void(^)(id jsonResponse, NSError *error))completion;

- (void)muteUser:(KBMMuteRequest *)muteRequest withCompletion:(void(^)(KBMAPIResponse *response, NSError *error))completion;

- (void)reportUserWithMessageKey:(NSString *)messageKey withCompletion:(void (^)(KBMAPIResponse *apiResponse, NSError *error))completion;

@end
