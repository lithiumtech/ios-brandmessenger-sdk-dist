//
//  KBMMessageArrayWrapper.h
//  BrandMessengerCore
//
//  Created by devashish on 17/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "BrandMessengerSettings.h"
#import "KBMMessage.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// `KBMMessageArrayWrapper` class is is used for caching the message array data in NSMutableArray used for adding, removing, clearing messages from Array.
@interface KBMMessageArrayWrapper : NSObject

/// This will have array of `KBMMessage` object.
@property (nonatomic, strong) NSMutableArray *messageArray;

/// :nodoc:
@property (nonatomic, strong) NSString *dateCellText;

/// Used for checking two dates and comparing the current date is older then the new date.
/// @param older Pass the older time stamp.
/// @param newer Pass the newer time stamp.
- (BOOL)checkDateOlder:(NSNumber *)older andNewer:(NSNumber *)newer;

/// Used for fetching the updated Array of messages.
- (NSMutableArray *)getUpdatedMessageArray;

/// Used for add array of KBMMessage` objects to another Array.
/// @param paramMessageArray An Array of `KBMMessage` objects.
- (void)addObjectToMessageArray:(NSMutableArray *)paramMessageArray;

/// Used for adding `KBMMessage` object in Array
/// @param message Pass the `KBMMessage` object.
- (void)addKBMMessageToMessageArray:(KBMMessage *)message;

/// Used removing a array of `KBMMessage` objects from Array.
/// @param paramMessageArray An Array of `KBMMessage` objects.
- (void)removeObjectFromMessageArray:(NSMutableArray *)paramMessageArray;

/// Used for removing `KBMMessage` object from Array of Messages.
/// @param message Pass the  `KBMMessage` object that you want to delete.
- (void)removeKBMMessageFromMessageArray:(KBMMessage *)message;

/// Used for adding lastest message object to array.
/// @param paramMessageArray Pass Array of  `KBMMessage` object.
- (void)addLatestObjectToArray:(NSMutableArray *)paramMessageArray;

/// Used for getting date Message.
/// @param messageText Pass date message text.
/// @param message Pass the `KhMessage` object.
- (KBMMessage * _Nullable)getDatePrototype:(NSString *)messageText andKBMMessageObject:(KBMMessage *)message;

/// Used geeting the date for message.
/// @param message Pass the `KBMMessage` object.
- (NSString * _Nullable)msgAtTop:(KBMMessage *)message;

@end

NS_ASSUME_NONNULL_END
