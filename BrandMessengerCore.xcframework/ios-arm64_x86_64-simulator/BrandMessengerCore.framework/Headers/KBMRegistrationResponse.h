//
//  KBMRegistrationResponse.h
//  BrandMessengerCore
//
//  Created by devashish on 18/09/2015.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"
#import <Foundation/Foundation.h>

@interface KBMRegistrationResponse : KBMJson

@property NSString *message;
@property NSString *deviceKey;
@property NSString *userKey;
@property NSString *contactNumber;
@property NSString *lastSyncTime;
@property NSString *currentTimeStamp;
@property NSString *brokerURL;
@property NSString *imageLink;
@property NSString *statusMessage;
@property NSString *encryptionKey;
@property short pricingPackage;
@property NSString *displayName;
@property NSString* notificationSoundFileName;
@property NSMutableDictionary *metadata;
@property NSString *roleName;
@property short roleType;
@property NSString *userEncryptionKey;
@property NSString *authToken;
@property short deviceNotificationMessageType;

- (BOOL)isRegisteredSuccessfully;

@end
