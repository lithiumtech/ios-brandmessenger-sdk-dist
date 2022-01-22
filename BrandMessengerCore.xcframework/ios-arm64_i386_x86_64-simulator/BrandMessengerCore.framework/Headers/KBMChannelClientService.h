//
//  KBMChannelClientService.h
//  BrandMessengerCore
//
//  Created by devashish on 28/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//  class for server calls

#import "KBMAPIResponse.h"
#import "KBMChannel.h"
#import "KBMChannelCreateResponse.h"
#import "KBMChannelDBService.h"
#import "KBMChannelFeed.h"
#import "KBMChannelFeedResponse.h"
#import "KBMChannelSyncResponse.h"
#import "KBMChannelUserX.h"
#import "KBMConstant.h"
#import "KBMMuteRequest.h"
#import "KBMRequestHandler.h"
#import "KBMResponseHandler.h"
#import <Foundation/Foundation.h>

@interface KBMChannelClientService : NSObject

@property (nonatomic, strong) KBMResponseHandler *responseHandler;

- (void)createChannel:(NSString *)channelName
  andParentChannelKey:(NSNumber *)parentChannelKey
   orClientChannelKey:(NSString *)clientChannelKey
       andMembersList:(NSMutableArray *)memberArray
         andImageLink:(NSString *)imageLink
          channelType:(short)type
          andMetaData:(NSMutableDictionary *)metaData
            adminUser:(NSString *)adminUserId
       withCompletion:(void(^)(NSError *error, KBMChannelCreateResponse *response))completion;

- (void)addMemberToChannel:(NSString *)userId
        orClientChannelKey:(NSString *)clientChannelKey
             andChannelKey:(NSNumber *)channelKey
            withCompletion:(void(^)(NSError *error, KBMAPIResponse *response))completion;

- (void)removeMemberFromChannel:(NSString *)userId
             orClientChannelKey:(NSString *)clientChannelKey
                  andChannelKey:(NSNumber *)channelKey
                 withCompletion:(void(^)(NSError *error, KBMAPIResponse *response))completion;

- (void)deleteChannel:(NSNumber *)channelKey
   orClientChannelKey:(NSString *)clientChannelKey
       withCompletion:(void(^)(NSError *error, KBMAPIResponse *response))completion;

- (void)leaveChannel:(NSNumber *)channelKey
  orClientChannelKey:(NSString *)clientChannelKey
          withUserId:(NSString *)userId
       andCompletion:(void(^)(NSError *error, KBMAPIResponse *response))completion;

- (void)addMultipleUsersToChannel:(NSMutableArray *)channelKeys
                     channelUsers:(NSMutableArray *)channelUsers
                    andCompletion:(void(^)(NSError *error, KBMAPIResponse *response))completion;

- (void)updateChannel:(NSNumber *)channelKey
   orClientChannelKey:(NSString *)clientChannelKey
           andNewName:(NSString *)newName
          andImageURL:(NSString *)imageURL
             metadata:(NSMutableDictionary *)metaData
          orChildKeys:(NSMutableArray *)childKeysList
       orChannelUsers:(NSMutableArray *)channelUsers
        andCompletion:(void(^)(NSError *error, KBMAPIResponse *response))completion;

- (void)updateChannelMetaData:(NSNumber *)channelKey
           orClientChannelKey:(NSString *)clientChannelKey
                     metadata:(NSMutableDictionary *)metaData
                andCompletion:(void(^)(NSError *error, KBMAPIResponse *response))completion;

- (void)getChannelInformationResponse:(NSNumber *)channelKey
                   orClientChannelKey:(NSString *)clientChannelKey
                       withCompletion:(void(^)(NSError *error, KBMChannelFeedResponse *response)) completion;

- (void)syncCallForChannel:(NSNumber *)updatedAtTime
      withFetchUserDetails:(BOOL)fetchUserDetails
             andCompletion:(void(^)(NSError *error, KBMChannelSyncResponse *response))completion;

- (void)markConversationAsRead:(NSNumber *)channelKey withCompletion:(void (^)(NSString *jsonResponse, NSError *error))completion;

