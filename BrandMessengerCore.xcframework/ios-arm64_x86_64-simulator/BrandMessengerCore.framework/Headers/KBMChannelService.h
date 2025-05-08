//
// KBMChannelService.h
// BrandMessengerCore
//
// Created by devashish on 04/01/2016.
// Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMChannelClientService.h"
#import "KBMChannelDBService.h"
#import "KBMChannelFeed.h"
#import "KBMChannelFeedResponse.h"
#import "KBMChannelInfo.h"
#import "KBMChannelSyncResponse.h"
#import "KBMRealTimeUpdate.h"
#import "KBMUserDefaultsHandler.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Constant key is used channel metadata for hidding or changing the channel action message for default create group.
static NSString *const KBM_CREATE_GROUP_MESSAGE = @"CREATE_GROUP_MESSAGE";
/// Constant key is used channel metadata for for hidding or changing the channel action message for default remove member in group.
static NSString *const KBM_REMOVE_MEMBER_MESSAGE = @"REMOVE_MEMBER_MESSAGE";
/// Constant key is used channel metadata for for hidding or changing the channel action message for default add member in group.
static NSString *const KBM_ADD_MEMBER_MESSAGE = @"ADD_MEMBER_MESSAGE";
/// Constant key is used channel metadata for for hidding or changing the channel action message for default joining member in group.
static NSString *const KBM_JOIN_MEMBER_MESSAGE = @"JOIN_MEMBER_MESSAGE";
/// Constant key is used channel metadata for for hidding or changing the channel action message for default group name.
static NSString *const KBM_GROUP_NAME_CHANGE_MESSAGE = @"GROUP_NAME_CHANGE_MESSAGE";
/// Constant key is used channel metadata for for hidding or changing the channel action message for default icon change.
static NSString *const KBM_GROUP_ICON_CHANGE_MESSAGE = @"GROUP_ICON_CHANGE_MESSAGE";
/// Constant key is used channel metadata for for hidding or changing the channel action message for default member left.
static NSString *const KBM_GROUP_LEFT_MESSAGE = @"GROUP_LEFT_MESSAGE";
/// Constant key is used channel metadata for for hidding or changing the channel action message for default delete group.
static NSString *const KBM_DELETED_GROUP_MESSAGE = @"DELETED_GROUP_MESSAGE";

/// `KBMChannelService` class has all API methods for Channel.
///
/// Some of the methods this class has :
/// Create channel, Update channel, Add member, Remove member, Channel information. List of channels.
@interface KBMChannelService : NSObject

/// This constant is set key for channel member save status.
extern NSString *const KBM_CHANNEL_MEMBER_SAVE_STATUS;
/// This constant is set key for channel member save update status data.
extern NSString *const KBM_Updated_Group_Members;
/// This constant is set key for channel member save completed status.
extern NSString *const KBM_CHANNEL_MEMBER_CALL_COMPLETED;
/// This constant is set key for Message list called.
extern NSString *const KBM_MESSAGE_LIST;
/// This constant is set key for Message Sync called.
extern NSString *const KBM_MESSAGE_SYNC;

/// Instance method of `KBMChannelService`.
+ (KBMChannelService *)sharedInstance;

/// Instance method of `KBMChannelClientService`.
@property (nonatomic, strong) KBMChannelClientService *channelClientService;

/// Instance method of `KBMChannelDBService`.
@property (nonatomic, strong) KBMChannelDBService *channelDBService;

/// Creates an channel given `KBMChannelInfo`.
/// @param channelInfo Pass the KBMChannelInfo which will have details for creating a channel.
/// @param completion Once the group/channel is created successful then `KBMChannelCreateResponse` else it will have NSError.
- (void)createChannelWithChannelInfo:(KBMChannelInfo *)channelInfo
                      withCompletion:(void(^)(KBMChannelCreateResponse * _Nullable response, NSError * _Nullable error))completion;


/// Gets information of channel like channel name, imageUrl of Channel, type of channel and other information.
/// @param channelKey Pass the channelkey or groupId that is required to get the channel information.
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param completion Pass the KBMChannel will have information of the channel else error in case of NSError.
- (void)getChannelInformationByResponse:(NSNumber * _Nullable)channelKey
                     orClientChannelKey:(NSString * _Nullable)clientChannelKey
                         withCompletion:(void (^)(NSError * _Nullable error,
                                                  KBMChannel * _Nullable channel,
                                                  KBMChannelFeedResponse * _Nullable channelResponse)) completion;

