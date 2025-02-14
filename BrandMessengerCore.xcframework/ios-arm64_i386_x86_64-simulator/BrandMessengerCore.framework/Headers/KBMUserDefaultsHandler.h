//
//  KBMUserDefaultsHandler.h
//  BrandMessengerCore
//
//  Created by shaik riyaz on 12/08/15.
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "BrandMessengerSettings.h"
#import <Foundation/Foundation.h>
#import "KBMUserOpenConversationResponse.h"
#import "KBMWidgetConfigurationResponse.h"
#import "KBMWidgetBrandStyleResponse.h"

static NSString* KBM_PASSWORD = @"KBM_PASSWORD";
static NSString* KBM_USER_AUTH_TOKEN = @"KBM_USER_AUTH_TOKEN";
static NSString* KBM_DEVICE_KEY = @"KBM_DEVICE_KEY";
/// Delegate protocol for encryption events.
@protocol KBMEncryptionDelegate <NSObject>
@required
-(bool)putSecureValueWithKey:(NSString*)key withValue:(NSString*)value;
@required
-(NSString*)getSecureValueWithKey:(NSString*)key;
@required
-(bool)hasSecureValueWithKey:(NSString*)key;
@required
-(void)clearAll;
@end

/// Logged in user disable the chat key.
static NSString *const KBM_DISABLE_USER_CHAT = @"DISABLE_CHAT_WITH_USER";

static NSString *const KBM_REGION_US = @"US";
static NSString *const KBM_REGION_APAC = @"APAC";
static NSString *const KBM_REGION_EU = @"EU";

@interface KBMUserDefaultsHandler : NSObject

+ (void)setConversationContactImageVisibility:(BOOL)visibility;

+ (BOOL)isConversationContactImageVisible;

+ (void)setBottomTabBarHidden:(BOOL)visibleStatus;

+ (BOOL)isBottomTabBarHidden;

+ (void)setNavigationRightButtonHidden:(BOOL)flagValue;
+ (BOOL)isNavigationRightButtonHidden;

+ (void)setBackButtonHidden:(BOOL)flagValue;

+ (BOOL)isBackButtonHidden;

+ (BOOL)isLoggedIn;

+ (void)clearKBMKeyDefaults;

+ (void)clearAll;

+ (NSString *)getCompanyKey;

+ (void)setCompanyKey:(NSString *)companyKey;

+ (NSString *)getApplicationKey;

+ (void)setApplicationKey:(NSString *)applicationKey;

+ (void)setEmailVerified:(BOOL)value;

+ (void)setApnDeviceToken:(NSString *)apnDeviceToken;

+ (NSString *)getApnDeviceToken;

+ (void)setBoolForKey_isConversationDbSynced:(BOOL)value;

+ (BOOL)getBoolForKey_isConversationDbSynced;

+ (void)setDeviceKeyString:(NSString *)deviceKeyString;

+ (void)setUserKeyString:(NSString *)userKeyString;

+ (void)setDisplayName:(NSString *)displayName;

+ (void)setEmailId:(NSString *)emailId;

+ (NSString *)getEmailId;

+ (NSString *)getDeviceKeyString;

+ (void)setUserId:(NSString *)userId;

+ (NSString *)getUserId;

+ (void)setLastSyncTime:(NSNumber *)lastSyncTime;

+ (void)setServerCallDoneForMSGList:(BOOL)value forContactId:(NSString *)constactId;

+ (BOOL)isServerCallDoneForMSGList:(NSString *)contactId;

+ (void)setProcessedNotificationIds:(NSMutableArray *)arrayWithIds;

+ (NSMutableArray*)getProcessedNotificationIds;

+ (BOOL)isNotificationProcessd:(NSString *)withNotificationId;

+ (NSNumber *)getLastSeenSyncTime;

+ (void)setLastSeenSyncTime:(NSNumber *)lastSeenTime;

+ (void)setShowLoadEarlierOption:(BOOL)value forContactId:(NSString *)constactId;

+ (BOOL)isShowLoadEarlierOption:(NSString *)constactId;

+ (void)setLastSyncChannelTime:(NSNumber *)lastSyncChannelTime;

+ (NSNumber *)getLastSyncChannelTime;

+ (NSNumber *)getLastSyncTime;

+ (NSString *)getUserKeyString;

+ (NSString *)getDisplayName;