- (void)addChildKeyList:(NSMutableArray *)childKeyList
           andParentKey:(NSNumber *)parentKey
         withCompletion:(void (^)(id jsonResponse, NSError *error))completion;

- (void)removeChildKeyList:(NSMutableArray *)childKeyList
              andParentKey:(NSNumber *)parentKey
            withCompletion:(void (^)(id jsonResponse, NSError *error))completion;

- (void)addClientChildKeyList:(NSMutableArray *)clientChildKeyList
           andClientParentKey:(NSString *)clientParentKey
               withCompletion:(void (^)(id jsonResponse, NSError *error))completion;

- (void)removeClientChildKeyList:(NSMutableArray *)clientChildKeyList
              andClientParentKey:(NSString *)clientParentKey
                  withCompletion:(void (^)(id jsonResponse, NSError *error))completion;

- (void)muteChannel:(KBMMuteRequest *)muteRequest withCompletion:(void(^)(KBMAPIResponse *response, NSError *error))completion;

- (void)getChannelInfoByIdsOrClientIds:(NSMutableArray *)channelIds
                    orClinetChannelIds:(NSMutableArray *)clientChannelIds
                        withCompletion:(void(^)(NSMutableArray *channelInfoList, NSError *error))completion;

- (void)getChannelListForCategory:(NSString *)category
                   withCompletion:(void(^)(NSMutableArray *channelInfoList, NSError *error))completion;

- (void)getAllChannelsForApplications:(NSNumber *)endTime
                       withCompletion:(void(^)(NSMutableArray *channelInfoList, NSError *error))completion;

- (void)addMemberToContactGroupOfType:(NSString *)contactsGroupId
                          withMembers:(NSMutableArray *)membersArray
                        withGroupType:(short)groupType
                       withCompletion:(void(^)(KBMAPIResponse *response, NSError *error))completion;


- (void)addMemberToContactGroup:(NSString *)contactsGroupId
                    withMembers:(NSMutableArray *)membersArray
                 withCompletion:(void(^)(KBMAPIResponse *response, NSError *error))completion;

- (void)getMembersFromContactGroupOfType:(NSString *)contactGroupId
                           withGroupType:(short)groupType
                          withCompletion:(void(^)(NSError *error, KBMChannel *channel)) completion;

- (void)getMembersFromContactGroup:(NSString *)contactGroupId withCompletion:(void(^)(NSError *error, KBMChannel *channel)) completion;

- (void)removeMemberFromContactGroup:(NSString *)contactsGroupId
                          withUserId:(NSString *)userId
                      withCompletion:(void(^)(KBMAPIResponse *response, NSError *error))completion;

- (void)removeMemberFromContactGroupOfType:(NSString *)contactsGroupId
                             withGroupType:(short)groupType
                                withUserId:(NSString *)userId
                            withCompletion:(void(^)(KBMAPIResponse *response, NSError *error))completion;

- (void)getMultipleContactGroup:(NSArray *)contactGroupIds withCompletion:(void(^)(NSError *error, NSArray *channel)) completion;

- (void)createChannel:(NSString *)channelName
  andParentChannelKey:(NSNumber *)parentChannelKey
   orClientChannelKey:(NSString *)clientChannelKey
       andMembersList:(NSMutableArray *)memberArray
         andImageLink:(NSString *)imageLink
          channelType:(short)type
          andMetaData:(NSMutableDictionary *)metaData
           adminUser :(NSString *)adminUserId
      withGroupUsers :(NSMutableArray *)groupRoleUsers
       withCompletion:(void(^)(NSError *error, KBMChannelCreateResponse *response))completion;

- (void)getChannelInfo:(NSNumber *)channelKey
    orClientChannelKey:(NSString *)clientChannelKey
        withCompletion:(void(^)(NSError *error, KBMChannel *channel)) completion DEPRECATED_MSG_ATTRIBUTE("Use getChannelInformationByResponse:orClientChannelKey:withCompletion from KBMChannelService instead");

@end
