//
//  KBMChannelFeedResponse.h
//  BrandMessengerCore
//
//  Created by Nitin on 20/10/17.
//  Copyright © 2017 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import "KBMChannel.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMChannelFeedResponse` class is used for channel information response parsing.
@interface KBMChannelFeedResponse : KBMAPIResponse

/// `KBMChannel` will be set once the channel is fetched successfully.
@property (nonatomic, strong) KBMChannel * _Nullable channel;

/// Used for parsing a JSON string.
/// @param JSONString Pass the JSON String.
- (instancetype)initWithJSONString:(NSString *)JSONString;

@end

NS_ASSUME_NONNULL_END
