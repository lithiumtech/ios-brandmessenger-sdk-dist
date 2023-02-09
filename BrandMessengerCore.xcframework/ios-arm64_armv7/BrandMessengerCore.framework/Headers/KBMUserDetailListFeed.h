//
//  KBMUserDetailListFeed.h
//  BrandMessengerCore
//
//  Created by Abhishek Thapliyal on 10/13/16.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"

NS_ASSUME_NONNULL_BEGIN

/// `KBMUserDetailListFeed` request for fetching User detail.
@interface KBMUserDetailListFeed : KBMJson

/// Seter method for array of userIds.
@property (nonatomic, strong) NSMutableArray *userIdList;

/// Setter method of array of userIds.
/// @param array Array of string userIds.
- (void)setArray:(NSMutableArray *)array;

@end

NS_ASSUME_NONNULL_END
