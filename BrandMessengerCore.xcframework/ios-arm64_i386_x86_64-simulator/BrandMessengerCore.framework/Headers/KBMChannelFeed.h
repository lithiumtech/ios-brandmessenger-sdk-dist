//
//  KBMChannelFeed.h
//  BrandMessengerCore
//
//  Created by devashish on 28/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMChannel.h"
#import "KBMJson.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMChannelFeed` class is used for parsing the Channel JSON object.
@interface KBMChannelFeed : KBMJson

/// This will have array of `KBMChannel` objects
@property (nonatomic) NSMutableArray <KBMChannel *> * _Nullable channelFeedsList;

/// This will have in case of there are any conversation objects.
@property (nonatomic) NSMutableArray <KBMChannel *> * _Nullable conversationProxyList;

@end
NS_ASSUME_NONNULL_END
