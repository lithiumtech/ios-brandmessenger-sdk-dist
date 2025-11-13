//
//  KBMUserBlocked.h
//  BrandMessengerCore
//
//  Created by devashish on 10/03/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// `KBMUserBlocked` class is used for block and unblock details of the user.
@interface KBMUserBlocked : NSObject

/// Generated Id of the stored in database.
@property (nonatomic, strong) NSString * _Nullable id;

/// Blocked to userId of the user.
@property (nonatomic, strong) NSString * _Nullable blockedTo;

/// Blocked by userId of the user.
@property (nonatomic, strong) NSString * _Nullable blockedBy;

/// App-ID of the user.
@property (nonatomic, strong) NSString * _Nullable applicationKey;

/// Response created at time stamp.
@property (nonatomic, strong) NSNumber * _Nullable createdAtTime;

/// Response updated at time stamp.
@property (nonatomic, strong) NSNumber * _Nullable updatedAtTime;

/// YES in case of user is blocked by you otherwise it will be NO in case of you have not blocked..
@property (nonatomic) BOOL userBlocked;

/// YES in case of user blocked you otherwise it will be NO in case of user not blocked you.
@property (nonatomic) BOOL userblockedBy;

@end

NS_ASSUME_NONNULL_END
