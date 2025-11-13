//
//  KBMUserDetail.h
//  BrandMessengerCore
//
//  Created by devashish on 26/11/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"
#import <CoreData/NSManagedObject.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMUserDetail : KBMJson

@property (nonatomic, strong) NSString *userId;
@property (nonatomic) BOOL connected;
@property (nonatomic, strong) NSNumber * _Nullable lastSeenAtTime;
@property (nonatomic, strong) NSNumber * _Nullable unreadCount;
@property (nonatomic, strong) NSString * _Nullable displayName;
@property (nonatomic, strong) NSString * _Nullable imageLink;
@property (nonatomic, strong) NSString * _Nullable contactNumber;
@property (nonatomic, strong) NSString * _Nullable userStatus;
@property (nonatomic, strong) NSArray * _Nullable keyArray;
@property (nonatomic, strong) NSArray * _Nullable valueArray;
@property (nonatomic, strong) NSString * _Nullable userIdString;
@property (nonatomic, strong) NSNumber * _Nullable userTypeId;
@property (nonatomic, strong) NSNumber * _Nullable deletedAtTime;
@property (nonatomic, strong) NSNumber * _Nullable roleType;
@property (nonatomic,retain) NSMutableDictionary * _Nullable metadata;
@property (nonatomic, strong) NSNumber * _Nullable notificationAfterTime;
@property (nonatomic, strong) NSString * _Nullable email;
@property (nonatomic, strong) NSNumber * _Nullable status;

- (void)setUserDetails:(NSString *)jsonString;

- (NSString *)getDisplayName;

- (id)initWithDictonary:(NSDictionary *)messageDictonary;

- (void)parsingDictionaryFromJSON:(NSDictionary *)JSONDictionary;

- (BOOL)isNotificationMuted;

- (BOOL)isChatDisabled;

- (NSMutableDictionary * _Nullable)getMetaDataDictionary:(NSString *)jsonString;
- (NSMutableDictionary * _Nullable)appendMetadataIn:(NSString *) metadataString;

@end

NS_ASSUME_NONNULL_END
