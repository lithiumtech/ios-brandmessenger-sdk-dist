//
//  KBMMessageWrapper.h
//  BrandMessengerCore
//
//  Created by Adarsh Kumar Mishra on 12/14/16.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import "BrandMessengerClient.h"
#import "KBMMessage.h"
#import <Foundation/Foundation.h>

@protocol MessageServiceWrapperDelegate <NSObject>

@optional

- (void)updateBytesDownloaded:(NSUInteger)bytesReceived;
- (void)updateBytesUploaded:(NSUInteger)bytesSent;
- (void)uploadDownloadFailed:(KBMMessage *)message;
- (void)uploadCompleted:(KBMMessage *)updatedMessage;
- (void)DownloadCompleted:(KBMMessage *)message;

@end

@interface KBMMessageServiceWrapper : NSObject

@property (strong, nonatomic) id <MessageServiceWrapperDelegate> messageServiceDelegate;

- (void)sendTextMessage:(NSString *)text andtoContact:(NSString *)toContactId;

- (void)sendTextMessage:(NSString *)messageText andtoContact:(NSString *)contactId orGroupId:(NSNumber *)channelKey;

- (void)sendMessage:(KBMMessage *)message
withAttachmentAtLocation:(NSString *)attachmentLocalPath
andWithStatusDelegate:(id)statusDelegate
     andContentType:(short)contentype;

- (void)downloadMessageAttachment:(KBMMessage *)message;

- (KBMMessage *)createMessageEntityOfContentType:(int)contentType
                                       toSendTo:(NSString *)to
                                       withText:(NSString *)text;

@end
