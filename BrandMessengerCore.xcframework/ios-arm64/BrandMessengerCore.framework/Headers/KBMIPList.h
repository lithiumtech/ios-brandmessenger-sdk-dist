//
//  KBMIPList.h
//  BrandMessengerCore
//
//  Created by Sunil K on 20/02/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMIPList : NSObject

@property(nonatomic, strong) NSArray * _Nullable ipAddresses;

@property(nonatomic, strong) NSArray * _Nullable countries;

@property(nonatomic) BOOL enabled;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
