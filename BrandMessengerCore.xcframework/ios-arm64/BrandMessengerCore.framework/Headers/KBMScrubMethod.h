//
//  KBMScrubMethod.h
//  BrandMessengerCore
//
//  Created by Sunil K on 20/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const KBM_LITERAL_KEY;
extern NSString *const KBM_LAST_FOUR_KEY;
extern NSString *const KBM_FIRST_FOUR_KEY;

@interface KBMScrubMethod : NSObject

@property(nonatomic, strong) NSString *type;

@property(nonatomic, strong) NSString * _Nullable replacement;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
