//
//  KBMConversationListMessages.h
//  BrandMessengerCore
//
//  Created by Sunil K on 21/10/24.
//

#import <Foundation/Foundation.h>
#import "KBMMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface KBMConversationListMessages : NSObject

/// Array of `KBMMessage` objects from channel active Messages.
@property (nonatomic) NSMutableArray <KBMMessage *> * _Nullable activeMessages;

/// Array of `KBMMessage` objects from channel archived Messages.
@property (nonatomic) NSMutableArray <KBMMessage *> * _Nullable archivedMessages;

@property(nonatomic) BOOL isConversationListEmpty;

@end

NS_ASSUME_NONNULL_END
