//
//  KBMPushAssist.h
//  BrandMessengerCore
//
//  Created by Divjyot Singh on 07/01/16.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface KBMPushAssist : NSObject

@property(nonatomic, readonly, strong) UIViewController * _Nullable topViewController;

- (void)assist:(NSString *)notiMsg withUserInfo:(NSMutableDictionary *)dict ofUser:(NSString * _Nullable)userId;
- (UIViewController * _Nullable)topViewController;
- (BOOL)isOurViewOnTop;
- (BOOL)isMessageContainerOnTop;
- (BOOL)isVOIPViewOnTop;

+ (BOOL)isViewObjIsMsgContainerVC:(UIViewController *)viewObj;

@end

NS_ASSUME_NONNULL_END
