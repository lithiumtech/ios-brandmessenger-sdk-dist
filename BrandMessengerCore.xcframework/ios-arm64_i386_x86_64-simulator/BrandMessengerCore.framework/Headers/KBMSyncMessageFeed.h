//
//  KBMSyncMessageFeed.h
//  BrandMessengerCore
//
//  Created by Devashish on 20/09/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMSyncMessageFeed : KBMJson

@property(nonatomic,copy) NSNumber * _Nullable lastSyncTime;

@property(nonatomic,copy) NSString * _Nullable currentSyncTime;

@property(nonatomic) NSMutableArray * _Nullable messagesList;

@property(nonatomic) NSMutableArray * _Nullable deliveredMessageKeys;

@property(nonatomic, assign) BOOL sent;

@property(nonatomic, assign) BOOL isRegisterdIdInvalid;

@end

NS_ASSUME_NONNULL_END
