//
//  KBMWidgetConfigurationResponse.h
//  BrandMessengerCore
//
//  Created by Sunil K on 17/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMWidgetConfigurationResponse : NSObject<NSCoding>

@property(nonatomic) BOOL enabled;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
