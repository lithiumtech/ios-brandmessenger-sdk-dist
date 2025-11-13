//
//  KBMUserBlockResponse.h
//  BrandMessengerCore
//
//  Created by devashish on 07/03/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import "KBMUserBlocked.h"

NS_ASSUME_NONNULL_BEGIN

@interface KBMUserBlockResponse : KBMAPIResponse

@property(nonatomic, strong) NSMutableArray * _Nullable blockedToUserList;
@property(nonatomic, strong) NSMutableArray * _Nullable blockedByList;

@property(nonatomic, strong) NSMutableArray <KBMUserBlocked *> * _Nullable blockedUserList;
@property(nonatomic, strong) NSMutableArray <KBMUserBlocked *> * _Nullable blockByUserList;

- (instancetype)initWithJSONString:(NSString *)JSONString;

@end

NS_ASSUME_NONNULL_END
