//
//  BrandMessengerSettings.h
//  BrandMessengerCore
//
//  Created by devashish on 20/11/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// `BrandMessengerSettings` is settings class for BrandMessengerUI Pre-build UI
@interface BrandMessengerSettings : NSObject

/// instance method for user defaults of `BrandMessengerSettings`.
@property (strong, nonatomic) NSUserDefaults *userDefaults;

+ (void)setFontFace:(NSString *)fontFace;
+ (NSString *)getFontFace;

// works with font face for iOS 11, uses system font face for iOS 10, being ignored for versions below
+ (void)setChatCellFontTextStyle:(NSString *)fontTextStyle;
+ (NSString *)getChatCellFontTextStyle;

// works with font face for iOS 11, uses system font face for iOS 10, being ignored for versions below
+ (void)setChatChannelCellFontTextStyle:(NSString *)fontTextStyle;
+ (NSString *)getChatChannelCellFontTextStyle;

+ (void)setUserProfileHidden:(BOOL)flag;

+ (BOOL)isUserProfileHidden;

+ (void)setColorForSendMessages:(UIColor *)sendMsgColor;

+ (void)setColorForReceiveMessages:(UIColor *)receiveMsgColor;

+ (UIColor *)getSendMsgColor;

+ (UIColor *)getReceiveMsgColor;

+ (void)setColorForNavigation:(UIColor *)barColor;

+ (UIColor *)getColorForNavigation;

+ (void)setColorForNavigationItem:(UIColor *)barItemColor;

+ (UIColor *)getColorForNavigationItem;

+ (void)hideRefreshButton:(BOOL)state;

+ (BOOL)isRefreshButtonHidden;

+ (void)setTitleForConversationScreen:(NSString *)titleText;

+ (NSString *)getTitleForConversationScreen;

+ (void)setTitleForBackButtonMsgVC:(NSString *)backButtonTitle;
+ (NSString *)getTitleForBackButtonMsgVC;

+ (void)setNotificationTitle:(NSString *)notificationTitle;

+ (NSString *)getNotificationTitle;

+ (void)setMaxImageSizeForUploadInMB:(NSInteger)maxFileSize;

+ (NSInteger)getMaxImageSizeForUploadInMB;

+ (void)setMaxCompressionFactor:(double)maxCompressionRatio;

+ (double)getMaxCompressionFactor;

+ (void)setGroupOption:(BOOL)option;

+ (BOOL)getGroupOption;

+ (void)setMultipleAttachmentMaxLimit:(NSInteger)limit;

+ (NSInteger)getMultipleAttachmentMaxLimit;

+ (void)setFilterContactsStatus:(BOOL)flag;

+ (BOOL)getFilterContactsStatus;

+ (void)setStartTime:(NSNumber *)startTime;

+ (NSNumber *)getStartTime;

+ (void)setChatWallpaperImageName:(NSString *)imageName;

+ (NSString *)getChatWallpaperImageName;

+ (void)setCustomMessageBackgroundColor:(UIColor *)color;

+ (UIColor *)getCustomMessageBackgroundColor;

+ (void)setCustomMessageTextColor:(UIColor *)color;
+ (UIColor *)getCustomMessageTextColor;

+ (void)setGroupExitOption:(BOOL)option;
+ (BOOL)getGroupExitOption;

+ (void)setGroupMemberAddOption:(BOOL)option;
+ (BOOL)getGroupMemberAddOption;

+ (void)setGroupMemberRemoveOption:(BOOL)option;
+ (BOOL)getGroupMemberRemoveOption;

+ (void)setOnlineContactLimit:(NSInteger)limit;
+ (NSInteger)getOnlineContactLimit;

+ (NSString *)getCustomClassName;
+ (void)setCustomClassName:(NSString *)className;

// When a user taps on title view in ALChatViewController  with this option you can receive notification with name thirdPartyDetailVCNotification with options to show custom group detail VC
// might be blocked by "setGroupInfoDisabled" and "setReceiverUserProfileOption"
+ (BOOL)getOptionToPushNotificationToShowCustomGroupDetalVC;
+ (void)setOptionToPushNotificationToShowCustomGroupDetalVC:(BOOL)option;

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

+ (UIColor *)getColorForSendButton;
+ (void)setColorForSendButton:(UIColor *)color;

+ (UIColor *)getColorForTypeMsgBackground;
+ (void)setColorForTypeMsgBackground:(UIColor *)viewColor;

+ (UIColor *)getBGColorForTypingLabel;
+ (void)setBGColorForTypingLabel:(UIColor *)bgColor;

