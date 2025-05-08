//
//  KBMAuthService.h
//  BrandMessengerCore
//
//  Created by Sunil on 11/06/20.
//  Copyright © 2020 Khoros, LLC. All rights reserved.
//

#import "KBMAuthClientService.h"
#import "KBMUserDefaultsHandler.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMAuthService` class is used for JWT token decode, validate auth token and refresh JWT token.
/// @warning `KBMAuthService` class used only for internal purposes.
@interface KBMAuthService : NSObject

/// Instance mthod of `KBMAuthClientService`.
@property (nonatomic, strong) KBMAuthClientService *authClientService;

/// Used for decode JWT token and save in user defaults.
/// @param authToken Pass the JWT auth token.
- (NSError * _Nullable)decodeAndSaveToken:(NSString *)authToken;

/// Check if saved token is still valid
/// @warning Do not call on main UI thread
+ (BOOL)isAuthTokenValid;

/// Used for validating a JWT Auth token and refresh the JWT token.
/// @param completion In case of successful the error will be nil otherwise error will be present if their is any error.
- (void)validateAuthTokenAndRefreshWithCompletion:(void (^)(NSError * _Nullable error))completion;

/// Used for refresh auth token the refreshed auth token is saved.
/// @param completion If KBMAPIResponse response in callback if success or error and NSError if any error occurs.
- (void)refreshAuthTokenForLoginUserWithCompletion:(void (^)(KBMAPIResponse * _Nullable apiResponse, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
