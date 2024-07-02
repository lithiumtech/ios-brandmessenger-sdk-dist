//
//  KBMWidget.h
//  Pods
//
//  Created by Sunil K on 15/11/22.
//

#import "KBMDisplayCondition.h"
#import <Foundation/Foundation.h>
#import "KBMRuleDisplayCondition.h"

NS_ASSUME_NONNULL_BEGIN

@interface KBMWidget : NSObject

@property(nonatomic, strong) NSString * _Nullable widgetHash;

@property(nonatomic, strong) NSMutableArray <KBMDisplayCondition *> * _Nullable displayConditions;

@property(nonatomic, strong) NSMutableArray <KBMRuleDisplayCondition *> * _Nullable ruleDisplayConditions;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;
@end

NS_ASSUME_NONNULL_END
