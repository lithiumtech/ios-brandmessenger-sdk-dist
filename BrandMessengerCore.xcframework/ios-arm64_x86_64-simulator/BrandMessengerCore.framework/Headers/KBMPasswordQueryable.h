//
//  KBMPasswordQueryable.h
//  BrandMessengerCore
//
//  Created by apple on 11/03/21.
//  Copyright © 2021 Khoros, LLC. All rights reserved.
//

#import "KBMSecureStore.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMPasswordQueryable` class is used for password keychain access secure store.
@interface KBMPasswordQueryable : NSObject <KBMSecureStoreQueryable>

/// Init is not avaliable.
-(nonnull instancetype)init NS_UNAVAILABLE;

/// Used for init store service name which is used for identifying the keychain store.
/// @param service Pass the name of the store to access.
-(nonnull instancetype)initWithService:(NSString * _Nonnull)service;

/// Sets from `initWithService` and can be access the name using service string.
@property (nonatomic) NSString *serviceString;

/// Sets from `initWithService` name of the keychain access group.
@property (nonatomic) NSString *appKeychainAcessGroup;

/// Implemented from `KBMSecureStoreQueryable` it is Dictionary for
@property (nonatomic, readonly, copy) NSMutableDictionary<NSString *, id> * _Nonnull query;

@end

NS_ASSUME_NONNULL_END
