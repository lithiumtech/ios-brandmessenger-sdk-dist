//
//  KBMAuthClientService.h
//  BrandMessengerCore
//
//  Created by Sunil on 15/06/20.
//  Copyright © 2020 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import <Foundation/Foundation.h>
#import "KBMRegistrationResponse.h"

NS_ASSUME_NONNULL_BEGIN

/// Delegate protocol for authentication events.
/// refresh/token failure will call onRefreshFail. Calling completion with new accessToken will re-login and process pending action.
@protocol KBMAuthenticationDelegate <NSObject>
@required
-(void)onRefreshFail:(void (^)(NSString* accessToken))completion;
@end

/// `KBMAuthClientService` class is has methods for JWT token.
/// @warning `KBMAuthClientService` class used only for internal purposes.
@interface KBMAuthClientService : NSObject

/// Used for refreshing JWT auth token from server.
/// @param completion An `KBMAPIResponse` will have status `KBM_RESPONSE_SUCCESS` for successful otherwise, an error describing the refresh authtoken failure.
/// @note It will generate new JWT token when this is called.
- (void)refreshAuthTokenForLoginUserWithCompletion:(void (^)(KBMAPIResponse * _Nullable apiResponse, NSError * _Nullable error))completion;

/// Set authenticationDelegate to catch KBMAuthenticationDelegate events
+ (void)setAuthenticationDelegate:(NSObject<KBMAuthenticationDelegate>*) delegate;

/// first part of new auth. Calls authHandler with accessToken.
/// @note responseDictionary expects at least 'id' and 'token', to use as username and password in subsequent login call.
+ (void)preRegistrationAuth:(NSString*)accessToken withCompletion:(void (^)(NSDictionary * _Nullable responseDictionary, NSError * _Nullable error))completion;

/// second part of new auth. Calls register(login) to applozic with credentials from preRegistrationAuth.
+ (void)loginFromAuthHandlerResponse:(NSDictionary*)response withCompletion:(void (^)(KBMRegistrationResponse * _Nullable response, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
