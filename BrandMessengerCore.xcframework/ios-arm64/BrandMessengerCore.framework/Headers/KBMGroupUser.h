//
//  KBMGroupUser.h
//  BrandMessengerCore
//
//  Created by Sunil on 14/02/18.
//  Copyright © 2018 Khoros, LLC. All rights reserved.
//
#import "KBMJson.h"
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// `KBMGroupUser` is used for creating channel members with the role during channel creation.
@interface KBMGroupUser : KBMJson

/// Set the member userId.
@property (nonatomic, strong) NSString *userId;

/// Set the member role these are roles for the member in the channel.
///
/// The roles are:
///
/// USER = 0,
/// ADMIN = 1,
/// MODERATOR = 2,
/// MEMBER = 3
@property (nonatomic, strong) NSNumber *groupRole;

/// Passing the JSON Dictionary.
/// @param messageDictonary Pass the JSON Dictionary.
- (id)initWithDictonary:(NSDictionary *)messageDictonary;

@end

NS_ASSUME_NONNULL_END
