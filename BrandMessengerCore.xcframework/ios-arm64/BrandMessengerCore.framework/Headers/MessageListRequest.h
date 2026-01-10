//
//  MessageListRequest.h
//  BrandMessengerCore
//
//  Created by Devashish on 29/02/16.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

static int const KBM_DEFAULT_MESSAGE_LIST_PAGE_SIZE = 50;

@interface MessageListRequest : NSObject

@property(nonatomic,retain) NSNumber * _Nullable channelKey;
@property(nonatomic) short channelType;
@property(nonatomic,retain) NSString * _Nullable startIndex;
@property(nonatomic,retain) NSString *pageSize;
@property(nonatomic) BOOL skipRead;
@property(nonatomic,retain) NSNumber * _Nullable endTimeStamp;
@property(nonatomic,retain) NSNumber * _Nullable startTimeStamp;
@property(nonatomic,retain) NSString * _Nullable userId;
@property(nonatomic,retain) NSNumber * _Nullable conversationId;

- (NSString *)getParamString;
- (BOOL)isFirstCall;

@end

NS_ASSUME_NONNULL_END
