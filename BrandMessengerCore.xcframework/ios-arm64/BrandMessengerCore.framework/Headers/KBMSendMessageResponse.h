//
//  KBMSendMessageResponse.h
//  BrandMessengerCore
//
//  Created by Devashish on 06/11/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

/*
 
 {"messageKey":"28c47e68-e6a3-4a6d-b0db-4658d6e0aa18","createdAt":1446820801594}
 */
#import "KBMJson.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMSendMessageResponse : KBMJson

@property (nonatomic, copy) NSString *messageKey;

@property (nonatomic, copy) NSNumber *createdAt;

@property (nonatomic, copy) NSNumber * _Nullable conversationId;

- (BOOL)isSuccess;

@end

NS_ASSUME_NONNULL_END
