//
//  KBMChannelCreateResponse.h
//  BrandMessengerCore
//
//  Created by devashish on 12/02/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import "KBMChannel.h"
#import <Foundation/Foundation.h>

/// `KBMChannelCreateResponse` class is used for parsing the JSON response of Channel create.
@interface KBMChannelCreateResponse : KBMAPIResponse

/// This channel is set from `initWithJSONString` method can be accessed once the JSON is passed.
@property (nonatomic, strong) KBMChannel *channel;

/// This method is used for parsing the Channel create response.
/// @param JSONString Pass the JSON  response string.
- (instancetype)initWithJSONString:(NSString *)JSONString;

@end
