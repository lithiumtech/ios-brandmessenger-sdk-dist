//
//  KBMAPIResponse.h
//  BrandMessengerCore
//
//  Created by devashish on 19/01/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "KBMErrorResponse.h"
#import "KBMJson.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Success response constant text.
extern NSString *const KBM_RESPONSE_SUCCESS;
/// Error response constant text.
extern NSString *const KBM_RESPONSE_ERROR;

/// `KBMAPIResponse` class is used for parsing the API response of Khoros.
@interface KBMAPIResponse : KBMJson

/// Status of the API call it will have `KBM_RESPONSE_SUCCESS` or `KBM_RESPONSE_ERROR`.
@property (nonatomic, strong) NSString * _Nullable status;

/// When the API call generated this wil have time in milliseconds.
@property (nonatomic, strong) NSNumber * _Nullable generatedAt;

/// This will have API response JSON.
@property (nonatomic, strong) id _Nullable response;

/// Actual JSON response string.
@property (nonatomic, strong) NSString * _Nullable actualresponse;

/// An error response in case of any error.
@property (nonatomic, strong) KBMErrorResponse * _Nullable errorResponse;

- (instancetype)initWithJSONString:(NSString *)JSONString;

@end

NS_ASSUME_NONNULL_END
