//
//  KBMDisplayConditionsResponse.h
//  BrandMessengerCore
//
//  Created by Sunil K on 20/02/23.
//

#import <Foundation/Foundation.h>
#import "KBMIPList.h"

NS_ASSUME_NONNULL_BEGIN

@interface KBMDisplayConditionsResponse : NSObject

@property(nonatomic, strong) KBMIPList * _Nullable ipWhitelist;

@property(nonatomic, strong) KBMIPList * _Nullable ipBlacklist;

@property(nonatomic, strong) NSDictionary * _Nullable throttle;

@property(nonatomic) BOOL enabled;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