+ (UIColor *)getTextColorForTypingLabel;
+ (void)setTextColorForTypingLabel:(UIColor *)txtColor;

+ (BOOL)getVisibilityNoConversationLabelChatVC;
+ (void)setVisibilityNoConversationLabelChatVC:(BOOL)flag;

+ (BOOL)getVisibilityForOnlineIndicator;
+ (void)setVisibilityForOnlineIndicator:(BOOL)flag;

+ (BOOL)getVisibilityForNoMoreConversationMsgVC;
+ (void)setVisibilityForNoMoreConversationMsgVC:(BOOL)flag;

+ (BOOL)isRefreshChatButtonEnabledInMsgVc;
+ (void)enableRefreshChatButtonInMsgVc:(BOOL)flag;

+ (UIColor *)getColorForToastText;
+ (void)setColorForToastText:(UIColor *)toastTextColor;

+ (UIColor *)getColorForToastBackground;
+ (void)setColorForToastBackground:(UIColor *)toastBGColor;

+ (UIColor *)getSendMsgTextColor;
+ (void)setSendMsgTextColor:(UIColor *)sendMsgColor;

+ (UIColor *)getReceiveMsgTextColor;
+ (void)setReceiveMsgTextColor:(UIColor *)receiveMsgColor;

+ (UIColor *)getMsgTextViewBGColor;
+ (void)setMsgTextViewBGColor:(UIColor *)color;

+ (UIColor *)getPlaceHolderColor;
+ (void)setPlaceHolderColor:(UIColor *)color;

+ (UIColor *)getUnreadCountLabelBGColor;
+ (void)setUnreadCountLabelBGColor:(UIColor *)color;

+ (UIColor *)getStatusBarBGColor;
+ (void)setStatusBarBGColor:(UIColor *)color;

+ (UIStatusBarStyle)getStatusBarStyle;
+ (void)setStatusBarStyle:(UIStatusBarStyle)style;

+ (void)setMaxTextViewLines:(int)numberOfLines;
+ (int)getMaxTextViewLines;

+ (BOOL)getMessageAbuseMode;
+ (void)setMessageAbuseMode:(BOOL)flag;

+ (UIColor *)getDateColor;
+ (void)setDateColor:(UIColor *)dateColor;

+ (UIColor *)getMsgDateColor;
+ (void)setMsgDateColor:(UIColor *)dateColor;

+ (BOOL)getReceiverUserProfileOption;
+ (void)setReceiverUserProfileOption:(BOOL)flag;

+ (float)getCustomMessageFontSize;
+ (void)setCustomMessageFontSize:(float)fontSize;

+ (NSString *)getCustomMessageFont;
+ (void)setCustomMessageFont:(NSString *)font;

+ (void) setGroupInfoDisabled:(BOOL)flag;
+ (BOOL) isGroupInfoDisabled;

+ (void) setGroupInfoEditDisabled:(BOOL)flag;
+ (BOOL) isGroupInfoEditDisabled;

+ (void)setGroupOfTwoFlag:(BOOL)flag;
+ (BOOL)getGroupOfTwoFlag;

+ (void)setBroadcastGroupEnable:(BOOL)flag;
+ (BOOL)isBroadcastGroupEnable;

+ (void) setContactTypeToFilter:(NSMutableArray *)arrayWithIds;
+ (NSMutableArray*) getContactTypeToFilter;

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

+ (UIImage *)getChatListTabIcon;
+ (void)setChatListTabIcon:(NSString *)imageName;

+ (UIImage *)getProfileTabIcon;
+ (void)setProfileTabIcon:(NSString *)imageName;

+ (BOOL)isChatOnTapUserProfile;
+ (void)openChatOnTapUserProfile:(BOOL)flag;

+ (BOOL)isReplyOptionEnabled;
+ (void)replyOptionEnabled:(BOOL)flag;

+ (BOOL)isAudioVideoEnabled;
+ (void)setAudioVideoEnabled:(BOOL)flag;

+ (void)enableOrDisableContactsGroup:(BOOL)flag;

+ (BOOL)isContactsGroupEnabled;

+ (void)setContactsGroupId:(NSString *)contactsGroupId;

+ (NSString *)getContactsGroupId;

+ (void)setContactGroupIdList:(NSArray *)contactIdList;

+ (NSArray*)getContactGroupIdList;

+ (void)forwardOptionEnableOrDisable:(BOOL)flag;

+ (BOOL)isForwardOptionEnabled;

