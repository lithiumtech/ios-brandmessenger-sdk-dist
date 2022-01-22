//
//  KBMContactService.h
//  BrandMessengerCore
//
//  Created by Devashish on 23/10/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMContact.h"
#import "KBMContactsResponse.h"
#import "KBMContactDBService.h"
#import "KBMRealTimeUpdate.h"
#import "KBMUserBlocked.h"
#import "KBMUserDetail.h"
#import "DB_CONTACT.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMContactService` class used for adding, fetching, updating, deleting `KBMContact` or user details.
@interface KBMContactService : NSObject

/// Instance method of `KBMContactDBService`.
@property (nonatomic, strong) KBMContactDBService *contactDBService;

/// Deletes array of contacts from local database.
/// @param contacts Pass the array of `KBMContact` objects for deleting.
- (BOOL)purgeListOfContacts:(NSArray *)contacts;

/// Delete the contact from local database.
/// @param contact Pass the contact for deleting.
- (BOOL)purgeContact:(KBMContact *)contact;

/// Deletes all contacts from core database.
- (BOOL)purgeAllContact;

/// Updates an array of contacts in the local database.
/// @param contacts Pass the array of `KBMContact` objects for updating.
- (BOOL)updateListOfContacts:(NSArray *)contacts;

/// Updates the contact in the local database.
/// @param contact Pass the `KBMContact` object to update.
- (BOOL)updateContact:(KBMContact *)contact;

/// Adds an array of contacts in a local database.
/// @param contacts Pass the array of `KBMContact` to add.
- (BOOL)addListOfContacts:(NSArray *)contacts;

/// Adds the contact in the local database.
/// @param userContact Create a `KBMContact` object and set up the details and pass it to the method.
- (BOOL)addContact:(KBMContact *)userContact;

/// This method is used for loading the contact or user detail from the local database.
/// If the contact does not exist, it will create a contact object and return KBMContact.
/// @param key Pass on which detail should be fetched on the bases.
/// Ex: to fetch based on the userId key, then pass the string as userId.
/// @param value Pass the value of the userId of the user to get the details.
/// @return Returns a `KBMContact` object.
- (KBMContact * _Nullable)loadContactByKey:(NSString *)key value:(NSString *)value;

/// Gets the contact from local database if contact exist otherwise it will create new contact with userId and display name.
/// @param contactId Pass the userId of the reciever.
/// @param displayName Pass the display name of the user.
/// @return Returns a `KBMContact` object.
- (KBMContact *)loadOrAddContactByKeyWithDisplayName:(NSString *)contactId value:(NSString *)displayName;

/// Sets the unread count in contact.
/// @param contact Pass the `KBMContact` object.
- (BOOL)setUnreadCountInDB:(KBMContact *)contact;

/// Gets the total unread count of all the contacts or user.
- (NSNumber * _Nullable)getOverallUnreadCountForContact;

/// Returns YES if contact exist otherwise NO.
/// @param userId Pass the userId of the user for checking if the contact exists in the database.
- (BOOL)isContactExist:(NSString *)userId;

/// Updates or adds a new contact in the local database.
/// @param contact Pass the `KBMContact` object with details to update or insert the contact.
- (BOOL)updateOrInsert:(KBMContact *)contact;

/// Updates or adds a array of contacts in the local database.
/// @param contacts Pass the array of `KBMContact` object with details to update or insert the contact.
- (void)updateOrInsertListOfContacts:(NSMutableArray *)contacts;

/// Used for checking if the user is deleted. This will check from the local database which is stored not from the server.
/// @param userId Pass the userId of the user to check whether the user is deleted or not.
- (BOOL)isUserDeleted:(NSString *)userId;

/// Updates user mute time in local database.
/// @param notificationAfterTime Time in milliseconds.
/// @param userId Pass the userId for updating time stamp in database.
- (KBMUserDetail * _Nullable)updateMuteAfterTime:(NSNumber *)notificationAfterTime andUserId:(NSString *)userId;
@end

NS_ASSUME_NONNULL_END
