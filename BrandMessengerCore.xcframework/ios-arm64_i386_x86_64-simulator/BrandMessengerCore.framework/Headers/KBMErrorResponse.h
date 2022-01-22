//
//  KBMErrorResponse.h
//  BrandMessengerCore
//
//  Created by Sunil on 17/11/21.
//  Copyright © 2021 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KBMJson.h"

NS_ASSUME_NONNULL_BEGIN

@interface KBMErrorResponse : NSObject

@property (nonatomic, strong) NSString * _Nullable errorCode;

@property (nonatomic, strong) NSString * _Nullable errorDescription;

@property (nonatomic, strong) NSString * _Nullable displayMessage;

- (id)initWithDictionary:(NSDictionary *)responseDictionary;

-(NSString * _Nullable)errorDescriptionMessage;

@end

NS_ASSUME_NONNULL_END
