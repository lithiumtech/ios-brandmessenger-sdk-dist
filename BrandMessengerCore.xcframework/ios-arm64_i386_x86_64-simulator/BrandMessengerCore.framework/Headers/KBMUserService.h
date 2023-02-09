//
//  KBMUserService.h
//  BrandMessengerCore
//
//  Created by Divjyot Singh on 05/11/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMAPIResponse.h"
#import "KBMChannelService.h"
#import "KBMConstant.h"
#import "KBMContactDBService.h"
#import "KBMContactService.h"
#import "KBMLastSeenSyncFeed.h"
#import "KBMMessage.h"
#import "KBMMessageList.h"
#import "KBMMuteRequest.h"
#import "KBMRealTimeUpdate.h"
#import "KBMSyncMessageFeed.h"
#import "KBMUserBlockResponse.h"
#import "KBMUserClientService.h"
#import "DB_FileMetaInfo.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMUserService` has a Brand Messenger user APIs.
///
/// Some of the methods that this class has:
///
/// * User details fetch.
/// * Mark conversation for one-to-one chat.
/// * Update user details to Messenger server.
/// * Report user message.
/// * List of Registered contacts or users in Messenger Server.
/// * Update user display who is not logged-in in Messenger server.
@interface KBMUserService : NSObject

/// Instance method of `KBMUserService`
+ (KBMUserService *)sharedInstance;

/// Instance method of `KBMUserClientService`
@property (nonatomic, strong) KBMUserClientService *userClientService;

/// Instance method of `KBMChannelService`
@property (nonatomic, strong) KBMChannelService *channelService;

/// Instance method of `KBMContactDBService`
@property (nonatomic, strong) KBMContactDBService *contactDBService;

/// Instance method of `KBMContactService`
@property (nonatomic, strong) KBMContactService *contactService;

/// Gets `KBMContact` object if exists in server otherwise, creates contact for given userId in local database and returns.
/// @param userId Pass the userId for fetching user details.
/// @param completion `KBMContact` on fetch completion.
- (void)getUserDetail:(NSString *)userId withCompletion:(void(^)(KBMContact * _Nullable contact))completion;

/// Gets the user `KBMContact` object for given userId from Messenger server.
///
/// @param userId An receiver userId to fetch the details.
/// @param completion An `KBMContact` object on successful fetch otherwise, an error describing fetch user details.
- (void)getUserDetailFromServer:(NSString *)userId
                 withCompletion:(void(^)(KBMContact * _Nullable contact, NSError * _Nullable error))completion;

/// Mark a conversation as read in a one-to-one chat.
/// @param userId Pass the userId for marking conversation read.
/// @param completion In case of a successful conversation marked as read, the error will be nil. Otherwise, in case of failure, the error will not be nil.
- (void)markConversationAsRead:(NSString *)userId withCompletion:(void (^)(NSString * _Nullable jsonResponse, NSError * _Nullable error))completion;

/// Used for blocking the user.
/// @param userId Pass the userId for blocking the user.
/// @param completion In case of any error in blocking, it will have an error in completion. Otherwise, if the block is successful it will have YES or true in userBlock.
- (void)blockUser:(NSString *)userId withCompletionHandler:(void(^)(NSError * _Nullable error, BOOL hasUserBlocked))completion;

/// Used for unblocking the user.
/// @param userId Pass the userId that for unblocking the user.
/// @param completion In case of any error in unblocking it will have an error in completion. Otherwise, if unblock is successful, it will have YES or true in userUnblock.
- (void)unblockUser:(NSString *)userId withCompletionHandler:(void(^)(NSError * _Nullable error, BOOL hasUserUnblocked))completion;

/// Used for mute a user in one-to-one chat.
/// @param muteRequest Pass the KBMMuteRequest object for the userId and notificationAfterTime.
/// @param completion KBMAPIResponse in case of a successful update or else it will return NSError in case of failure.
- (void)muteUser:(KBMMuteRequest *)muteRequest withCompletion:(void(^)(KBMAPIResponse * _Nullable response, NSError * _Nullable error))completion;

