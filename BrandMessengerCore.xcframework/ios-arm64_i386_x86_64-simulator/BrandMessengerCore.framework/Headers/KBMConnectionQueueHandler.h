//
//  KBMConnectionQueueHandler.h
//  BrandMessengerCore
//
//  Created by shaik riyaz on 26/08/15.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface KBMConnectionQueueHandler : NSObject

@property (nonatomic,retain) NSMutableArray * _Nullable mConnectionsArray;

+ (KBMConnectionQueueHandler *)sharedConnectionQueueHandler;

- (NSMutableArray *_Nullable)getCurrentConnectionQueue;

@end
NS_ASSUME_NONNULL_END
