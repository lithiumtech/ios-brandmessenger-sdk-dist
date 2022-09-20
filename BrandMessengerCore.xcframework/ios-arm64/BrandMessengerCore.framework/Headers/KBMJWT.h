//
//  KBMJWT.h
//  BrandMessengerCore
//
//  Created by apple on 12/03/21.
//  Copyright © 2021 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// `KBMJWTProtocol` is used in `KBMJWT` for decoding the JWT token.
@protocol KBMJWTProtocol <NSObject>

/// token header part contents
@property (nonatomic) NSDictionary<NSString *, id> * _Nonnull header;

/// token body part values or token claims
@property (nonatomic) NSDictionary<NSString *, id> * _Nonnull body;

/// token signature part
@property (nonatomic) NSString * _Nullable signature;

/// jwt string value
@property (nonatomic) NSString * _Nullable string;

/// value of `exp` claim if available
@property (nonatomic) NSDate * _Nullable expiresAt;

/// value of `iss` claim if available
@property (nonatomic) NSString * _Nullable issuer;

/// value of `sub` claim if available
@property (nonatomic) NSString * _Nullable subject;

/// value of `aud` claim if available
@property (nonatomic) NSMutableArray<NSString*> * _Nullable audience;

/// value of `iat` claim if available
@property (nonatomic) NSDate * _Nullable issuedAt;

/// value of `nbf` claim if available
@property (nonatomic) NSDate * _Nullable notBefore;

/// value of `jti` claim if available
@property (nonatomic) NSString * _Nullable identifier;

/// value of the <code>expired</code> field
@property (nonatomic) BOOL expired;

@end

/// `KBMJWT` is used for decoding the JWT token use the `decodeWithJwt` method to decode.
@interface KBMJWT : NSObject <KBMJWTProtocol>

/// Creates a new instance of `KBMJWT` and decodes the given jwt token
/// @param jwtValue Value of the token to decode.
/// @param error Pass NSError to get any error in decoding JWT token.
/// @return A new instance of `KBMJWT` that holds the decode token.
+ (KBMJWT * _Nullable)decodeWithJwt:(NSString * _Nonnull)jwtValue
                             error:(NSError * _Nullable * _Nullable)error;

/// Init is unavailable use `decodeWithJwt` method to decode.
- (nonnull instancetype)init NS_UNAVAILABLE;

@end

