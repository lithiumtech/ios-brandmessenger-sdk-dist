//
//  KBMDisplayCondition.h
//  Pods
//
//  Created by Sunil K on 15/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMDisplayCondition : NSObject

@property(nonatomic, strong) NSString *typeId;

@property(nonatomic) BOOL satisfied;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;
@end

NS_ASSUME_NONNULL_END
