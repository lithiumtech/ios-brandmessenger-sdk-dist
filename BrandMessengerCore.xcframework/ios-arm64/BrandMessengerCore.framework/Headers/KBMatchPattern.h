//
//  KBMatchPattern.h
//  BrandMessengerCore
//
//  Created by Sunil K on 20/12/22.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMatchPattern : NSObject

@property(nonatomic, strong) NSString *type;

@property(nonatomic, strong) NSString * _Nullable preprocessedPattern;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;
@end

NS_ASSUME_NONNULL_END
