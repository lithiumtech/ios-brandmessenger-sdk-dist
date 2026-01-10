//
//  DB_CHANNEL_USER_X.h
//  BrandMessengerCore
//
//  Created by devashish on 28/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import <CoreData/CoreData.h>

/// `DB_CHANNEL_USER_X` is DB class is used for storing the group members in core database which will have details of member in channel.
@interface DB_CHANNEL_USER_X : NSManagedObject

/// Channel key or group id used for identifying the group or channel the user belong to;
@property (nonatomic, retain) NSNumber *channelKey;

/// Parent group key used for identifying the parent group.
@property (nonatomic, retain) NSNumber *parentGroupKey;

/// UserId of the channel or group member.
@property (nonatomic, retain) NSString *userId;

/// :nodoc:
@property (nonatomic) short status;

/// :nodoc:
@property (nonatomic, retain) NSNumber *unreadCount;

/// Used for identifying the role of the member in group or channel.
@property (nonatomic,retain) NSNumber *role;

@end
