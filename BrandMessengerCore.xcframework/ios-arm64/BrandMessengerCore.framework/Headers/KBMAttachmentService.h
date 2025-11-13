//
//  KBMAttachmentService.h
//  BrandMessengerCore
//
//  Created by sunil on 25/09/18.
//  Copyright © 2018 Khoros, LLC. All rights reserved.
//

#import "KBMHTTPManager.h"
#import "KBMMessage.h"
#import "KBMMessageDBService.h"
#import "KBMMessageService.h"
#import "KBMRealTimeUpdate.h"
#import "BrandMessengerClient.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMAttachmentService` class has methods for sending and downloading an attachment, downloading a thumbnail.
@interface KBMAttachmentService : NSObject

/// This delegate is used for listening attachment upload or download events.
@property (nonatomic, weak) id<KBMAttachmentDelegate> _Nullable attachmentProgressDelegate;

/// `KBMUpdatesDelegate` delegate is used for real time delegate events for message.
@property (nonatomic, weak) id<KBMUpdatesDelegate> _Nullable delegate;

/// Instance method of `KBMAttachmentService`.
+ (KBMAttachmentService *)sharedInstance;

/// Sends an attachment message in chat.
/// @param attachmentMessage Pass the `KBMMessage` object.
/// @param delegate Sets the `KBMUpdatesDelegate` for real time update of the message status like sent.
/// @param attachmentProgressDelegate Sets the `KBMAttachmentDelegate` for the upload and download events.
- (void)sendMessageWithAttachment:(KBMMessage *)attachmentMessage
                     withDelegate:(id<KBMUpdatesDelegate> _Nullable)delegate
           withAttachmentDelegate:(id<KBMAttachmentDelegate> _Nullable)attachmentProgressDelegate;

/// Downloads an attachment for given `KBMMessage` object.
/// @param message Pass the `KBMMessage` object.
/// @param attachmentProgressDelegate Sets the `KBMAttachmentDelegate` for real-time updates for download events.
- (void)downloadMessageAttachment:(KBMMessage *)message withDelegate:(id<KBMAttachmentDelegate> _Nullable)attachmentProgressDelegate;

/// Downloads an thumbnail image for attachment.
/// @param message Pass the `KBMMessage` object.
/// @param attachmentProgressDelegate Sets the `KBMAttachmentDelegate` for real-time updates for download events.
- (void)downloadImageThumbnail:(KBMMessage *)message withDelegate:(id<KBMAttachmentDelegate> _Nullable)attachmentProgressDelegate;

@end

NS_ASSUME_NONNULL_END
