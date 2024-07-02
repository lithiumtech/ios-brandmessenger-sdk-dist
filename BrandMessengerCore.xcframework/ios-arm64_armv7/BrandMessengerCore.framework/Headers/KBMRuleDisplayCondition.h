//
//  KBMRuleDisplayCondition.h
//  BrandMessengerCore
//
//  Created by Sunil K on 19/04/24.
//

#import "KBMDisplayCondition.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMRuleDisplayCondition : NSObject

@property(nonatomic, strong) NSString * _Nullable ruleId;

@property(nonatomic, strong) NSMutableArray <KBMDisplayCondition *> * _Nullable displayConditions;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END