+ (void)setUserBlockLastTimeStamp:(NSNumber *)lastTimeStamp;

+ (NSNumber *)getUserBlockLastTimeStamp;

+ (NSString *)getPassword;
+ (BOOL)setPassword:(NSString *)password;

+ (void)setAppModuleName:(NSString *)appModuleName;
+ (NSString *)getAppModuleName;

+ (BOOL)getContactViewLoaded;
+ (void)setContactViewLoadStatus:(BOOL)status;

+ (void)setServerCallDoneForUserInfo:(BOOL)value ForContact:(NSString *)contactId;
+ (BOOL)isServerCallDoneForUserInfoForContact:(NSString *)contactId;

+ (void)setBASEURL:(NSString *)baseURL;
+ (NSString *)getBASEURL;

+ (void)setMQTTURL:(NSString *)mqttURL;
+ (NSString *)getMQTTURL;

+ (void)setFILEURL:(NSString *)fileURL;
+ (NSString *)getFILEURL;

+ (void)setMQTTPort:(NSString *)portNumber;
+ (NSString *)getMQTTPort;

+ (void)setMQTTProtocol:(NSString *)protocol;
+ (NSString *)getMQTTProtocol;
+ (BOOL)isMQTTTLS;

+ (void)setUserTypeId:(short)type;
+ (short)getUserTypeId;

+ (NSNumber *)getLastMessageListTime;
+ (void)setLastMessageListTime:(NSNumber *)lastTime;

+ (BOOL)getFlagForAllConversationFetched;
+ (void)setFlagForAllConversationFetched:(BOOL)flag;

+ (NSInteger)getFetchConversationPageSize;
+ (void)setFetchConversationPageSize:(NSInteger)limit;

+ (short)getNotificationMode;
+ (void)setNotificationMode:(short)mode;

+ (short)getUserAuthenticationTypeId;
+ (void)setUserAuthenticationTypeId:(short)type;

+ (short)getUnreadCountType;
+ (void)setUnreadCountType:(short)mode;

+ (BOOL)isMsgSyncRequired;
+ (void)setMsgSyncRequired:(BOOL)flag;

+ (BOOL)isDebugLogsRequire;
+ (void)setDebugLogsRequire:(BOOL)flag;

+ (BOOL)getLoginUserConatactVisibility;
+ (void)setLoginUserConatactVisibility:(BOOL)flag;

+ (NSString *)getLoggedInUserStatus;
+ (void)setLoggedInUserStatus:(NSString *)status;

+ (BOOL)isUserLoggedInUserSubscribedMQTT;
+ (void)setLoggedInUserSubscribedMQTT:(BOOL)flag;

+ (NSString *)getEncryptionKey;
+ (void)setEncryptionKey:(NSString *)encrptionKey;

+ (short)getUserPricingPackage;
+ (void)setUserPricingPackage:(short)pricingPackage;

+ (BOOL)getEnableEncryption;
+ (void)setEnableEncryption:(BOOL)flag;

+ (void)setGoogleMapAPIKey:(NSString *)googleMapAPIKey;
+ (NSString *)getGoogleMapAPIKey;

+ (NSString *)getNotificationSoundFileName;
+ (void)setNotificationSoundFileName:(NSString *)notificationSoundFileName;

+ (BOOL)isContactServerCallIsDone;
+ (void)setContactServerCallIsDone:(BOOL)flag;

+ (BOOL)isContactScrollingIsInProgress;
+ (void)setContactScrollingIsInProgress:(BOOL)flag;

+ (void)setLastGroupFilterSyncTime:(NSNumber *)lastSyncTime;
+ (NSNumber *)getLastGroupFilterSyncTIme;

+ (void)setUserRoleType:(short)type;
+ (short)getUserRoleType;

+ (void)setPushNotificationFormat:(short)type;
+ (short)getPushNotificationFormat;
+ (void)setUserEncryption:(NSString *)encryptionKey;
+ (NSString *)getUserEncryptionKey;

+ (void)setLastSyncTimeForMetaData:(NSNumber *)metaDataLastSyncTime;
+ (NSNumber *)getLastSyncTimeForMetaData;

+ (void)disableChat:(BOOL)disable;
+ (BOOL)isChatDisabled;

+ (BOOL)setAuthToken:(NSString *)authToken;
+ (NSString *)getAuthToken;