/// Used for reporting the message to the admin of the account
/// @param messageKey Pass message key of `KBMMessage` object
/// @param completion KBMAPIResponse response callback if success or error and NSError if any error occurs
- (void)reportUserWithMessageKey:(NSString *)messageKey withCompletion:(void (^)(KBMAPIResponse * _Nullable apiResponse, NSError * _Nullable error))completion;

/// Gets the registered contacts from Messenger server and from local database.
/// @param nextPage If nextPage is NO or false, it will get contacts from starting and return the array of contact.
/// If nextPage the flag is YES or true, it will return the next older contacts.
/// @param completion Array of KBMContact in case of successfully fetched, else it will return NSError.
- (void)getListOfRegisteredContactsWithNextPage:(BOOL)nextPage
                                 withCompletion:(void(^)(NSMutableArray * _Nullable contactArray, NSError * _Nullable error))completion;

/// Mark a single message as read using with given `KBMMessage` object and paired message key from the `KBMMessage` object.
/// @param message An `KBMMessage` object for marking the message as read.
/// @param pairedkeyValue An paired message key from the `KBMMessage` object.
/// @param completion In case of a successful message marked as read, the error will be nil. Otherwise, an error describing mark conversation read failure.
- (void)markMessageAsRead:(KBMMessage *)message
       withPairedkeyValue:(NSString *)pairedkeyValue
           withCompletion:(void (^)(NSString * _Nullable response, NSError * _Nullable error))completion;

/// Updating the display name of a user who is not registered or does not login to an Messenger server for given receiver userId and user name.
/// @param userId Pass the receiver userId.
/// @param displayName Pass the user display name of the receiver.
/// @param completion KBMAPIResponse in case of a successful update or else it will return NSError in case of failure.
- (void)updateDisplayNameWith:(NSString *)userId
              withDisplayName:(NSString *)displayName
               withCompletion:(void (^)(KBMAPIResponse * _Nullable apiResponse, NSError * _Nullable error))completion;

/// Updating the display name, image URL, or status of a logged-in user in user.
/// @param displayName Pass the display name of a user.
/// @param imageLink Pass the image URL link of the user.
/// @param status Pass the status of the user.
/// @param completion If an error is not nil, the user detail will be fetched successfully, else error in the failure of fetching.
- (void)updateUserDisplayName:(NSString * _Nullable)displayName
                 andUserImage:(NSString * _Nullable)imageLink
                   userStatus:(NSString * _Nullable)status
               withCompletion:(void (^)(id _Nullable jsonResponse, NSError * _Nullable error))completion;

/// Updates user details like the phone number, emailId based on ofUserID on the behalf of the user the admin can edit the details.
///
/// @param phoneNumber Pass the phone number if update required otherwise pass nil.
/// @param email Pass the Email ID if update required otherwise pass nil.
/// @param userId Pass the userId on the behalf update required.
/// @param completion YES in case of update success otherwise NO in case of any error.
/// @warning Used only for internal purpose only.
- (void)updateUser:(NSString * _Nullable)phoneNumber
             email:(NSString * _Nullable)email
            ofUser:(NSString *)userId
    withCompletion:(void (^)(BOOL))completion;

/// Gets array of `KBMUserDetail` for given array of userIds.
/// @param userArray Add the userIds and pass it an array for user details.
/// @param completion Array of KBMUserDetail in case of a successful fetch or else it will return NSError in case of failure.
- (void)getUserDetails:(NSMutableArray *)userArray
        withCompletion:(void (^)(NSMutableArray * _Nullable userDetailArray, NSError * _Nullable error))completion;

/// This method is used for update a logged-in user password to new one.
/// @param oldPassword Pass the existing password of the user.
/// @param newPassword Pass new password of the user.
/// @param completion KBMAPIResponse` in status of this it will have success fetched the data successfully or error in case of any error.
- (void)updatePassword:(NSString *)oldPassword
       withNewPassword:(NSString *)newPassword
        withCompletion:(void(^)(KBMAPIResponse * _Nullable apiResponse, NSError * _Nullable error))completion;

/// Fetching users whose last seen is updated recently.
/// @param lastSeenAtTime Pass the last getLastSeenSyncTime from KBMUserDefaultsHandler.
/// @param completionMark In case of a successful fetch, it will have a list of `KBMUserDetail` array. Otherwise, in case of failure, the error will not be nil.
- (void)getLastSeenUpdateForUsers:(NSNumber *)lastSeenAtTime withCompletion:(void(^)(NSMutableArray * _Nullable userDetailArray))completionMark;

