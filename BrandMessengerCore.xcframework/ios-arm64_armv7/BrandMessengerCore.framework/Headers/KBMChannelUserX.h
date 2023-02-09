//
//  KBMChannelUserX.h
//  BrandMessengerCore
//
//  Created by devashish on 28/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"
#import <CoreData/NSManagedObject.h>
#import <Foundation/Foundation.h>

/// List of role types for channel members.
typedef enum {
    /// User role
    USER = 0,
    /// Admin of the channel.
    ADMIN = 1,
    /// Moderator of the channel.
    MODERATOR = 2,
    /// Memeber of the channel.
    MEMBER = 3
} ROLE_TYPE;

/// `KBMChannelUserX` class is used for channel member details.
@interface KBMChannelUserX : KBMJson

/// Channel member userId
@property (nonatomic, strong) NSString *userKey;

/// Channel key or groupId
@property (nonatomic, strong) NSNumber *key;

/// :nodoc:
@property (nonatomic) short status;

/// :nodoc:
@property (nonatomic, strong) NSNumber *unreadCount;

/// Parent channel key for iderntifying the parent channel.
@property (nonatomic, strong) NSNumber *parentKey;

/// Role of the channel member.
@property (nonatomic, strong) NSNumber *role;

/// Init for the JSON NSDictionary for creating an object of `KBMChannelUserX`.
/// @param messageDictonary Pass JSON dctionary for creating object.
- (id)initWithDictonary:(NSDictionary *)messageDictonary;

/// To identify the channel member is Admin.
/// @return YES in case of Admin otherwise NO in case of not an admin user.
- (BOOL)isAdminUser;

@end
