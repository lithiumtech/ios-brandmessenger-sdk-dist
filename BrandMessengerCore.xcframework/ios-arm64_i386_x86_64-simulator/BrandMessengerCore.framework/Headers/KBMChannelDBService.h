//
//  KBMChannelDBService.h
//  BrandMessengerCore
//
//  Created by devashish on 28/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//  class for databse actios for group

#import "BrandMessengerSettings.h"
#import "KBMChannel.h"
#import "KBMChannelUserX.h"
#import "KBMConversationProxy.h"
#import "KBMDBHandler.h"
#import "KBMRealTimeUpdate.h"
#import "DB_CHANNEL.h"
#import "DB_CHANNEL_USER_X.h"
#import "DB_ConversationProxy.h"
#import <Foundation/Foundation.h>

@interface KBMChannelDBService : NSObject

- (NSError *)addMemberToChannel:(NSString *)userId andChannelKey:(NSNumber *)channelKey;

- (void)insertChannel:(NSMutableArray *)channelList;

- (DB_CHANNEL *)createChannelEntity:(KBMChannel *)channel;

- (void)insertChannelUserX:(NSMutableArray *)channelUserXList;

- (DB_CHANNEL_USER_X *)createChannelUserXEntity:(KBMChannelUserX *)channelUserX;

- (NSMutableArray *)getChannelMembersList:(NSNumber *)channelKey;

- (KBMChannel *)loadChannelByKey:(NSNumber *)channelKey;

- (DB_CHANNEL *)getChannelByKey:(NSNumber *)channelKey;

- (NSString *)userNamesWithCommaSeparatedForChannelkey:(NSNumber *)channelKey;

- (KBMChannel *)checkChannelEntity:(NSNumber *)channelKey;

- (NSError *)removeMemberFromChannel:(NSString *)userId andChannelKey:(NSNumber *)channelKey;

- (NSError *)deleteChannel:(NSNumber *)channelKey;

- (NSMutableArray *)getAllChannelKeyAndName;

- (NSError *)updateChannel:(NSNumber *)channelKey
                andNewName:(NSString *)newName
                orImageURL:(NSString *)imageURL
               orChildKeys:(NSMutableArray *)childKeysList
        isUpdatingMetaData:(BOOL)flag
            orChannelUsers:(NSMutableArray *)channelUsers;

- (NSError *)updateChannelMetaData:(NSNumber *)channelKey metaData:(NSMutableDictionary *)newMetaData;

- (NSMutableArray *)getListOfAllUsersInChannel:(NSNumber *)channelKey;

- (NSUInteger)markConversationAsRead:(NSNumber *)channelKey;

- (NSArray *)getUnreadMessagesForGroup:(NSNumber *)groupId;

- (void)updateUnreadCountChannel:(NSNumber *)channelKey unreadCount:(NSNumber *)unreadCount;

- (void)setLeaveFlag:(BOOL)flag forChannel:(NSNumber *)channelKey;

- (BOOL)isChannelLeft:(NSNumber *)channelKey;

- (BOOL)isChannelDeleted:(NSNumber *)channelKey;

- (BOOL)isConversaionClosed:(NSNumber *)channelKey;

- (BOOL)isAdminBroadcastChannel:(NSNumber *)channelKey;

- (void)updateChannelParentKey:(NSNumber *)channelKey
              andWithParentKey:(NSNumber *)channelParentKey
                      isAdding:(BOOL)flag;

- (void)updateClientChannelParentKey:(NSString *)clientChildKey
              andWithClientParentKey:(NSString *)clientParentKey
                            isAdding:(BOOL)flag;

- (NSNumber *)getOverallUnreadCountForChannelFromDB;

- (KBMChannel *)loadChannelByClientChannelKey:(NSString *)clientChannelKey;

- (void)removedMembersArray:(NSMutableArray *)memberArray andChannelKey:(NSNumber *)channelKey;

- (void)addedMembersArray:(NSMutableArray *)memberArray andChannelKey:(NSNumber *)channelKey;

- (NSMutableArray *)fetchChildChannels:(NSNumber *)parentGroupKey;

- (NSError *)updateMuteAfterTime:(NSNumber *)notificationAfterTime andChnnelKey:(NSNumber *)channelKey;

- (KBMChannelUserX *)loadChannelUserXByUserId:(NSNumber *)channelKey andUserId:(NSString *)userId;

- (void)updateParentKeyInChannelUserX:(NSNumber *)channelKey andWithParentKey:(NSNumber *)parentKey addUserId:(NSString *)userId;

- (void)updateRoleInChannelUserX:(NSNumber *)channelKey andUserId:(NSString *)userId withRoleType:(NSNumber *)role;

- (NSMutableArray *)getListOfAllUsersInChannelByNameForContactsGroup:(NSString *)channelName;

- (DB_CHANNEL *)getContactsGroupChannelByName:(NSString *)channelName;

- (NSMutableArray *)getGroupUsersInChannel:(NSNumber *)channelKey;

- (void)fetchChannelMembersAsyncWithChannelKey:(NSNumber *)channelKey witCompletion:(void(^)(NSMutableArray *membersArray))completion;

- (void)getUserInSupportGroup:(NSNumber *)channelKey withCompletion:(void(^)(NSString *userId)) completion;

- (DB_CHANNEL_USER_X *)createChannelUserXEntity:(KBMChannelUserX *)channelUserX withContext:(NSManagedObjectContext *)context;

- (NSError *)deleteMembers:(NSNumber *)key;

- (DB_CHANNEL_USER_X *)getChannelUserX:(NSNumber *)channelKey DEPRECATED_ATTRIBUTE;

- (KBMChannelUserX *)loadChannelUserX:(NSNumber *)channelKey DEPRECATED_ATTRIBUTE;

@end
