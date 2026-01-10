//
//  KBMLastSeenSyncFeed.h
//  BrandMessengerCore
//
//  Created by Devashish on 19/12/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"
#import "KBMUserDetail.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMLastSeenSyncFeed` class is used
@interface KBMLastSeenSyncFeed : KBMJson

/// Array of the `KBMUserDetail` objects.
@property(nonatomic) NSMutableArray <KBMUserDetail *> * _Nullable lastSeenArray;

/// This method is used for parsing the Last seen user status.
/// @param lastSeenResponse Pass the JSON string response.
- (instancetype)initWithJSONString:(NSString * _Nullable)lastSeenResponse;

/// This method is used for populating the `KBMUserDetail` JSON Dictionary.
/// @param jsonString Pass the Array of Dictionary.
- (void)populateLastSeenDetail:(NSMutableArray * _Nullable)jsonString;

@end

NS_ASSUME_NONNULL_END
