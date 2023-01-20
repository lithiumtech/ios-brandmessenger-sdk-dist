//
//  BrandMessengerSettings.h
//  BrandMessengerCore
//
//  Created by devashish on 20/11/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

static NSString *const KBM_MESSAGE_META_DATA_KEY = @"com.brandmessenger.KBM_MESSAGE_META_DATA_KEY";

/// `BrandMessengerSettings` is settings class for BrandMessengerUI Pre-build UI
@interface BrandMessengerSettings : NSObject

/// instance method for user defaults of `BrandMessengerSettings`.
@property (strong, nonatomic) NSUserDefaults *userDefaults;

+ (void)setMaxImageSizeForUploadInMB:(NSInteger)maxFileSize;

+ (NSInteger)getMaxImageSizeForUploadInMB;

+ (void)setMaxCompressionFactor:(double)maxCompressionRatio;

+ (double)getMaxCompressionFactor;

+ (void)setFilterContactsStatus:(BOOL)flag;

+ (BOOL)getFilterContactsStatus;

+ (void)setStartTime:(NSNumber *)startTime;

+ (NSNumber *)getStartTime;

+ (void)setOnlineContactLimit:(NSInteger)limit;
+ (NSInteger)getOnlineContactLimit;

+ (void)setContextualChat:(BOOL)option;
+ (BOOL)getContextualChatOption;

+ (void)setCallOption:(BOOL)flag;
+ (BOOL)getCallOption;

// Enable/Diable Notification Sound
+ (void)enableNotificationSound;
+ (void)disableNotificationSound;
// Enable/Diable Notification Complete
+ (void)enableNotification;
+ (void)disableNotification;

+ (void)setGroupOfTwoFlag:(BOOL)flag;
+ (BOOL)getGroupOfTwoFlag;

+ (NSString *)getCustomNavigationControllerClassName;
+ (void)setNavigationControllerClassName:(NSString *)className;

+ (BOOL)getSubGroupLaunchFlag;
+ (void)setSubGroupLaunchFlag:(BOOL)flag;

+ (NSArray *)getListOfViewControllers;
+ (void)setListOfViewControllers:(NSArray *)viewList;

+ (void)setMsgContainerVC:(NSString *)className;
+ (NSString *)getMsgContainerVC;

+ (NSString *)getAudioVideoClassName;
+ (void)setAudioVideoClassName:(NSString *)className;

+ (NSString *)getClientStoryBoard;
+ (void)setClientStoryBoard:(NSString *)storyboard;

+ (BOOL)isAudioVideoEnabled;
+ (void)setAudioVideoEnabled:(BOOL)flag;

+ (void)enableOrDisableContactsGroup:(BOOL)flag;

+ (BOOL)isContactsGroupEnabled;

+ (void)setContactsGroupId:(NSString *)contactsGroupId;

+ (NSString *)getContactsGroupId;

+ (void)setContactGroupIdList:(NSArray *)contactIdList;

+ (NSArray*)getContactGroupIdList;

+ (BOOL)isSwiftFramework;
+ (void)setSwiftFramework:(BOOL)flag;

+ (BOOL)isStorageServiceEnabled;
+ (void)enableStorageService:(BOOL)flag;

+ (BOOL)isGoogleCloudServiceEnabled;
+ (void)enableGoogleCloudService:(BOOL)flag;

+ (BOOL)isConversationCloseButtonEnabled;
+ (void)setConversationCloseButton:(BOOL)flag;

+ (void) setDefaultGroupType:(NSInteger)type;
+ (NSInteger) getDefaultGroupType;
+ (void) enableSaveVideosToGallery:(BOOL)flag;
+ (BOOL) isSaveVideoToGalleryEnabled;

+ (void)setUserRoleName:(NSString *)roleName;
+ (NSString *)getUserRoleName;

+ (void)setDeleteConversationOption:(BOOL)flag;
+ (BOOL)isDeleteConversationOptionEnabled;

+ (NSString *)getLocalizableName;
+ (void)setLocalizableName:(NSString *)localizableName;

+ (void)setCategoryName:(NSString *)categoryName;
+ (NSString *)getCategoryName;

+ (NSArray *)metadataKeysToHideMessages;
+ (void)hideMessagesWithMetadataKeys:(NSArray *)keys;

+ (void)clearAll;

+ (void)setupSuiteAndMigrate;
+ (NSString *)getShareExtentionGroup;

+ (void)disableInAppNotificationTap:(BOOL)flag;
+ (BOOL)isInAppNotificationTapDisabled;

+ (void)setMessageMetadata:(NSMutableDictionary *)messageMetadata;
+ (NSMutableDictionary *)getMessageMetadata;

/// Support contact userId can be set for  showing the support contact at top in contact screen.
+ (void)setSupportContactUserId:(NSString *)userId;
+ (NSString *)getSupportContactUserId;

@end
