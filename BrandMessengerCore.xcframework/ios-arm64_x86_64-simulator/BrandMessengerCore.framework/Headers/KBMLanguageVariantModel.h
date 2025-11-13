//
//  KBMLanguageVariantModel.h
//  BrandMessengerCore
//
//  Created by Sunil K on 08/05/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMLanguageVariantModel : NSObject

@property(nonatomic, strong) NSString * _Nullable languageCode;

@property(nonatomic, strong) NSString * _Nullable translation;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
