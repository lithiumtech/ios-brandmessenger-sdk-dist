//
//  KBMNotificationView.h
//  BrandMessengerCore
//
//  Created by Devashish on 06/10/15.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "BrandMessengerCore.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMNotificationView` class is used for showing local notification and it is used in Messenger UI.
@interface KBMNotificationView : UILabel

/// Sets in `-[KBMNotificationView initWithKBMMessage:withAlertMessage]` method and the receiver userId for which notification to show otherwise it will be nil.
@property (retain ,nonatomic) NSString * _Nullable contactId;

/// Sets in `-[KBMNotificationView initWithKBMMessage:withAlertMessage]` method and the groupId for which the notification to show otherwise it will be nil
@property (retain, nonatomic) NSNumber * _Nullable groupId;

/// Sets in `-[KBMNotificationView initWithKBMMessage:withAlertMessage]` method and the conversationId is of topic-based chat otherwise it will be nil.
@property (retain, nonatomic) NSNumber * _Nullable conversationId;

/// Sets in `-[KBMNotificationView initWithKBMMessage:withAlertMessage]` method it will have `KBMMessage` object.
@property (retain, nonatomic) KBMMessage *message;

/// Get the `KBMNotificationView` object with `KBMMessage` and alert message for showing a notification.
/// @param message An `KBMMessage` object with message details.
/// @param alertMessage An alert message to display.
- (instancetype)initWithKBMMessage:(KBMMessage *)message withAlertMessage:(NSString * _Nullable)alertMessage;

/// Shows local notification and handler for the tap event for notification.
/// @param handler The handler will be called once the tap on the local notification.
- (void)showNativeNotificationWithcompletionHandler:(void (^)(BOOL))handler;

/// Showing the default notification message for member left from the channel.
- (void)showGroupLeftMessage;

/// Show default no Internet Connectivity message.
- (void)noDataConnectionNotificationView;

/// Showing information notification with given notification alert text.
/// @param message An message text to show in notification.
+ (void)showNotification:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
