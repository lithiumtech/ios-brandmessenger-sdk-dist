//
//  KBMWidgetBrandStyleResponse.h
//  BrandMessengerCore
//
//  Created by Sunil K on 01/03/23.
//

#import "KBMLanguageVariantModel.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KBMWidgetBrandStyleResponse : NSObject<NSCoding>

@property(nonatomic, strong) NSString * _Nullable brandColor;

@property(nonatomic, strong) NSString * _Nullable conversationColor;

@property(nonatomic, strong) NSString * _Nullable actionColor;

@property(nonatomic, strong) NSString * _Nullable headerText;

@property(nonatomic, strong) NSString * _Nullable businessName;

@property(nonatomic, strong) NSString * _Nullable businessIconUrl;

@property(nonatomic, strong) NSString * _Nullable introductionText;

@property(nonatomic, strong) NSString * _Nullable inboxChatIntroText;

@property(nonatomic, strong) NSString * _Nullable inboxChatRecentListTitle;

@property(nonatomic, strong) NSString * _Nullable inboxChatArchivedListTitle;

@property(nonatomic, strong) NSString * _Nullable inboxChatNewConversationButton;

@property(nonatomic, strong) NSString * _Nullable interfaceLanguage;

@property(nonatomic) BOOL fixedIntroPane;

@property(nonatomic, strong) NSMutableArray * _Nullable headerTextLanguageVariants;

@property(nonatomic, strong) NSMutableArray * _Nullable inboxChatIntroTextLanguageVariants;

@property(nonatomic, strong) NSMutableArray * _Nullable inboxChatRecentListTitleLanguageVariants;

@property(nonatomic, strong) NSMutableArray * _Nullable inboxChatArchivedListTitleLanguageVariants;

@property(nonatomic, strong) NSMutableArray * _Nullable inboxChatNewConversationButtonLanguageVariants;

- (instancetype)initWithJSONDictionary:(NSDictionary *)dictionary;

- (NSMutableArray<KBMLanguageVariantModel *> * _Nullable)getHeaderLanguageVariants;

- (NSMutableArray<KBMLanguageVariantModel *> * _Nullable)getInboxChatIntroTextLanguageVariants;

- (NSMutableArray<KBMLanguageVariantModel *> * _Nullable)getInboxChatRecentListTitleLanguageVariants;

- (NSMutableArray<KBMLanguageVariantModel *> * _Nullable)getInboxChatArchivedListTitleLanguageVariants;

- (NSMutableArray<KBMLanguageVariantModel *> * _Nullable)getInboxChatNewConversationButtonLanguageVariants;

@end

NS_ASSUME_NONNULL_END
