//
//  KBMRedactionGroup.h
//  BrandMessengerCore
//
//  Created by Sunil K on 20/12/22.
//
#import <Foundation/Foundation.h>
#import "KBMScrubMethod.h"
#import "KBMatchPattern.h"

NS_ASSUME_NONNULL_BEGIN

@interface KBMRedactionGroup : NSObject

@property(nonatomic) BOOL enabled;

@property(nonatomic, strong) NSMutableArray<KBMatchPattern *> * _Nullable matchPatterns;

@property(nonatomic, strong) KBMScrubMethod * _Nullable scrubMethod;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
