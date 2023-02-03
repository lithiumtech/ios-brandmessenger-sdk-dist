//
//  KBMMQTTConversationService.h
//  BrandMessengerCore
//
//  Created by Sunil on 11/27/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMMessage.h"
#import "KBMRealTimeUpdate.h"
#import "KBMSyncCallService.h"
#import "KBMUserDetail.h"
#import "MQTTClient.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Notification name for channel mute or unmuted.
extern NSString *const KBMChannelDidChangeGroupMuteNotification;

/// Notification name for logged in user activated or deactivated.
extern NSString *const KBMLoggedInUserDidChangeDeactivateNotification;

/// `KBMMQTTConversationDelegate` protocol used for listening to the real-time updates from MQTT.
///
/// @warning This is used for MQTT real-time update events for internal purposes only.
@protocol KBMMQTTConversationDelegate <NSObject>

/// This callback will be called once the new message is received.
///
/// @param message This will have `KBMMessage` object on new message received
/// @param messageArray This will be nil
- (void)syncCall:(KBMMessage *)message andMessageList:(NSMutableArray * _Nullable)messageArray;

/// The callback will be called on message is delivered to the receiver.
///
/// @param messageKey Will have messageKey for delivered status
/// @param contactId UserId of the user message delivered to.
/// @param status Status are `DELIVERED` or `DELIVERED_AND_READ`.
- (void)delivered:(NSString *)messageKey contactId:(NSString * _Nullable)contactId withStatus:(int)status;

/// The callback will be called on the receiver to read the all messages in the conversation.
///
/// @param contactId Will have receiver userId who has read the conversation.
/// @param status Read sttaus of message.
- (void)updateStatusForContact:(NSString *)contactId withStatus:(int)status;

/// The callback will be called on for typing events.
///
/// @param applicationKey App-ID for Brand Messenger.
/// @param userId Will have user's userId who is typing.
/// @param status If the status flag is YES or true then the user started typing, if the status is NO or false then the user stops typing
- (void)updateTypingStatus:(NSString *)applicationKey userId:(NSString *)userId status:(BOOL)status;

/// The callback will be called on the user's online or offline update.
///
/// @param userDetail Will have `KBMUserDetail` object of user.
- (void)updateLastSeenAtStatus:(KBMUserDetail *)userDetail;

/// The callback will be called on MQTT disconnected you can resubscribe to the conversation.
- (void)mqttConnectionClosed;

@optional

- (void)updateMessageText:(NSString *)text withMessageKey:(NSString *)messageKey;

/// The callback will be called on the MQTT is connected.
- (void)mqttDidConnected;

/// The callback will be called on the user is blocked or unblocked
/// @param userId Receiver userId blocked or unblocked.
/// @param flag if YES then user is blocked otherwise unblocked for NO.
- (void)reloadDataForUserBlockNotification:(NSString *)userId andBlockFlag:(BOOL)flag;

/// The callback will be called on the user details updated like name, profile image URL, status, etc.
/// @param userId Receiver userId the user details updated.
- (void)updateUserDetail:(NSString *)userId;

@end

/// `KBMMQTTConversationService` used for making a connection to the server for real-time update events on MQTT.
///
/// @warning `KBMMQTTConversationService` used for internal purposes only.
@interface KBMMQTTConversationService : NSObject <MQTTSessionDelegate>

/// `KBMMQTTConversationService` instance method.
+(KBMMQTTConversationService *)sharedInstance;

/// `KBMSyncCallService` instance method.
@property (nonatomic, strong) KBMSyncCallService *syncCallService;

/// Sets the `KBMMQTTConversationDelegate` for listening to the real-time updates from MQTT.
@property (nonatomic, weak) id<KBMMQTTConversationDelegate>mqttConversationDelegate;

/// Gives callbacks for real-time update events for Messages, channels, Users, and Typing
@property (nonatomic, weak) id<KBMUpdatesDelegate>realTimeUpdate;

/// `MQTTSession` instance method.
@property (nonatomic, readwrite) MQTTSession *session;

/// Used for subscribing to real-time events for conversation.
- (void)subscribeToConversation;

/// Used for subscribing to real-time events for conversation with topic name.
/// @param topic Pass the name of the topic to subscribe.
- (void)subscribeToConversationWithTopic:(NSString *)topic;

/// Used for unsubscribing to real-time events for conversation.
- (void)unsubscribeToConversation;

/// Used for unsubscribing to real-time events for conversation with topic name.
/// @param topic Pass the name of the topic to unsubscribe.
- (void)unsubscribeToConversationWithTopic:(NSString *)topic;

/// Unsubscribe for all real-time update events for conversations.
/// @param userKey Pass the `[KBMUserDefaultsHandler getUserKeyString];` key.
- (BOOL)unsubscribeToConversation:(NSString *)userKey;

/// Used for sending a typing status in one-to-one or channel conversation.
/// @param applicationKey App-Id or application key of Brand Messenger.
/// @param userId Pass the receiver userId of the user.
/// @param channelKey Pass the channelKey of `KBMChannel`.
/// @param typing If the logged user is typing pass YES or true in typing else on stop of user typing pass NO or false to stop the typing.
- (void)sendTypingStatus:(NSString * _Nullable)applicationKey
                  userID:(NSString * _Nullable)userId
           andChannelKey:(NSNumber * _Nullable)channelKey
                  typing:(BOOL)typing;

/// Unsubscribe to typing status of channel conversation.
/// @param channelKey Pass the channelKey of `KBMChannel`.
- (void)unSubscribeToChannelConversation:(NSNumber * _Nullable)channelKey;

/// Subscribes to typing status for given channel key.
/// @param channelKey Pass the channelKey of `KBMChannel`.
- (void)subscribeToChannelConversation:(NSNumber * _Nullable)channelKey;

/// Subscribes to Open Channel for real-time update events.
/// @param channelKey Pass the channelKey of `KBMChannel`.
- (void)subscribeToOpenChannel:(NSNumber *)channelKey;

/// Unsubscribes to open channel all real-time update events.
/// @param channelKey Pass the channelKey of f `KBMChannel`.
- (void)unSubscribeToOpenChannel:(NSNumber *)channelKey;

/// Syncs the message and post an notification request, used for internal purposes only .
/// @param message Pass the `KBMMessage` object.
/// @param notificationDictionary Notification dictionary.
- (void)syncReceivedMessage:(KBMMessage *)message withNSMutableDictionary:(NSMutableDictionary *)notificationDictionary;

/// Used for subscribe to conversation with topic.
/// @param topic Pass the name of topic to subscribe.
/// @param completion completion YES in case of subscribed otherwise NO with an error.
- (void)subscribeToConversationWithTopic:(NSString *)topic withCompletionHandler:(void (^)(BOOL subscribed, NSError * _Nullable error))completion;

/// For publishing a read status of the message using MQTT.
/// @param messageKey Pass the message key which is used for identifying the message.
- (BOOL)messageReadStatusPublishWithMessageKey:(NSString *)messageKey;

/// For publishing custom data with topic using MQTT.
/// @param dataString Pass the string of data to publish.
/// @param topic Pass the topic name to publish on.
- (BOOL)publishCustomData:(NSString *)dataString withTopicName:(NSString *)topic;
@end

NS_ASSUME_NONNULL_END
