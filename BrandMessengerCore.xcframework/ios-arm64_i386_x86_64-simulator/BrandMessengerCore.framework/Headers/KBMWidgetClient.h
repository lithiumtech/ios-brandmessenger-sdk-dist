//
//  KBMWidgetClient.h
//  BrandMessengerCore
//
//  Created by Sunil K on 15/11/22.
//

#import "KBMDisplayCondition.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMWidgetClient : NSObject

/// To get all Display Conditions from Chat Widget configuration.
- (void)getAllDisplayConditions:(void (^)(NSMutableArray <KBMDisplayCondition *> * _Nullable displayConditions, NSError * _Nullable error))completion;

/// To know all Display Conditions from Chat Widget configuration are met.
- (void)isAllDisplayConditionsMet:(void (^)(BOOL hasAllDisplayConditionsMet, NSError * _Nullable error))completion;

/// To know widget hash enable or not.
- (void)isWidgetHashEnabled:(void (^)(BOOL isWidgetHashEnabled, NSError * _Nullable error))completion;

// Internal General Configuration API
-(void)getWidgetGeneralConfiguration:(BOOL)shouldGetAppIdFromConfig withCompletion:(void (^)(KBMWidgetConfigurationResponse * _Nullable widgetConfigurationResponse, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
