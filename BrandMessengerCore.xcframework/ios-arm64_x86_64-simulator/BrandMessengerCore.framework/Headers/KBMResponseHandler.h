//
//  KBMResponseHandler.h
//  BrandMessengerCore
//
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "KBMAuthService.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMResponseHandler`used for handling the URL request for calling the server for all the APIs.
///
/// Has methods for processing requests, JWT authenticates a request before processing.
@interface KBMResponseHandler : NSObject

/// `KBMAuthService` instance method.
@property (nonatomic, strong) KBMAuthService *authService;

/// Calling an API without JWT token.
/// @param request Create a URLRequest using `KBMRequestHandler`.
/// @param tag An tag of request to identify the request.
/// @param reponseCompletion An complete JSON response otherwise an error describing the request failure.
/// @note Internal API request method don't need to call from outside.
- (void)processRequest:(NSMutableURLRequest *)request
                andTag:(NSString *)tag
 WithCompletionHandler:(void(^)(id _Nullable jsonResponse , NSError  * _Nullable error))reponseCompletion;

/// Authenticate to sever by JWT token validation and proccess the request for API call.
/// @param request Create a URLRequest using `KBMRequestHandler`.
/// @param tag Pass the tag for request to identify the request.
/// @param completion An complete JSON response otherwise an error describing the Authenticate failure.
/// @note Internal API request method don't need to call from outside.
- (void)authenticateAndProcessRequest:(NSMutableURLRequest *)request
                               andTag:(NSString *)tag
                WithCompletionHandler:(void (^)(id _Nullable jsonResponse, NSError  * _Nullable error))completion;

/// Authenticate to sever for JWT token and will have the mutable URL request updated with JWT Token for calling the Messenger sever.
/// @param request Create a URLRequest using `KBMRequestHandler`.
/// @param completion Will have `NSMutableURLRequest` if success in generating JWT token otherwise an error describing the Authenticate failure.
/// @note Internal API request method don't need to call from outside.
- (void)authenticateRequest:(NSMutableURLRequest *)request
             WithCompletion:(void (^)(NSMutableURLRequest * _Nullable urlRequest, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
