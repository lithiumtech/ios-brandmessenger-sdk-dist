//
//  KBMConversationCreateResponse.h
//  BrandMessengerCore
//
//  Created by Divjyot Singh on 04/03/16.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import "KBMConversationProxy.h"
#import <Foundation/Foundation.h>

/// `KBMConversationCreateResponse` class is used for context based conversation create response parsing.
@interface KBMConversationCreateResponse : KBMAPIResponse

/// This will be set from `initWithJSONString` method.
@property (nonatomic, strong) KBMConversationProxy *alConversationProxy;

/// This method is used for parsing the conversation create JSON string
/// @param JSONString Pass the JSON response string.
- (instancetype)initWithJSONString:(NSString *)JSONString;
@end
