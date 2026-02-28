//
//  KBMRedactionConfiguration.h
//  BrandMessengerCore
//
//  Created by Sunil K on 20/12/22.
//

#import <Foundation/Foundation.h>
#import "KBMRedactionGroup.h"

NS_ASSUME_NONNULL_BEGIN

@interface KBMRedactionConfiguration : NSObject

@property(nonatomic, strong) KBMRedactionGroup * _Nullable redactionGroup;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;
@end

NS_ASSUME_NONNULL_END
