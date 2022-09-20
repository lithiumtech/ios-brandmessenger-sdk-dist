//
//  KBMSearchRequest.h
//  BrandMessengerCore
//
//  Created by apple on 05/09/19.
//  Copyright © 2019 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMSearchRequest : NSObject

@property(nonatomic,retain) NSNumber * _Nullable channelKey;
@property(nonatomic,retain) NSString * _Nullable userId;
@property(nonatomic,retain) NSNumber * _Nullable groupType;
@property(nonatomic,retain) NSString * searchText;

- (NSString * _Nullable)getParamString;

@end

NS_ASSUME_NONNULL_END
