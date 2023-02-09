//
//  KBMChannelOfTwoMetaData.h
//  BrandMessengerCore
//
//  Created by Mihir on 02/05/18.
//  Copyright © 2018 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMChannelOfTwoMetaData : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString * _Nullable price;
@property (nonatomic, strong) NSString *link;
- (NSMutableDictionary *)toDict:(KBMChannelOfTwoMetaData *)metadata;
@end

NS_ASSUME_NONNULL_END
