//
//  KBMMessageBuilder.h
//  BrandMessengerCore
//
//  Created by apple on 04/07/18.
//  Copyright © 2018 Khoros, LLC. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMMessageBuilder` is an object builder for sending a text or attachment message to the Messenger server.
///
/// Sending an message in one-to-one chat:
/// @code
/// KBMMessage *message = [KBMMessage build:^(KBMMessageBuilder *messageBuilder) {
///     messageBuilder.to = @"1234588"; // Pass userId to whom you want to send a message.
///     messageBuilder.message = @"Hi How are you?"; // Pass message text here.
/// }];
/// @endcode
/// Sending a message in channel or group chat:
/// @code
/// KBMMessage *message = [KBMMessage build:^(KBMMessageBuilder *messageBuilder) {
///     messageBuilder.groupId = @47474; // Pass channelKey here to whom you want to send a message.
///     messageBuilder.message = @"Hi Hpw are you?"; // Pass message text here.
/// }];
/// @endcode
/// Sending an attachment message:
/// @code
/// KBMMessage *message = [KBMMessage build:^(KBMMessageBuilder *messageBuilder) {
///      messageBuilder.to = @"1234588"; // Set the userId of the receiver to send message in one to one chat and will be nil case of channel or group chat.
///      messageBuilder.imageFilePath = @"image123.jpg"; // File name
///      messageBuilder.contentType = KBMMESSAGE_CONTENT_ATTACHMENT;
/// }];
/// @endcode
@interface KBMMessageBuilder : NSObject

/// Sets the userId of the receiver to send a message in one-to-one chat.
/// @warning This has to be nil in case of channel or group message.
@property (nonatomic, copy) NSString * _Nullable to;

/// Sets the message text.
@property (nonatomic, copy) NSString * _Nullable message;

/// Sets the content type of message list of content types can be found in `KBMMessage` class static constants.
@property(nonatomic) short contentType;

/// Sets the channel key or groupId to send a message to the channel otherwise it will be nil.
/// @warning This has to be nil in case of one-to-one message.
@property (nonatomic, copy) NSNumber * _Nullable groupId;

/// :nodoc:
@property(nonatomic,copy) NSNumber * _Nullable conversationId;

/// Sets the extra information as metadata which will be in key-value Dictionary in each message that can be sent.
///
/// To set the message metadata use below code:
/// @code
///
/// NSMutableDictionary *messageMetaData = [[NSMutableDictionary alloc] init];
/// [messageMetaData setValue:@"Software engineer" forKey:@"designation"];
/// [messageMetaData setValue:@"Bengaluru" forKey:@"city"];
/// [messageMetaData setValue:@"India" forKey:@"country"];
/// @endcode
@property (nonatomic,retain) NSMutableDictionary * _Nullable metadata;

/// Sets the name of the attachment file that you want to upload in chat.
/// @note Make sure that the file exists in the document directory if the file does not exist make sure to save it and set it.
@property (nonatomic, copy) NSString * _Nullable imageFilePath;

@end

NS_ASSUME_NONNULL_END