/// Adds a member to a channel.
/// @param userId Pass the userId that wanted to add in a channel.
/// @param channelKey Pass channelkey or groupId that is required for adding a member in a channel.
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param completion it has error and KBMAPIResponse where you can check if an error is not nil else in `KBMAPIResponse` there is the status to check if its success or failure.
- (void)addMemberToChannel:(NSString *)userId
             andChannelKey:(NSNumber * _Nullable)channelKey
        orClientChannelKey:(NSString * _Nullable)clientChannelKey
            withCompletion:(void(^)(NSError * _Nullable error, KBMAPIResponse * _Nullable response))completion;

/// Removes a member from a channel.
/// @param userId Pass the userId that wanted to remove from a channel.
/// @param channelKey Pass the channelkey or groupId that is required for removing a member from a channel.
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param completion It has error and KBMAPIResponse where you can check if an error is not nil else in KBMAPIResponse there is the status to check if its success or failure.
- (void)removeMemberFromChannel:(NSString *)userId
                  andChannelKey:(NSNumber * _Nullable)channelKey
             orClientChannelKey:(NSString * _Nullable)clientChannelKey
                 withCompletion:(void(^)(NSError * _Nullable error, KBMAPIResponse * _Nullable response))completion;

/// Leaves a member from channel.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @param userId Pass login userId here to leave from channel.
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param completion it has the error where you can check if an error is not nil the user is left from channel.
- (void)leaveChannel:(NSNumber * _Nullable)channelKey
           andUserId:(NSString *)userId
  orClientChannelKey:(NSString * _Nullable)clientChannelKey
      withCompletion:(void(^)(NSError * _Nullable error))completion;

/// Leaves a member from channel.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @param userId Pass loggedIn userId here to leave from channel.
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param completion It has error and KBMAPIResponse where you can check if an error is not nil else in KBMAPIResponse there is the status to check if its success or error.
- (void)leaveChannelWithChannelKey:(NSNumber * _Nullable)channelKey
                         andUserId:(NSString *)userId
                orClientChannelKey:(NSString * _Nullable)clientChannelKey
                    withCompletion:(void(^)(NSError * _Nullable error, KBMAPIResponse * _Nullable response))completion;

/// Deletes the channel from the server. Only the group admin can call this method.
/// @param channelKey If channelkey or groupId that is required for deleting a channel.
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param completion It has error and KBMAPIResponse where you can check if an error is not nil else in KBMAPIResponse there is the status to check if its success or failure.
- (void)deleteChannel:(NSNumber * _Nullable)channelKey
   orClientChannelKey:(NSString * _Nullable)clientChannelKey
       withCompletion:(void(^)(NSError * _Nullable error, KBMAPIResponse * _Nullable response))completion;

/// Updates the channel information like name, imageUrl, etc.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @param newName It's the new channel name of a channel.
/// @param imageURL Image URL will be channel profile image.
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param flag If your updating metadata pass YES or NO.
/// @param metaData It's extra information that can be updated or added to the channel.
/// @param childKeysList its list of child keys if you have created subgroups.
/// @param channelUsers NSMutableArray of KBMChannelUser object
///
/// KBMChannelUser *channelUser = [KBMChannelUser new];
/// channelUser.role = [NSNumber numberWithInt:1]; // USER = 0,ADMIN = 1,MODERATOR = 2,MEMBER = 3
/// channelUser.userId = userId; //user to update the role
/// NSMutableArray *channelUsers = [NSMutableArray new];
/// [channelUsers addObject:channelUser.dictionary];
/// @param completion It has the error where you can check if an error is not nil if it's updated successfully.
- (void)updateChannel:(NSNumber * _Nullable)channelKey
           andNewName:(NSString * _Nullable)newName
          andImageURL:(NSString * _Nullable)imageURL
   orClientChannelKey:(NSString * _Nullable)clientChannelKey
   isUpdatingMetaData:(BOOL)flag
             metadata:(NSMutableDictionary * _Nullable)metaData
          orChildKeys:(NSMutableArray * _Nullable)childKeysList
       orChannelUsers:(NSMutableArray * _Nullable)channelUsers
       withCompletion:(void(^)(NSError * _Nullable error))completion;

