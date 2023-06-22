//
//  KBMWidgetConfigurationResponse.h
//  BrandMessengerCore
//
//  Created by Sunil K on 17/11/22.
//

#import <Foundation/Foundation.h>
#import "KBMRedactionConfiguration.h"
#import "KBMDisplayConditionsResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface KBMWidgetConfigurationResponse : NSObject<NSCoding>

@property(nonatomic) BOOL enabled;

@property(nonatomic, strong) NSDictionary * _Nullable generalConfiguration;

@property(nonatomic, strong) NSMutableArray * _Nullable redactionConfiguration;

@property(nonatomic, strong) NSDictionary * _Nullable displayConditions;

@property(nonatomic, strong) NSDictionary * _Nullable customerActions;

@property(nonatomic, strong) NSString * _Nullable brandStyleId;

- (BOOL)isImageUploadEnabled;

- (BOOL)isFileUploadEnabled;

- (BOOL)isShareLocationEnabled;

+ (BOOL)isAllFileFormatSupported;

- (BOOL)isConfigurationResponseExist;

- (BOOL)isPrintTranscriptEnabled;

/// Array of supported file format.
- (NSArray * _Nullable)getSupportedFileExtensions;

/// Use this to get the array of `KBMRedactionConfiguration`.
-(NSMutableArray<KBMRedactionConfiguration *> * _Nullable)getRedactionConfigurations;

- (KBMDisplayConditionsResponse *)getDisplayConditionsResponse;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
