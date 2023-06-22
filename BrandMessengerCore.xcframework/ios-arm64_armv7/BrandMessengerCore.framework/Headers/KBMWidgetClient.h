//
//  KBMWidgetClient.h
//  BrandMessengerCore
//
//  Created by Sunil K on 15/11/22.
//

#import "KBMDisplayCondition.h"
#import <Foundation/Foundation.h>
#import "KBMWidgetBrandStyleResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface KBMWidgetClient : NSObject

/// To get all Display Conditions from Chat Widget configuration.
- (void)getAllDisplayConditions:(void (^)(NSMutableArray <KBMDisplayCondition *> * _Nullable displayConditions, NSError * _Nullable error))completion;

/// To know all Display Conditions from Chat Widget configuration are met.
- (void)isAllDisplayConditionsMet:(void (^)(BOOL hasAllDisplayConditionsMet, NSError * _Nullable error))completion;

/// To know widget hash enable or not.
- (void)isWidgetHashEnabled:(void (^)(BOOL isWidgetHashEnabled, NSError * _Nullable error))completion;

/// Internal Widget Configuration Response API
- (void)getWidgetConfigurationResponse:(BOOL)shouldGetAppIdFromConfig withCompletion:(void (^)(KBMWidgetConfigurationResponse * _Nullable widgetConfigurationResponse, NSError * _Nullable error))completion;

/// To know device IP address or country code is allowed or not.
- (void)isDeviceGeoIPAllowedWithCompletion:(void (^)(BOOL isDeviceGeoIPAllowed, NSError * _Nullable error))completion;

/// Throttling disaply condition of care chat widget.
/// - Parameter completion:Check for error is nil and then use the `shouldThrottle` flag to check  is Throttling is applied for the user then you can add logic to disable the chat button.
- (void)shouldThrottleWithCompletion:(void (^)(BOOL shouldThrottle, NSError * _Nullable error))completion;

/// Internal Widget Configuration Brand Style Response API
- (void)getWidgetConfigurationBrandStyleWithCompletion:(void (^)(KBMWidgetBrandStyleResponse * _Nullable widgetBrandStyleResponse, NSError * _Nullable error))completion;
@end

NS_ASSUME_NONNULL_END