+ (BOOL)isSwiftFramework;
+ (void)setSwiftFramework:(BOOL)flag;

+ (BOOL)isStorageServiceEnabled;
+ (void)enableStorageService:(BOOL)flag;

+ (BOOL)isGoogleCloudServiceEnabled;
+ (void)enableGoogleCloudService:(BOOL)flag;

+ (BOOL)isConversationCloseButtonEnabled;
+ (void)setConversationCloseButton:(BOOL)flag;

+ (void)setHideAttachmentsOption:(NSArray *)array;

+ (NSArray*)getHideAttachmentsOption;

+ (BOOL)isCameraOptionHidden;
+ (BOOL)isPhotoGalleryOptionHidden;
+ (BOOL)isSendAudioOptionHidden;
+ (BOOL)isSendVideoOptionHidden;
+ (BOOL)isLocationOptionHidden;
+ (BOOL)isBlockUserOptionHidden;
+ (BOOL)isShareContactOptionHidden;
+ (BOOL)isAttachmentButtonHidden;
+ (BOOL)isDocumentOptionHidden;
+ (void) setDefaultGroupType:(NSInteger)type;
+ (NSInteger) getDefaultGroupType;
+ (void) enableSaveVideosToGallery:(BOOL)flag;
+ (BOOL) isSaveVideoToGalleryEnabled;
+ (void) enableQuickAudioRecording:(BOOL)flag;
+ (BOOL) isQuickAudioRecordingEnabled;

+ (void)setUserRoleName:(NSString *)roleName;
+ (NSString *)getUserRoleName;

+ (void)setDropShadowInNavigationBar:(BOOL)flag;
+ (BOOL)isDropShadowInNavigationBarEnabled;

+ (void)setDeleteConversationOption:(BOOL)flag;
+ (BOOL)isDeleteConversationOptionEnabled;

+ (NSString *)getLocalizableName;
+ (void)setLocalizableName:(NSString *)localizableName;
+ (void)setTemplateMessages:(NSMutableDictionary *)dictionary;
+ (NSMutableDictionary*) getTemplateMessages;

+ (BOOL)isTemplateMessageEnabled;
+ (void)enableTeamplateMessage:(BOOL)flag;

+ (void)setCategoryName:(NSString *)categoryName;
+ (NSString *)getCategoryName;

+ (BOOL)isContactSearchEnabled;
+ (void)enableContactSearch:(BOOL)flag;

+ (BOOL)isChannelMembersInfoInNavigationBarEnabled;
+ (void)showChannelMembersInfoInNavigationBar:(BOOL)flag;

+ (UIColor *)getTabBarBackgroundColour;
+ (void) setTabBarBackgroundColour:(UIColor *)color;
+ (UIColor *)getTabBarSelectedItemColour;
+ (void) setTabBarSelectedItemColour:(UIColor *)color;
+ (UIColor *)getTabBarUnSelectedItemColour;
+ (void) setTabBarUnSelectedItemColour:(UIColor *)color;
+ (UIColor *)getAttachmentIconColour;
+ (void)setAttachmentIconColour:(UIColor *)color;
+ (UIColor *)getSendIconColour;
+ (void) setSendIconColour:(UIColor *)color;
+ (UIColor *)getMessageSubtextColour;
+ (void)setMessageSubtextColour:(UIColor *)color;
+ (UIColor *)getProfileMainColour;
+ (void) setProfileMainColour:(UIColor *)color;
+ (UIColor *)getProfileSubColour;
+ (void) setProfileSubColour:(UIColor *)color;
+ (UIColor *)getNewContactMainColour;
+ (void) setNewContactMainColour:(UIColor *)color;
+ (UIColor *)getNewContactSubColour;
+ (void)setNewContactSubColour:(UIColor *)color;
+ (UIColor *)getNewContactTextColour;
+ (void) setNewContactTextColour:(UIColor *)color;
+ (UIColor *)getMessageListTextColor;
+ (void) setMessageListTextColor:(UIColor *)color;
+ (UIColor *)getMessagesViewBackgroundColour;
+ (void)setMessagesViewBackgroundColour:(UIColor *)color;
+ (UIColor *)getChatViewControllerBackgroundColor;
+ (void) setChatViewControllerBackgroundColor:(UIColor *)color;
+ (UIColor *)getSearchBarTintColour;
+ (void)setSearchBarTintColour:(UIColor *)color;

+ (NSArray *)metadataKeysToHideMessages;
+ (void)hideMessagesWithMetadataKeys:(NSArray *)keys;