/// Search the users for given name of user.
/// @param userName Pass the name of the user to search
/// @param completion `KBMAPIResponse` in the status of this it will have success fetched the data successfully or error in case of any error.
- (void)getListOfUsersWithUserName:(NSString *)userName withCompletion:(void(^)(KBMAPIResponse * _Nullable response, NSError * _Nullable error))completion;

/// Gets the muted users from an Messenger server.
/// @param delegate If KBMUpdatesDelegate is passed, the event for onUserMuteStatus will be called.
/// @param completion Array of KBMUserDetail in case of a successful fetch or else it will return NSError in case of failure.
- (void)getMutedUserListWithDelegate:(id <KBMUpdatesDelegate> _Nullable)delegate
                      withCompletion:(void(^)(NSMutableArray * _Nullable userDetailArray, NSError * _Nullable error))completion;

/// Fetching the blocked and unblocked user status.
/// @param lastSyncTime Pass the last sync time that synced before.
- (void)blockUserSync:(NSNumber *)lastSyncTime;

/// Posts the conversation read status with notification name `Update_unread_count` and userInfo will have the userId of the user whose conversation has been read from another platform.
/// @param userId of user that notification to post for read.
/// @param delegate `KBMUpdatesDelegate` for sending callback for read conversation.
/// @warning This method is used internal purpose only for posting notification.
- (void)updateConversationReadWithUserId:(NSString *)userId withDelegate:(id<KBMUpdatesDelegate> _Nullable)delegate;

/// Used for fetching updated user details from the server.
/// @param userId Pass the userId for which the latest user detail is needed.
/// @param completionMark KBMUserDetail in case of a successful fetch or else it will return nil in case of failure.
- (void)updateUserDetail:(NSString *)userId withCompletion:(void(^)(KBMUserDetail * _Nullable userDetail))completionMark;

/// Returns array of userIds which are blocked by logged-in user.
- (NSMutableArray * _Nullable)getListOfBlockedUserByCurrentUser;

/// Total unread count which are fetched from core database.
- (NSNumber * _Nullable)getTotalUnreadCount;

/// Fetching a list of top online users based on the `onlineContactLimit` from `BrandMessengerSettings`.
/// @param completion Array of an `KBMContact` object in case of successful fetch otherwise an error describing online user fetch failure.
- (void)fetchOnlineContactFromServer:(void(^)(NSMutableArray * _Nullable contactArray, NSError * _Nullable error))completion;

/// Used for disable the chat for logged in user in all conversations.
/// @param disable Pass YES for disabling the chat otherwise NO for enable.
/// @param completion Response is YES then disabled successfully otherwise error.
- (void)disableChat:(BOOL)disable withCompletion:(void(^)(BOOL response, NSError * _Nullable error)) completion;

/// Fetching registered users in your App-ID.
///
/// On completion you can fetch the users from `KBMContactDBService` method `getAllContactsFromDB`.
/// @param completion An error describing registered user failure otherwise it will be nil in case of success.
- (void)getListOfRegisteredUsersWithCompletion:(void(^)(NSError * _Nullable error))completion;

/// Fetching user details based on the `KBMMessage` array.
/// @param messages An Array of `KBMMessage` object.
/// @param completionMark The handler will be called once the competion is done.
- (void)processContactFromMessages:(NSArray * _Nullable)messages withCompletion:(void(^)(void))completionMark;

/// Used for set unread count to zero in local database.
/// @param contactId Receiver userId to reset the count to zero.
- (void)setUnreadCountZeroForContactId:(NSString *)contactId;

/// Update the block status in local database.
/// @param userBlockResponse An `KBMUserBlockResponse` object parsing JSON.
/// @warning Method is used for Internal use only.
- (void)updateBlockUserStatusToLocalDB:(KBMUserBlockResponse *)userBlockResponse;

/// Mark the conversation as read in local core database for given message.
/// Method is used for Internal use only.
/// @param message Pass the `KBMMessage` object.
- (void)markConversationReadInDataBaseWithMessage:(KBMMessage *)message;

@end

NS_ASSUME_NONNULL_END
