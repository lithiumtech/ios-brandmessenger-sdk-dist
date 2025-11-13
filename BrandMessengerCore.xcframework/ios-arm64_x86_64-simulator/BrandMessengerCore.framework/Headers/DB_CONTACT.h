//
//  DB_CONTACT.h
//  BrandMessengerCore
//
//  Created by shaik riyaz on 11/08/15.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import <CoreData/CoreData.h>
#import <Foundation/Foundation.h>

/// `DB_CONTACT` is DB class is used for storing the contact or user details in core database.
@interface DB_CONTACT : NSManagedObject

/// UserId of user which is used for identifying the user.
@property (nonatomic, retain) NSString *userId;

/// Full name of the user.
@property (nonatomic, retain) NSString *fullName;

/// Contact number of user.
@property (nonatomic, retain) NSString *contactNumber;

/// Display name of the user.
@property (nonatomic, retain) NSString *displayName;

/// Profile image url of user.
@property (nonatomic, retain) NSString *contactImageUrl;

/// Email id of the user.
@property (nonatomic, retain) NSString *email;

/// Local image resource name.
@property (nonatomic, retain) NSString *localImageResourceName;

/// Last seen time of the user.
@property (nonatomic, retain) NSNumber *lastSeenAt;

/// User status message.
@property (nonatomic, retain) NSString *userStatus;

/// User is online or not.
///
/// If connected is true then user is online else offline.
@property (nonatomic) BOOL connected;

/// Unread message count of user.
@property (nonatomic, retain) NSNumber *unreadCount;

/// If block is true then user is blocked.
@property (nonatomic) BOOL block;

/// To check if some one has blocked logged-in user.
@property (nonatomic) BOOL blockBy;

/// To identify the user type.
@property (nonatomic, retain) NSNumber *userTypeId;

/// Contact type for showing own contacts set of added contacts or user.
@property (nonatomic, retain) NSNumber *contactType;

/// To know that user is deleted If deletedAtTime > 0 then user is deleted else not deleted.
@property (nonatomic, retain) NSNumber *deletedAtTime;

/// User meta data an extra information of user.
@property (nonatomic, retain) NSString *metadata;

/// Role of user it will have list of roles can be found in `KBMUSER_ROLE_TYPE`
@property (nonatomic, retain) NSNumber *roleType;

/// User notification has been muted if notificationAfterTime > 0 else notification are not muted.
@property (nonatomic, strong) NSNumber *notificationAfterTime;

/// Contact current status.
@property (nonatomic, strong) NSNumber *status;

@end
