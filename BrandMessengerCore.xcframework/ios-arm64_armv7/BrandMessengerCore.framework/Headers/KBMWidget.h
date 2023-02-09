//
//  KBMWidget.h
//  Pods
//
//  Created by Sunil K on 15/11/22.
//

#import "KBMDisplayCondition.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMWidget : NSObject

@property(nonatomic, strong) NSString * _Nullable widgetHash;

@property(nonatomic, strong) NSMutableArray <KBMDisplayCondition *> * _Nullable displayConditions;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;
@end

NS_ASSUME_NONNULL_END
