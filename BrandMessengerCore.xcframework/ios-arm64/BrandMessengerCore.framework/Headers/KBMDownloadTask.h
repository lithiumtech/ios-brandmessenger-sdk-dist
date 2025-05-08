//
//  KBMDownloadTask.h
//  BrandMessengerCore
//
//  Created by apple on 25/03/19.
//  Copyright © 2019 Khoros, LLC. All rights reserved.
//

#import "KBMMessage.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMDownloadTask` is class used for creating an download task.
@interface KBMDownloadTask : NSObject

/// Sets the YES or true in case of Thumbnail.
@property (nonatomic) BOOL isThumbnail;

/// Sets the name of the file.
@property (nonatomic, copy) NSString * _Nullable fileName;

/// Sets the `KBMMessage` object.
@property (nonatomic, strong) KBMMessage *message;

@end

NS_ASSUME_NONNULL_END
