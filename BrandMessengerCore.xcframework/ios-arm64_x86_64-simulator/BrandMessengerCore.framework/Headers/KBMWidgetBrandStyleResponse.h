//
//  KBMWidgetBrandStyleResponse.h
//  BrandMessengerCore
//
//  Created by Sunil K on 01/03/23.
//

#import "KBMLanguageVariantModel.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMWidgetBrandStyleResponse : NSObject<NSCoding>

@property(nonatomic, strong) NSString * _Nullable brandColor;

@property(nonatomic, strong) NSString * _Nullable conversationColor;

@property(nonatomic, strong) NSString * _Nullable actionColor;

@property(nonatomic, strong) NSString * _Nullable headerText;

@property(nonatomic, strong) NSString * _Nullable businessName;

@property(nonatomic, strong) NSString * _Nullable businessIconUrl;

@property(nonatomic, strong) NSString * _Nullable introductionText;

@property(nonatomic) BOOL fixedIntroPane;

@property(nonatomic, strong) NSMutableArray * _Nullable headerTextLanguageVariants;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

- (NSMutableArray<KBMLanguageVariantModel *> * _Nullable)getHeaderLanguageVariants;

@end

NS_ASSUME_NONNULL_END
