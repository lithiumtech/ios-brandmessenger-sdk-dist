//
//  KBMMuteRequest.h
//  BrandMessengerCore
//
//  Created by Adarsh Kumar Mishra on 1/12/17.
//  Copyright © 2017 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"

NS_ASSUME_NONNULL_BEGIN

/// `KBMMuteRequest` is used for creating a mute request for one-to-one or channel conversation mute or unmute.
@interface KBMMuteRequest : KBMJson

/// Sets the userId in case of one-to-one mute or unmute request.
@property (nonatomic, strong) NSString * _Nullable userId;
/// Sets the Group id in case of channel or group mute or unmute request.
@property (nonatomic, strong) NSNumber * _Nullable id;
/// Client Group id in case if you have your client group id is set during create channel then you can use that.
@property (nonatomic, strong) NSString * _Nullable clientGroupId;
/// Time Interval for which notification has been disabled.
@property (nonatomic, strong) NSNumber *notificationAfterTime;

NS_ASSUME_NONNULL_END

@end
