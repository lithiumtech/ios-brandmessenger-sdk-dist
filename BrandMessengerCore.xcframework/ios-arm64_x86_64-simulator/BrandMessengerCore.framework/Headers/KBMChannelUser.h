//
//  KBMChannelUser.h
//  BrandMessengerCore
//
//  Created by Adarsh Kumar Mishra on 12/8/16.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"

NS_ASSUME_NONNULL_BEGIN

/// `KBMChannelUser` this class is used for creating channel members with the role during channel creation.
@interface KBMChannelUser : KBMJson

/// Sets the member role these are roles for the member in the channel.
///
/// Roles are: USER = 0,
/// ADMIN = 1,
/// MODERATOR = 2,
/// MEMBER = 3
@property (nonatomic, strong) NSNumber * _Nullable role;

/// Sets the member userId.
@property (nonatomic, strong) NSString * _Nullable userId;

/// Parent group key is the parent channel key.
@property (nonatomic, strong) NSNumber * _Nullable parentGroupKey;

/// Passing the JSON Dictionary.
/// @param messageDictonary Pass the JSON Dictionary.
- (id)initWithDictonary:(NSDictionary *)messageDictonary;

@end

NS_ASSUME_NONNULL_END
