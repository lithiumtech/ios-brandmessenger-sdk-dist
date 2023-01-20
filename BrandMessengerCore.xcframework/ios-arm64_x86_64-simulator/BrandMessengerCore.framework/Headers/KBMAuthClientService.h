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

/// Delegate protocol for JWT authentication events.
/// refresh/token failure will call onRefreshFail. Calling completion with new accessToken will re-login and process pending action.
@protocol KBMJWTAuthenticationDelegate <NSObject>
@required
-(void)onRefreshFailWithJWT:(void (^)(NSString* jwt, NSString* userId))completion;
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

/// Set JWT authenticationDelegate to catch KBMJWTAuthenticationDelegate events
+ (void)setJWTAuthenticationDelegate:(NSObject<KBMJWTAuthenticationDelegate>*) delegate;

/// Auth. Calls authHandler with dictionary. Used by
/// + (void)preRegistrationAuth:(NSString*)accessToken withCompletion:(void (^)(NSDictionary * _Nullable responseDictionary, NSError * _Nullable error))completion;
/// and
/// + (void) preRegistrationAuthWithJwt:(NSString*)jwt userId:(NSString*)userId withCompletion:(void (^)(NSDictionary * _Nullable responseDictionary, NSError * _Nullable error))completion
/// @note responseDictionary expects at least 'id' and 'token', to use as username and password in subsequent login call.
+ (void) preRegistrationAuthWithAuthDictionary:(NSDictionary *)authDictionary
                          withAuthenticateMode:(BOOL)hasAuthenticatedMode
                                withCompletion:(void (^)(NSDictionary * _Nullable responseDictionary, NSError * _Nullable error))completion;
/// Auth. Calls authHandler with accessToken.
/// @note responseDictionary expects at least 'id' and 'token', to use as username and password in subsequent login call.
+ (void)preRegistrationAuth:(NSString *)accessToken
           withUnauthUserId:(NSString * _Nullable)unauthUserId
            withUnauthToken:(NSString * _Nullable)unauthToken
             withCompletion:(void (^)(NSDictionary * _Nullable responseDictionary, NSError * _Nullable error))completion;

/// Auth. Calls authHandler with jwt and userId
/// @note responseDictionary expects at least 'id' and 'token', to use as username and password in subsequent login call.
+ (void)preRegistrationAuthWithJwt:(NSString*)jwt
                             userId:(NSString*)userId
                   withUnauthUserId:(NSString * _Nullable)unauthUserId
                    withUnauthToken:(NSString * _Nullable)unauthToken
                     withCompletion:(void (^)(NSDictionary * _Nullable responseDictionary, NSError * _Nullable error))completion;

/// second part of new auth. Calls register(login) to applozic with credentials from preRegistrationAuth or for unauth login.
+ (void)loginFromAuthHandlerResponse:(NSDictionary *_Nullable)response
                       withCompletion:(void (^)(KBMRegistrationResponse * _Nullable response, NSError * _Nullable error))completion;

/// make welcome-message API Request.
+ (void) sendWelcomeMessageRequestWithCompletion:(void (^)(NSDictionary * _Nullable responseDictionary, NSError * _Nullable error))completion;

/// Preregistration for unauth in the request body only metadata data goes.
/// @note responseDictionary expects at least 'id' and 'token', to login.
+ (void)preRegistrationUnauthWithCompletion:(void (^)(NSDictionary * _Nullable responseDictionary, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
