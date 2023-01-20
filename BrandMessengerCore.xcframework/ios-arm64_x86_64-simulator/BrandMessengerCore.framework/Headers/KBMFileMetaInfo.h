//
//  KBMFileMetaInfo.h
//  BrandMessengerCore
//
//  Created by shaik riyaz on 23/08/15.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMFileMetaInfo` class is used for attachment object.
@interface KBMFileMetaInfo : KBMJson

/// File attachment key.
@property (nonatomic,copy) NSString * _Nullable key;

/// User key of the user who set the attachment file.
@property (nonatomic,copy) NSString * _Nullable userKey;

/// Blob key of the file attachment.
@property (nonatomic,copy) NSString * _Nullable blobKey;

/// Thumbnail blob key in case of image, video.
@property (nonatomic,copy) NSString * _Nullable thumbnailBlobKey;

/// Local thumbnail file name.
@property (nonatomic,copy) NSString * _Nullable thumbnailFilePath;

/// Name of the file attachment.
@property (nonatomic,copy) NSString *name;

/// Attachment url.
@property (nonatomic,copy) NSString * _Nullable url;

/// Size of the file.
@property (nonatomic,copy) NSString * _Nullable size;

/// Content type of attachment file.
@property (nonatomic,copy) NSString * contentType;

/// Thumbnail url
@property (nonatomic,copy) NSString * _Nullable thumbnailUrl;

/// Time of the attachment created at.
@property (nonatomic,copy) NSNumber * _Nullable createdAtTime;

/// :nodoc:
@property (nonatomic, assign) CGFloat progressValue;

/// Returns a size of the file.
- (NSString *)getTheSize;

/// Populate the JSON of the file metadata.
/// @param dict Dictionary of file meta json.
- (KBMFileMetaInfo *)populate:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
