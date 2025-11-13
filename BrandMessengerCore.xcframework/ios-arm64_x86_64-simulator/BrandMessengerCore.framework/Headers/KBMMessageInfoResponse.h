//
//  KBMMessageInfoResponse.h
//  BrandMessengerCore
//
//  Created by devashish on 17/03/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import "KBMMessageInfo.h"

NS_ASSUME_NONNULL_BEGIN
/// `KBMMessageInfoResponse` class is used for parsing the Message information JSON response.
@interface KBMMessageInfoResponse : KBMAPIResponse

/// This will be set from `initWithJSONString` can be access array of `KBMMessageInfo` objects.
@property(nonatomic, strong) NSMutableArray <KBMMessageInfo *> * _Nullable msgInfoList;

/// This method is used for parsing JSON string response.
/// @param JSONString Pass the JSON string response.
- (instancetype)initWithJSONString:(NSString *)JSONString;

@end
NS_ASSUME_NONNULL_END
