//
//  KBMAppStateUtility.h
//  BrandMessengerCore
//
//  Created by Paul Kwak on 2/28/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface KBMAppStateUtility : NSObject

@property (nonatomic) UIApplicationState applicationState;

+ (KBMAppStateUtility*)shared;
+ (UIApplicationState)getApplicationState;

@end
