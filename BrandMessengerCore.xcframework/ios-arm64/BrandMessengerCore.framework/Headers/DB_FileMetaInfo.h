//
//  DB_FileMetaInfo.h
//  BrandMessengerCore
//
//  Created by shaik riyaz on 23/08/15.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import <CoreData/CoreData.h>
#import <Foundation/Foundation.h>

/// `DB_FileMetaInfo` is DB class is used for storing the attachment details in core database.
@interface DB_FileMetaInfo : NSManagedObject

/// File attachment blob key used for identifying the file this blob key need to be added in File base URL.
@property (nonatomic, retain) NSString *blobKeyString;

/// Thumbnail blob key used for identifying the thumbnail this blob key need to be added in thumbnail base URL.
@property (nonatomic, retain) NSString *thumbnailBlobKeyString;

/// Local stored thumbnail image name on disk.
@property (nonatomic, retain) NSString *thumbnailFilePath;

/// For identifying the file is which type it can be image, audio, video or other types.
@property (nonatomic, retain) NSString *contentType;

/// File attachment created at time will be in milliseconds.
@property (nonatomic, retain) NSNumber *createdAtTime;

/// File attachment key.
@property (nonatomic, retain) NSString *key;

/// File name of the attachment.
@property (nonatomic, retain) NSString *name;

/// Size of the file attachment.
@property (nonatomic, retain) NSString *size;

/// File attachment user key.
@property (nonatomic, retain) NSString *suUserKeyString;

/// Thumbnail URL
@property (nonatomic, retain) NSString *thumbnailUrl;

/// File URL.
@property (nonatomic, retain) NSString *url;

@end
