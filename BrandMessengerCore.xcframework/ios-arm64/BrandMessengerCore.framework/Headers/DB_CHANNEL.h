//
//  DB_CHANNEL.h
//  BrandMessengerCore
//
//  Created by devashish on 28/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import <CoreData/CoreData.h>

/// `DB_CHANNEL` is DB class is used for storing the group or channel details in core database.
@interface DB_CHANNEL : NSManagedObject

/// This will be used for identifying the admin of group or channel which is set during the creation of group.
@property (nonatomic, retain) NSString *adminId;

/// Name of the channel or group.
@property (nonatomic, retain) NSString *channelDisplayName;

/// Channel image url.
@property (nonatomic, retain) NSString *channelImageURL;

/// GroupId or channelKey which is used for identifying based on this.
@property (nonatomic, retain) NSNumber *channelKey;

/// Parent channelKey that current group belongs.
@property (nonatomic, retain) NSNumber *parentGroupKey;

/// Parent client groupId that current group belongs.
@property (nonatomic, retain) NSString *parentClientGroupKey;

/// Own client group id which is set during the creation of channel.
@property (nonatomic, retain) NSString *clientChannelKey;

/// To check the group type.
@property (nonatomic) short type;

/// Number members in channel.
@property (nonatomic, strong) NSNumber *userCount;

/// Unread count of channel or group.
@property (nonatomic, strong) NSNumber *unreadCount;

/// Returns true in case of user is left from channel or group.
@property (nonatomic) BOOL isLeft;

/// This will give the channel as mutted for till the time.
@property (nonatomic, strong) NSNumber *notificationAfterTime;

/// To identifying the channel or group is deleted or not.
/// If the `deletedAtTime` is > 0 then channel is deleted else its not deleted.
@property (nonatomic, strong) NSNumber *deletedAtTime;

/// It gives the meta data of channel.
/// Its an extra information which is stored in channel.
@property (nonatomic, retain) NSString *metadata;

/// Used for identifying the channel category.
@property (nonatomic) short category;

@end