+ (BOOL)isMultiSelectGalleryViewDisabled;
+ (void)disableMultiSelectGalleryView:(BOOL)enabled;

+ (BOOL)is5MinVideoLimitInGalleryEnabled;
+ (void)enable5MinVideoLimitInGallery:(BOOL)enabled;

+ (void)setBackgroundColorForAttachmentPlusIcon:(UIColor *)backgroundColor;
+ (UIColor *)getBackgroundColorForAttachmentPlusIcon;
+ (void)clearAll;

+ (BOOL)isTextStyleInCellEnabled;
+ (void)enableTextStyleCell:(BOOL)enabled;

+ (void)setChatCellTextFontSize:(float)fontSize;
+ (float)getChatCellTextFontSize;

+ (void)setChannelCellTextFontSize:(float)fontSize;
+ (float)getChannelCellTextFontSize;

+ (void)setBackgroundColorForAudioRecordingView:(UIColor *)backgroundColor;
+ (UIColor *)getBackgroundColorForAudioRecordingView;

+ (void)setColorForSlideToCancelText:(UIColor *)color;
+ (UIColor *)getColorForSlideToCancelText;

+ (void)setColorForAudioRecordingText:(UIColor *)color;
+ (UIColor *)getColorForAudioRecordingText;

+ (void)setFontForAudioView:(NSString *)font;
+ (NSString *)getFontForAudioView;

+ (void)enableNewAudioDesign:(BOOL)enable;
+ (BOOL)isNewAudioDesignEnabled;

+ (void)setBackgroundColorForReplyView:(UIColor *)backgroudColor;
+ (UIColor *)getBackgroundColorForReplyView;

+ (void)setHideMediaSelectOption:(NSMutableArray *)array;
+ (NSArray *)getHideMediaSelectOption;

+ (BOOL)imagesHiddenInGallery;
+ (BOOL)videosHiddenInGallery;

+ (void)setTextColorForMessageTextView:(UIColor *)txtColor;
+ (UIColor *)getTextColorForMessageTextView;

+ (void)setChannelActionMessageBgColor:(UIColor *)txtColor;
+ (UIColor *)getChannelActionMessageBgColor;

+ (void)setChannelActionMessageTextColor:(UIColor *)txtColor;
+ (UIColor *)getChannelActionMessageTextColor;

+ (void)setUserIconFirstNameColorCodes:(NSMutableDictionary *)nsMutableDictionary;
+ (NSMutableDictionary*) getUserIconFirstNameColorCodes;

// Enable/Disable unblock users from sendMessageTextView
+ (void)setIsUnblockInChatDisabled:(BOOL)flag;
+ (BOOL)isUnblockInChatDisabled;

+ (void)setupSuiteAndMigrate;
+ (NSString *)getShareExtentionGroup;

+ (BOOL)isDocumentOptionEnabled;
+ (void)enableDocumentOption:(BOOL)flag;

+ (BOOL)isAddContactButtonForSenderDisabled;
+ (void)disableAddContactButtonForSender;

+ (void)setColorForSentContactMsgLabel:(UIColor *)sentContactLabelMsgColor;
+ (void)setColorForReceivedContactMsgLabel:(UIColor *)receivedMsgColor;

+ (UIColor *)getSentContactMsgLabelColor;
+ (UIColor *)getReceivedContactMsgLabelColor;

+ (void)setImagePreviewBackgroundColor:(UIColor *)color;
+ (UIColor *)getImagePreviewBackgroundColor;

+ (void)restrictedMessageRegexPattern:(NSString *)pattern;
+ (NSString *)getRestrictedMessageRegexPattern;

+ (void)disableInAppNotificationTap:(BOOL)flag;
+ (BOOL)isInAppNotificationTapDisabled;

+ (void)disableGroupListingTab:(BOOL)flag;
+ (BOOL)isGroupListingTabDisabled;

+ (void)enableMessageSearch:(BOOL)flag;

+ (BOOL)isMessageSearchEnabled;

+ (void)enableMessageDeleteForAllOption:(BOOL)flag;
+ (BOOL)isMessageDeleteForAllEnabled;

+ (void)setPhotosSelectionLimit:(NSInteger)selectionLimit;
+ (NSInteger)getPhotosSelectionLimit;

+ (void)setMessageMetadata:(NSMutableDictionary *)messageMetadata;
+ (NSMutableDictionary *)getMessageMetadata;

/// Support contact userId can be set for  showing the support contact at top in contact screen.
+ (void)setSupportContactUserId:(NSString *)userId;
+ (NSString *)getSupportContactUserId;

@end
