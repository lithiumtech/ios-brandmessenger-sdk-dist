//
//  KBMHTTPManager.h
//  BrandMessengerCore
//
//  Created by apple on 25/03/19.
//  Copyright © 2019 Khoros, LLC. All rights reserved.
//

#import "KBMDownloadTask.h"
#import "KBMMessage.h"
#import "KBMUploadTask.h"
#import "BrandMessengerClient.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMHTTPManager : NSObject <NSURLSessionDataDelegate,NSURLSessionDelegate>

@property (nonatomic, weak) id<KBMAttachmentDelegate> _Nullable attachmentProgressDelegate;

@property (nonatomic, weak) id<KBMUpdatesDelegate> _Nullable delegate;

@property (nonatomic, strong) NSMutableData * _Nullable buffer;

@property (nonatomic) NSUInteger *length;

@property (nonatomic) KBMUploadTask * _Nullable uploadTask;

@property (nonatomic) KBMDownloadTask * _Nullable downloadTask;

@property (nonatomic, strong) KBMResponseHandler *responseHandler;

- (void)processDownloadForMessage:(KBMMessage *)message isAttachmentDownload:(BOOL)attachmentDownloadFlag;

- (void)processUploadFileForMessage:(KBMMessage *)message uploadURL:(NSString *)uploadURL;

- (void)uploadProfileImage:(UIImage *)profileImage
              withFilePath:(NSString *)filePath
                 uploadURL:(NSString *)uploadURL
            withCompletion:(void(^)(NSData * _Nullable data, NSError * _Nullable error)) completion;

@end

NS_ASSUME_NONNULL_END
