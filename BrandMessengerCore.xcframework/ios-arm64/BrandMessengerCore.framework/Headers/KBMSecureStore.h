//
//  KBMSecureStore.h
//  BrandMessengerCore
//
//  Created by apple on 11/03/21.
//  Copyright © 2021 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMSecureStoreQueryable` protocol is used in `KBMSecureStore`.
@protocol KBMSecureStoreQueryable <NSObject>

/// Query the secure store.
@property (nonatomic, readonly, copy) NSMutableDictionary<NSString *, id> * _Nonnull query;
@end

/// `KBMSecureStore` is used for storing the data in key chains secure store.
@interface KBMSecureStore : NSObject

/// `KBMSecureStoreQueryable` protocol intance.
@property (nonatomic) id <KBMSecureStoreQueryable> secureStoreQueryable;

/// init is not avaliable for accessing.
- (nonnull instancetype)init NS_UNAVAILABLE;

/// Used for init the Generic Password secure store protocol.
/// @param secureStoreQueryable Pass the class of the type `KBMSecureStoreQueryable` protocol.
- (nonnull instancetype)initWithSecureStoreQueryable:(id <KBMSecureStoreQueryable> _Nonnull)secureStoreQueryable;

/// Used for set the data in secure store.
/// @param value Pass the value to store.
/// @param userAccount Pass the key of the user account name.
/// @param error Will have error if there is failed to remove the data from store.
- (BOOL)setValue:(NSString * _Nonnull)value
  forUserAccount:(NSString * _Nonnull)userAccount
           error:(NSError * _Nullable * _Nullable)error;

/// Used for getting a value from secure store.
/// @param userAccount Pass the key of the user account.
/// @param error Will have error if there is failed to remove the data from store.
- (NSString * _Nullable)getValueFor:(NSString * _Nonnull)userAccount
                              error:(NSError * _Nullable * _Nullable)error;

/// Used for removing the single data from secure store.
/// @param userAccount Pass the key of user account.
/// @param error Will have error if there is failed to remove the data from store.
- (BOOL)removeValueFor:(NSString * _Nonnull)userAccount
                 error:(NSError * _Nullable * _Nullable)error;

/// Removes all the data from key chains for the Khoros secure store.
/// @param error Will have error if there is failed to remove all the data from store.
- (BOOL)removeAllValuesAndReturnError:(NSError * _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