/// Updates channel information like name, imageUrl etc.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @param newName its new channel name of a channel.
/// @param imageURL Will be channel profile image.
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param flag If your updating metadata then pass YES or NO.
/// @param metaData It's extra information can be updated or added in channel.
/// @param childKeysList Its list of child keys if you have created subgroups.
/// @param channelUsers NSMutableArray of KBMChannelUser object.
/// @param completion It has error and KBMAPIResponse where you can check if error is not nil else in KBMAPIResponse there is status to check if its success or failed.
- (void)updateChannelWithChannelKey:(NSNumber * _Nullable)channelKey
                         andNewName:(NSString * _Nullable)newName
                        andImageURL:(NSString * _Nullable)imageURL
                 orClientChannelKey:(NSString * _Nullable)clientChannelKey
                 isUpdatingMetaData:(BOOL)flag
                           metadata:(NSMutableDictionary * _Nullable)metaData
                        orChildKeys:(NSMutableArray * _Nullable)childKeysList
                     orChannelUsers:(NSMutableArray * _Nullable)channelUsers
                     withCompletion:(void(^)(NSError * _Nullable error, KBMAPIResponse *_Nullable response))completion;

/// Updates a channel metadata.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param metaData Its extra information can be updated or added in channel.
/// @param completion it has an error where you can check if an error is not nil if it's updated successfully
- (void)updateChannelMetaData:(NSNumber * _Nullable)channelKey
           orClientChannelKey:(NSString * _Nullable)clientChannelKey
                     metadata:(NSMutableDictionary *)metaData
               withCompletion:(void(^)(NSError * _Nullable error))completion;

/// Marks the conversation as read in the channel.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @param completion It has a response and error if an error is a nil then Conversation is marked successfully
- (void)markConversationAsRead:(NSNumber *)channelKey withCompletion:(void (^)(NSString * _Nullable response , NSError * _Nullable error))completion;

/// Mutes or unmutes the channel for given `KBMMuteRequest`.
/// @param muteRequest Its an object of KBMMuteRequest where you need to pass channelKey and notificationTime its time you want to mute from or unmute.
/// KBMMuteRequest * muteRequest = [KBMMuteRequest new];
/// muteRequest.id = channelKey;
/// muteRequest.notificationAfterTime= notificationTime;
/// @param completion If an error is nil then check for KBMAPIResponse it has status where if its success or error.
- (void)muteChannel:(KBMMuteRequest *)muteRequest withCompletion:(void(^)(KBMAPIResponse * _Nullable response, NSError * _Nullable error))completion;

/// Creates a broadcast channel for given members userId array.
/// @param memberArray Pass member userId whom wanted to add in the broadcast channel.
/// @param metaData Its extra information can be added in channel.
/// @param completion If an error is nil, Then the channel is created successfully else some error in creating a channel.
- (void)createBroadcastChannelWithMembersList:(NSMutableArray *)memberArray
                                  andMetaData:(NSMutableDictionary * _Nullable)metaData
                               withCompletion:(void(^)(KBMChannel * _Nullable channel, NSError * _Nullable error))completion;

/// Gets the channels from the applications.
/// @param endTime Pass endTime to to fetch next set of channels.
/// @param completion If error is nil and channelInfoList count is > 0 then it has channel object in array.
- (void)getAllChannelsForApplications:(NSNumber *)endTime withCompletion:(void(^)(NSMutableArray * _Nullable channelInfoList, NSError * _Nullable error))completion;

/// Gets all the channels for the logged-in user.
/// @param completion will have a channel array of KBMChannel or will have an error in case of while fetching channels.
- (void)getListOfChannelWithCompletion:(void(^)(NSMutableArray * _Nullable channelArray, NSError * _Nullable error))completion;

/// Gets the list of channel information by Category.
/// @param category Pass category that you want to get the channels from category.
/// @param completion If an error is a nil and the channelInfoList count is > 0 then you have channels information in NSMutableArray its type is KBMChannel object.
- (void)getChannelListForCategory:(NSString *)category
                   withCompletion:(void(^)(NSMutableArray * _Nullable channelInfoList, NSError * _Nullable error))completion;

/// Gets the information of the channel from the local database.
/// @param channelKey Pass the channelkey or groupId that is required to get the channel information.
/// @return it returns KBMChannel object it has information of a channel.
- (KBMChannel * _Nullable)getChannelByKey:(NSNumber *)channelKey;

/// Gets the channel information for given client channel key from local database.
/// @param clientChannelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @return It wil return the channel information KBMChannel object.
- (KBMChannel * _Nullable)fetchChannelWithClientChannelKey:(NSString *)clientChannelKey;