+ (void)setAuthTokenCreatedAtTime:(NSNumber *)createdAtTime;
+ (NSNumber *)getAuthTokenCreatedAtTime;
+ (void)setAuthTokenValidUptoInMins:(NSNumber *)validUptoInMins;
+ (NSNumber *)getAuthTokenValidUptoMins;

+ (void)setInitialMessageListCallDone:(BOOL)flag;
+ (BOOL)isInitialMessageListCallDone;

+ (void)deactivateLoggedInUser:(BOOL)deactivate;
+ (BOOL)isLoggedInUserDeactivated;

+ (void)setChannelListLastSyncGeneratedTime:(NSNumber *)lastSyncGeneratedTime;
+ (NSNumber *)getChannelListLastSyncGeneratedTime;

+ (void)setVOIPDeviceToken:(NSString *)VOIPDeviceToken;
+ (NSString *)getVOIPDeviceToken;

+ (void)setDeviceNotificationMessageType:(short)type;
+ (short)getDeviceNotificationMessageType;

+ (void)setRegion:(NSString*) region;
+ (NSString*)getRegion;
+ (NSString *)getAuthHandlerURL;
+ (void)setCustomAuthHandlerUrl:(NSString *)baseURL;
+ (NSString*)getCustomAuthHandlerURL;

+ (void)setUseDebugUser:(BOOL) use;
+ (BOOL)getUseDebugUser;

+ (void)setDoNotAutosubscribeOnLaunch:(BOOL) subscribe;
+ (BOOL)getDoNotAutosubscribeOnLaunch;

+ (void)setEncryptionDelegate:(id<KBMEncryptionDelegate>)delegate;
+ (void)setHideQuickReply:(NSString*) identifier;
+ (BOOL)getHideQuickReply:(NSString*) identifier;

+ (void)setFetchNewOnChatOpen:(BOOL)enable;
+ (BOOL)getFetchNewOnChatOpen;

+ (void)setUsePersistentMessagesStorage:(BOOL)enable;
+ (BOOL)getUsePersistentMessagesStorage;

+ (void)setAnonymousUserLoggedIn:(BOOL)loggedIn;
+ (BOOL)isAnonymousUserLoggedIn;

+ (void)setUserExpirationTSSeconds:(NSNumber *)expirationTSSeconds;
+ (NSNumber *)getUserExpirationTSSeconds;

+(BOOL)isAnonymousUserExpired;

+(void)setUserOpenConversationResponse:(KBMUserOpenConversationResponse *)response;
+(KBMUserOpenConversationResponse *)getUserOpenConversationResponse;

+(void)setSendWelcomeMessageRequestAfterTimestamp:(NSNumber *)timestamp;
+(NSNumber *)getSendWelcomeMessageRequestAfterTimestamp;

+ (void)setWidgetId:(NSString *)widgetId;
+ (NSString *)getWidgetId;

+ (void)setConfigurationURL:(NSString *)configurationURL;
+ (NSString *)getConfigurationURL;

+ (void)setWidgetHash:(NSString *)widgetHash;
+ (NSString *)getWidgetHash;

+(void)setWidgetConfigurationResponse:(KBMWidgetConfigurationResponse *)response;
+(KBMWidgetConfigurationResponse *)getWidgetConfigurationResponse;

+ (void)setRichMessageSelectedCardIndex:(NSString *)identifier withIndex:(NSNumber *)index;
+ (NSNumber *)getRichMessageSelectedCardIndex:(NSString *)identifier;

+ (void)setRichMessageSelectedButtonIndex:(NSString *)identifier withIndex:(NSNumber *)index;
+ (NSNumber *)getRichMessageSelectedButtonIndex:(NSString *)identifier;

+ (void)setProactiveChatServerBaseURL:(NSString *)proactiveChatServerBaseURL;
+ (NSString *)getProactiveChatServerBaseURL;

+ (void)setBrandStyleHash:(NSString *)brandStyleHash;
+ (NSString *)getBrandStyleHash;

+ (void)setWidgetBrandStyleResponse:(KBMWidgetBrandStyleResponse *)response;
+ (KBMWidgetBrandStyleResponse *)getWidgetBrandStyleResponse;

+ (void) setIsAliveInterval:(NSInteger)interval;
+ (NSInteger) getIsAliveInterval;

@end
