//
//  KBMSearchResultCache.h
//  BrandMessengerCore
//
//  Created by Shivam Pokhriyal on 02/07/19.
//  Copyright © 2019 Khoros, LLC. All rights reserved.
//

#import "KBMChannel.h"
#import "KBMContact.h"
#import "KBMUserDetail.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// `KBMSearchResultCache` class is used for storing the `KBMChannel` and `KBMUserDetail` object.
@interface KBMSearchResultCache : NSObject

/// Instance method of `KBMSearchResultCache`.
+ (KBMSearchResultCache *)shared;

/// Used for storing the array of `KBMChannel` objects.
/// @param channels Pass the array of `KBMChannel` objects.
- (void)saveChannels:(NSMutableArray<KBMChannel *> * _Nullable)channels;

/// Used for storing the array of `KBMUserDetail` objects.
/// @param userDetails Pass the array of `KBMUserDetail` objects.
- (void)saveUserDetails:(NSMutableArray<KBMUserDetail *> * _Nullable)userDetails;

/// Used for fetching the `KBMChannel` object from `KBMSearchResultCache`.
/// @param key Pass the channelKey or groupId.
- (KBMChannel * _Nullable)getChannelWithId:(NSNumber *)key;

/// Used for fetching the `KBMContact` object from `KBMSearchResultCache`.
/// @param key Pass the userId to fetch the contact.
- (KBMContact * _Nullable)getContactWithId:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