/// Gets the group member's name to show in a navigation bar.
- (NSString *)userNamesWithCommaSeparatedForChannelkey:(NSNumber *)channelKey;

/// Returns a dictionary containing required key value pairs to turn off the notifications
/// for all the group action messages.
- (NSDictionary *)metadataToTurnOffActionMessagesNotifications;

/// Returns a dictionary containing required key-value pairs to hide all the action messages.
/// and turn off the notifications for them.
- (NSDictionary *)metadataToHideActionMessagesAndTurnOffNotifications;

/// Adds a mutliple users in group or channel.
/// @param channelKeys Pass channelKey or array of channelKeys.
/// @param channelUsers Pass userIds that wanted to add in channels or channel.
/// @param completion If error is not nil then member will be added succesful else if any error then it will have NSError.
- (void)addMultipleUsersToChannel:(NSMutableArray *)channelKeys
                     channelUsers:(NSMutableArray *)channelUsers
                    andCompletion:(void(^)(NSError * _Nullable error))completion;

/// Returns YES if the logged-in user is left from a channel or not otherwise NO.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @return it will return YES OR NO if the login member is channel or not
- (BOOL)isChannelLeft:(NSNumber *)channelKey;

/// Returns YES in case of channel is deleted otherwise NO.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @return it will return YES or NO if the channel is deleted or not.
+ (BOOL)isChannelDeleted:(NSNumber *)channelKey;

/// Used to check if the channel is muted or not.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @return it will return YES OR NO if the channel is muted or not.
+ (BOOL)isChannelMuted:(NSNumber *)channelKey;

/// Returns YES if channel is closed otherwise NO.
/// @param channelKey Pass the channel key can get from `KBMChannel` object as channel.key.
/// @return it will return YES OR NO if the conversation Closed in a channel.
+ (BOOL)isConversationClosed:(NSNumber *)channelKey;

/// This method is used to close the channel conversation.
/// @param channelKey Pass the channel key can get from KBMChannel object as channel.key.
/// @param completion If error is nil then the channel is closed else error in closing group.
- (void)closeGroupConverstion:(NSNumber *)channelKey withCompletion:(void(^)(NSError * _Nullable error))completion;

/// Gets the total unread count of channels.
/// @return NSNumber the total unread count of the channel.
- (NSNumber * _Nullable)getOverallUnreadCountForChannel;

/// Gets all channels for the logged-in user from the local database.
/// @return it will return the NSMutableArray of KBMChannel object.
- (NSMutableArray * _Nullable)getAllChannelList;

/// This method is internal, used to set channel unread cout to zero.
- (void)setUnreadCountZeroForGroupID:(NSNumber *)channelKey;

/// Gets channel information from channelKeys array or clientChannelKey array.
/// @param channelIds Pass channelKeys array to get the list of channel information.
/// @param clientChannelIds If you have list of clientChannelKey then pass to get channel information.
/// @param completion If error is nil and channelInfoList count is > 0 then you have channels information in NSMutableArray its type is KBMChannel object.
- (void)getChannelInfoByIdsOrClientIds:(NSMutableArray * _Nullable)channelIds
                    orClinetChannelIds:(NSMutableArray * _Nullable)clientChannelIds
                        withCompletion:(void(^)(NSMutableArray * _Nullable channelInfoList, NSError * _Nullable error))completion;
/// Adds or create contacts group with a user, type, and name.
/// @param contactsGroupId Pass the contactsGroupId which will be a unique string.
/// @param membersArray Pass members userId that you want to add.
/// @param groupType Pass type as 9 for contacts group.
/// @param completion If error is nil and KBMAPIResponse has status if its success then member is added in contacts group.
- (void)addMemberToContactGroupOfType:(NSString *)contactsGroupId
                          withMembers:(NSMutableArray *)membersArray
                       withGroupType :(short)groupType
                       withCompletion:(void(^)(KBMAPIResponse * _Nullable response, NSError * _Nullable error))completion;

/// Adds or create contacts group with default type.
/// @param contactsGroupId Pass contactsGroupId which will be unique string.
/// @param membersArray Pass members userId that you want to add.
/// @param completion If error is nil and KBMAPIResponse has status if its success then member is added in contacts group.
- (void)addMemberToContactGroup:(NSString *)contactsGroupId
                    withMembers:(NSMutableArray *)membersArray
                 withCompletion:(void(^)(KBMAPIResponse * _Nullable response, NSError * _Nullable error))completion;

