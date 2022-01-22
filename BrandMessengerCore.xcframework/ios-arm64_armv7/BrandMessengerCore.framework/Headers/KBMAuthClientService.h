//
//  KBMAuthClientService.h
//  BrandMessengerCore
//
//  Created by Sunil on 15/06/20.
//  Copyright © 2020 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMAuthClientService` class is has methods for JWT token.
/// @warning `KBMAuthClientService` class used only for internal purposes.
@interface KBMAuthClientService : NSObject

/// Used for refreshing JWT auth token from server.
/// @param completion An `KBMAPIResponse` will have status `KBM_RESPONSE_SUCCESS` for successful otherwise, an error describing the refresh authtoken failure.
/// @note It will generate new JWT token when this is called.
- (void)refreshAuthTokenForLoginUserWithCompletion:(void (^)(KBMAPIResponse * _Nullable apiResponse, NSError * _Nullable error))completion;
@end

NS_ASSUME_NONNULL_END
