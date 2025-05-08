//
//  KBMUploadTask.h
//  BrandMessengerCore
//
//  Created by apple on 25/03/19.
//  Copyright © 2019 Khoros, LLC. All rights reserved.
//

#import "KBMMessage.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMUploadTask` is used for uploading the attachment file.
@interface KBMUploadTask : NSObject

/// Sets the file name of the attachment.
@property (nonatomic, copy) NSString * _Nullable filePath;

/// Name of the file.
@property (nonatomic, copy) NSString * _Nullable fileName;

/// Sets the key from `KBMMessage` object.
@property (nonatomic, copy) NSString * _Nullable identifier;

/// Sets the the `KBMMessage` object.
@property (nonatomic, strong) KBMMessage *message;

/// Sets the video Thumbnail name.
@property (nonatomic, strong) NSString * _Nullable videoThumbnailName;

@end

NS_ASSUME_NONNULL_END