/// Gets the members from contacts group with the type where it will have members id who are in this contacts group
/// @param contactGroupId Pass contactsGroupId which will be unique string.
/// @param groupType Pass type as 9 for contacts group.
/// @param completion if error is nil and KBMAPIResponse has status if its success then you will get members userId who are in contacts group.
- (void)getMembersFromContactGroupOfType:(NSString *)contactGroupId
                           withGroupType:(short)groupType
                          withCompletion:(void(^)(NSError * _Nullable error, KBMChannel * _Nullable channel)) completion;

/// Removes a member from the contacts group.
/// @param contactsGroupId Pass contactsGroupId which will be unique string.
/// @param userId Pass the user wanted to remove the member from the contacts group
/// @param completion If error is nil and KBMAPIResponse has status if its success then member is removed from contacts group.
- (void)removeMemberFromContactGroup:(NSString *)contactsGroupId
                         withUserId :(NSString *)userId
                      withCompletion:(void(^)(KBMAPIResponse * _Nullable response, NSError * _Nullable error))completion;

/// Removes a member from contacts group with type.
/// @param contactsGroupId Pass contactsGroupId which will be unique string.
/// @param groupType Pass type as 9 for contacts group.
/// @param userId Pass the userId that wanted to remove from contacts group.
/// @param completion if error is nil and KBMAPIResponse has status if its success then member is removed from contacts group else If the error is there then NSError will not be nil.
- (void)removeMemberFromContactGroupOfType:(NSString *)contactsGroupId
                             withGroupType:(short) groupType
                               withUserId :(NSString *)userId
                            withCompletion:(void(^)(KBMAPIResponse * _Nullable response, NSError * _Nullable error))completion;

/// Gets members from multiple contacts groups.
/// @param contactGroupIds Pass contactGroupIds to get the member userIds.
/// @param completion If error is nil it will have list of memberIds in channel/group else it will have NSError.
- (void)getMembersIdsForContactGroups:(NSArray *)contactGroupIds withCompletion:(void(^)(NSError * _Nullable error, NSArray * _Nullable membersArray)) completion;

/// This method is for internal purpose to get the members by channel name.
/// @param channelName Pass the client channel id or channel name to fetch the users from contacts group.
- (NSMutableArray * _Nullable)getListOfAllUsersInChannelByNameForContactsGroup:(NSString *)channelName;

/// Creates a new channel conversation.
///
/// @param channelName Pass the channel name that wanted to be set for the channel.
/// @param clientChannelKey Pass the clientChannelKey in case if the channelkey is not present else it will be nil.
/// @param memberArray Pass the members userId that wanted to add in a channel.
/// @param imageLink It's URL of channel image that wanted to see in the channel profile image.
/// @param type Pass type of group wanted to create.
/// Types of the group. PRIVATE = 1, PUBLIC = 2, OPEN = 6
/// @param metaData It's extra information can be added in channel.
/// @param adminUserId If you want to make any member as admin while creating then you can pass the userId of that member.
/// @param groupRoleUsers Pass roles of a member in a channel during creating channel.
/// @param completion f an error is nil then a group is created successfully it has KBMChannel information of channel else some error while creating if an error is not nil.
- (void)createChannel:(NSString *)channelName
   orClientChannelKey:(NSString * _Nullable)clientChannelKey
       andMembersList:(NSMutableArray *)memberArray
         andImageLink:(NSString * _Nullable)imageLink
          channelType:(short)type
          andMetaData:(NSMutableDictionary * _Nullable)metaData
            adminUser:(NSString * _Nullable)adminUserId
       withGroupUsers:(NSMutableArray * _Nullable)groupRoleUsers
       withCompletion:(void(^)(KBMChannel * _Nullable channel, NSError * _Nullable error))completion;

/// Updates unread count to zero and send notification with name `Update_unread_count` channelKey will be in object of notification and send the call back delegate using `KBMUpdatesDelegate`
/// @param channelKey Pass the channelKey or groupId you can get the key from `KBMChannel` object
/// @param delegate Set the `KBMUpdatesDelegate` for conversation read callback update.
/// @warning This is internal method.
- (void)updateConversationReadWithGroupId:(NSNumber *)channelKey withDelegate:(id<KBMUpdatesDelegate> _Nullable)delegate;

