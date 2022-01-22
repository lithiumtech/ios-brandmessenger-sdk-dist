//
//  UIImage+Utility.h
//  BrandMessengerCore
//
//  Created by shaik riyaz on 22/08/15.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// `UIImage` extension utility class for image.
@interface UIImage (Utility)

/// Use the method for getting size from UIImage.
- (double)getImageSizeInMb;
/// Use the method for geeting compressed image.
/// @param sizeInMb Pass the size of image.
- (UIImage * _Nullable)getCompressedImageLessThanSize:(double)sizeInMb;
/// Use the method compressed data.
- (NSData * _Nullable)getCompressedImageData;

@end

NS_ASSUME_NONNULL_END

