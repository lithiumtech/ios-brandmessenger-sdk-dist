//
//  KBMDataNetworkConnection.h
//  BrandMessengerCore
//
//  Created by devashish on 02/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMDataNetworkConnection : UIViewController

+ (BOOL)checkDataNetworkAvailable;
+ (BOOL)noInternetConnectionNotification;

@end

NS_ASSUME_NONNULL_END
