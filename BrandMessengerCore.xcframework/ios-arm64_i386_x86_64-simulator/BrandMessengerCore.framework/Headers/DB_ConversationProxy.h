//
//  DB_ConversationProxy.h
//  BrandMessengerCore
//
//  Created by devashish on 13/01/2016.
//  Copyright © 2016 Khoros, LLC. All rights reserved.
//

#import <CoreData/CoreData.h>

/// `DB_ConversationProxy` is DB class used for storing the conversation details in core data.
@interface DB_ConversationProxy : NSManagedObject

/// Sets the conversation id.
@property (nonatomic, strong) NSNumber *iD;

/// Sets the topicId.
@property (nonatomic, strong) NSString *topicId;

/// Sets the groupId of conversation.
@property (nonatomic, strong) NSNumber *groupId;

/// Sets the userId for the conversation for topic.
@property(nonatomic,strong) NSString *userId;

/// Sets the created at time of conversation.
@property (nonatomic,retain) NSNumber *created;

/// It will have YES in case of conversation is closed else it will be NO.
@property(nonatomic,retain) NSNumber *closed;

/// Topic detail json string.
@property(nonatomic,strong) NSString *topicDetailJson;

@end
