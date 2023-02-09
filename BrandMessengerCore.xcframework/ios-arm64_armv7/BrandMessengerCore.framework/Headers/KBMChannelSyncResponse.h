//
//  KBMChannelSyncResponse.h
//  BrandMessengerCore
//
//  Created by devashish on 16/02/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import "KBMChannel.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// `KBMChannelSyncResponse` class is used for parasing the channel sync API response.
@interface KBMChannelSyncResponse : KBMAPIResponse

/// Array of channels that are fetched from sever it will be of type `KBMChannel` class.
@property (nonatomic, strong) NSMutableArray * _Nullable channelArray;

/// Will be used for init the JSON response string for parsing JSON data.
/// @param JSONString Pass the JSON response string.
- (instancetype)initWithJSONString:(NSString *)JSONString;

@end

NS_ASSUME_NONNULL_END
