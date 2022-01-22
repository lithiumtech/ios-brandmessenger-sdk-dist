//
//  KBMContactsResponse.h
//  BrandMessengerCore
//
//  Created by devashish on 25/04/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"

NS_ASSUME_NONNULL_BEGIN
/// `KBMContactsResponse` class is used for parsing the user details response JSON.
@interface KBMContactsResponse : KBMJson

/// Last fetched time of contact JSON.
@property (nonatomic, strong) NSNumber * _Nullable lastFetchTime;

/// :nodoc:
@property (nonatomic, strong) NSNumber * _Nullable totalUnreadCount;

/// Array of `KBMUserDetail` objects.
@property (nonatomic, strong) NSMutableArray * _Nullable userDetailList;

@end

NS_ASSUME_NONNULL_END