/// This method will update mute and unmute time local database.
/// @param notificationAfterTime Pass the time in milliseconds.
/// @param channelKey Pass the channelKey or groupId you can get the key from `KBMChannel` object.
- (NSError * _Nullable)updateMuteAfterTime:(NSNumber *)notificationAfterTime
                              andChnnelKey:(NSNumber *)channelKey;

/// For internal use only.
/// @param parentGroupKey Pass parent channelKey to get the channels.
/// @return It will return the NSMutableArray of KBMChannel object.
- (NSMutableArray * _Nullable)fetchChildChannelsWithParentKey:(NSNumber *)parentGroupKey;

/// For internal use only.
- (void)processChildGroups:(KBMChannel *)channel;

/// Adds child keys to the parent key.
/// @param childKeyList NSMutableArray list of child channelKeys to the parent wanted to add.
/// @param parentKey Pass the parent channelKey.
/// @param completion if error is nil then its added successfully.
- (void)addChildKeyList:(NSMutableArray *)childKeyList
           andParentKey:(NSNumber *)parentKey
         withCompletion:(void(^)(id _Nullable jsonResponse, NSError * _Nullable error))completion;

/// Removes the child keys from parent channelKey where it was added to the parent.
/// @param childKeyList NSMutableArray list of child channelKeys to the parent wanted to remove from parentKey.
/// @param parentKey Pass the parent channelKey.
/// @param completion If error is nil then its removed successfully.
- (void)removeChildKeyList:(NSMutableArray *)childKeyList
              andParentKey:(NSNumber *)parentKey
            withCompletion:(void(^)(id _Nullable jsonResponse, NSError * _Nullable error))completion;

/// Adds child keys to client Parent Key.
/// @param clientChildKeyList Llist of client child channelKeys to the parent wanted to add.
/// @param clientParentKey Pass the client parent channelKey
/// @param completion If an error is nil then its added successfully else error.
- (void)addClientChildKeyList:(NSMutableArray *)clientChildKeyList
                 andParentKey:(NSString *)clientParentKey
               withCompletion:(void(^)(id _Nullable jsonResponse, NSError * _Nullable error))completion;

/// Removes the child keys from client ParentKey where it was added to the child keys to parent.
/// @param clientChildKeyList NSMutableArray list of client child channelKeys to the parent wanted to remove from clientParentKey.
/// @param clientParentKey Pass the clientParentKey in case if you have channelParentKey.
/// @param completion if an error is nil then its removed successfully.
- (void)removeClientChildKeyList:(NSMutableArray *)clientChildKeyList
                    andParentKey:(NSString *)clientParentKey
                  withCompletion:(void(^)(id _Nullable jsonResponse, NSError * _Nullable error))completion;

/// This is an internal method for sync channels from the server
- (void)syncCallForChannel;

/// For internal use only.
///
/// @param delegate For real time updates callback will be triggered for channel update
/// @param completion On successful sync an `KBMChannelSyncResponse` will have `channelArray` of type `KBMChannel` otherwise, an error describing the failure of channel sync.
-(void)syncCallForChannelWithDelegate:(id<KBMUpdatesDelegate> _Nullable)delegate
                       withCompletion:(void (^)(KBMChannelSyncResponse * _Nullable response, NSError * _Nullable error))completion;

/// :nodoc:
- (void)callForChannelServiceForDBInsertion:(id)jsonResponse;

/// Gets the list of users userId from a channel by channelKey.
/// @param channelKey Pass the channelkey or groupId that is required to get the channel members userId.
/// @return it returns NSMutableArray has users who are in the channel.
- (NSMutableArray * _Nullable)getListOfAllUsersInChannel:(NSNumber *)channelKey;

/// This method is internal method used for saving channel members and channels in local database.
/// @param channelFeedsList Array of `KBMChannel` objects.
/// @param isFromMessageList Pass YES if the call is made for Message List else pass the NO for the Message thread conversation.
- (void)saveChannelUsersAndChannelDetails:(NSMutableArray <KBMChannel *>*)channelFeedsList calledFromMessageList:(BOOL)isFromMessageList;

/// For internal use only.
- (BOOL)checkAdmin:(NSNumber *)channelKey;

/// This internal method is used for saving channel object in local database.
/// @param channel Pass the `KBMChannel` object.
/// @param isFromMessageList Pass YES if the call is made for Message List else pass the NO for the Message thread conversation.
- (void)createChannelEntry:(KBMChannel * _Nullable)channel fromMessageList:(BOOL)isFromMessageList;

@end

NS_ASSUME_NONNULL_END
