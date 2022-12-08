//
//  KBMUserOpenConversationResponse.h
//  BrandMessengerCore
//
//  Created by Sunil K on 14/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Used for storing the `KBMUserOpenConversationResponse` object in Userdefaults.
@interface KBMUserOpenConversationResponse : NSObject<NSCoding>

@property (nonatomic) BOOL hasOpenCases;

@property (nonatomic, strong) NSNumber * _Nullable checkAfterTimestamp;

@end

NS_ASSUME_NONNULL_END
