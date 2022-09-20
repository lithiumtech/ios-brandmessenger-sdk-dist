//
//  KBMChannel.h
//  BrandMessengerCore
//
//  Created by devashish on 28/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.

#import "KBMConversationProxy.h"
#import "KBMJson.h"
#import <CoreData/NSManagedObject.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// For internal use only.
static NSString *const KBM_CHANNEL_DEFAULT_MUTE = @"MUTE";
/// For internal use only.
static NSString *const KBM_CHANNEL_CONVERSATION_STATUS = @"CONVERSATION_STATUS";
/// For internal use only.
static NSString *const KBM_CATEGORY = @"AL_CATEGORY";
/// :nodoc:
static NSString *const KBM_CONTEXT_BASED_CHAT = @"AL_CONTEXT_BASED_CHAT";
/// :nodoc:
static NSString *const KBM_CONVERSATION_ASSIGNEE = @"CONVERSATION_ASSIGNEE";

/// Channel types
typedef enum
{
    /// :nodoc:
    VIRTUAL = 0,
    /// Only admin can add member in the channel.
    PRIVATE = 1,
    /// Any one can join in the channel.
    PUBLIC = 2,
    /// :nodoc:
    SELLER = 3,
    /// :nodoc:
    SELF = 4,
    /// One way broadcast messages in channel.
    BROADCAST = 5,
    /// Used for user can chat without joining an channel.
    OPEN = 6,
    /// Group of two same as one-to-one chat.
    GROUP_OF_TWO = 7,
    /// Categorizing contacts can be created based on common interests or activities the members of the channel are used for showing in contacts section.
    CONTACT_GROUP = 9,
    /// :nodoc:
    SUPPORT_GROUP = 10,
} CHANNEL_TYPE;

/// :nodoc:
typedef enum {
    /// :nodoc:
    ALL_CONVERSATION = 0,
    /// :nodoc:
    ASSIGNED_CONVERSATION = 1,
    /// :nodoc:
    CLOSED_CONVERSATION = 3
} CONVERSATION_CATEGORY;

/**
 * A channel is a medium for multiple users to send and receive messages to and from each other. It facilitates a channel conversation.
 *
 * Channels are identified by their channel `key` which is auto-generated or `clientChannelKey` which is your client channel key.
 *
 * Before a user can send messages to a channel, the channel needs to be created and the user needs to either join it or be added to it. Whether a user can join a channel or not depends on the channel `type`.
 *
 *  To create a channel and add users to it, refer to `-[BrandMessengerClient createChannelWithChannelInfo:withCompletion:]`.
 *
 *  To add a user to an existing channel (it allowed), refer to `-[BrandMessengerClient addMemberToChannelWithUserId:andChannelKey:orClientChannelKey:withCompletion:]`.
 *
 * To send a message to a channel refer to `-[BrandMessengerClient sendTextMessage:withCompletion:]`.
 */
@interface KBMChannel : KBMJson

/// Channel key is Identifier of Channel.
@property (nonatomic, strong) NSNumber *key;

/// Client channel key is Identifier of Channel.
///
/// If the client channel key is set during channel creation it will have its channel client key otherwise it will be a string of `key`.
@property (nonatomic, strong) NSString * _Nullable clientChannelKey;

/// Channel name.
@property (nonatomic, strong) NSString *name;

/// Channel image URL.
@property (nonatomic, strong) NSString * _Nullable channelImageURL;

/// Admin of the channel.
@property (nonatomic, strong) NSString * _Nullable adminKey;

/// Used for identifying the type of channel the types are `CHANNEL_TYPE`.
@property (nonatomic) short type;

/// Total number of users in channel.
@property (nonatomic, strong) NSNumber * _Nullable userCount;

/// Total unread count in channel.
@property (nonatomic, strong) NSNumber * _Nullable unreadCount;

/// For internal use only.
@property (nonatomic, strong) NSMutableArray * _Nullable membersName;

/// For internal use only.
@property (nonatomic, strong) NSMutableArray * _Nullable membersId;

/// :nodoc:
@property (nonatomic, strong) NSMutableArray * _Nullable removeMembers;

/// :nodoc:
@property (nonatomic, strong) NSNumber * _Nullable parentKey;

/// :nodoc:
@property (nonatomic, strong) NSString * _Nullable parentClientKey;

/// For internal use only.
@property (nonatomic, strong) NSMutableArray * _Nullable groupUsers;

/// :nodoc:
@property (nonatomic, strong) NSMutableArray * _Nullable childKeys;

/// To know when the channel is muted or unmuted it will have time in milliseconds otherwise nil.
@property (nonatomic, strong) NSNumber * _Nullable notificationAfterTime;

/// If channel is deleted it will be > 0 otherwise nil or 0.
@property (nonatomic, strong) NSNumber * _Nullable deletedAtTime;

/// Extra information in channel metadata.
@property (nonatomic, strong) NSMutableDictionary * _Nullable metadata;

/// For internal use only.
///
/// This is used to categorize the channel based on the metadata value for `CONVERSATION_CATEGORY`
@property (nonatomic) short category;

/// For internal use only.
- (id)initWithDictonary:(NSDictionary *)messageDictonary;

/// :nodoc:
- (NSNumber * _Nullable)getChannelMemberParentKey:(NSString *)userId;

/// Returns YES in case of notification are muted for current channel otherwise NO.
- (BOOL)isNotificationMuted;

/// :nodoc:
- (BOOL)isConversationClosed;

/// Returns YES in case of the channel is context-based chat otherwise NO.
- (BOOL)isContextBasedChat;

/// Returns YES in case of the channel is of type broadcast chat otherwise NO.
- (BOOL)isBroadcastGroup;

/// Returns YES in case of the channel is of type open otherwise NO.
- (BOOL)isOpenGroup;

/// Returns YES in case of the channel is of type group of two otherwise NO.
- (BOOL)isGroupOfTwo;

/// Returns YES in case of the channel is deleted otherwise NO.
- (BOOL)isDeleted;

/// Returns receiver member userId of group of two.
- (NSString * _Nullable)getReceiverIdInGroupOfTwo;

/// For internal use only.
- (NSMutableDictionary * _Nullable)getMetaDataDictionary:(NSString *)jsonString;

/// Returns YES in case of the channel is part of a given category otherwise NO.
- (BOOL)isPartOfCategory:(NSString *)category;

/// For internal use only.
+ (CONVERSATION_CATEGORY)getConversationCategory:(NSDictionary *)metadata;

/// :nodoc:
@property (nonatomic, copy) NSManagedObjectID *channelDBObjectId DEPRECATED_ATTRIBUTE;

/// :nodoc:
@property (nonatomic, strong) KBMConversationProxy *conversationProxy DEPRECATED_ATTRIBUTE;

@end

NS_ASSUME_NONNULL_END
