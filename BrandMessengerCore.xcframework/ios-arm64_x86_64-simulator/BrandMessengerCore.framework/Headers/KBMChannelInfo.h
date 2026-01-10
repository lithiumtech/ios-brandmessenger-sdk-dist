//
//  KBMChannelInfo.h
//  BrandMessengerCore
//
//  Created by devashish on 28/12/2015.
//  Copyright © 2015 Khoros, LLC. All rights reserved.
//

#import "KBMJson.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMChannelInfo` class is used for creating new channel conversation.
///
/// The groupName, groupMemberList and type are mandatory fields.
///
/// KBMChannelInfo can be created as shown below:
///
///@code
/// @import BrandMessengerCore;
///
/// // Channel members userId.
/// NSMutableArray *channelMemberArray = [[NSMutableArray alloc] init];
/// [channelMemberArray addObject:@"MemberUserId1"];
/// [channelMemberArray addObject:@"MemberUserId2"];
///
/// // Custom metadata in Channel.
/// NSMutableDictionary *channelMetadata = [[NSMutableDictionary alloc] init];
/// [channelMetadata setValue:@"Value 1" forKey:@"Key1"];
/// [channelMetadata setValue:@"Value 2" forKey:@"Key2"];
///
/// // Creating an Channel info.
/// KBMChannelInfo *channelInfo = [[KBMChannelInfo alloc] init];
/// channelInfo.groupName = @"Home Channel"; // Channel name.
/// channelInfo.imageUrl = @"http://mywebsite.com/channel_profile_picture.jpg"; // Channel Image URL.
/// channelInfo.groupMemberList = channelMemberArray; // Channel members userId array.
/// channelInfo.type = PUBLIC; // Channel type.
/// channelInfo.metadata = channelMetadata;
///
///@endcode
@interface KBMChannelInfo : KBMJson

/// Sets the channel or group name.
@property (nonatomic, strong) NSString *groupName;

/// Sets your client group id.
@property (nonatomic, strong) NSString * _Nullable clientGroupId;

/// Sets the members userId that you want to add to the channel or group.
@property (nonatomic, strong) NSMutableArray *groupMemberList;

/// Sets the Image URL for channel or group.
@property (nonatomic, strong) NSString * _Nullable imageUrl;

/// Sets the admin userId of the channel or group.
@property (nonatomic, strong) NSString * _Nullable admin;

/// :nodoc:
@property (nonatomic, strong) NSString * _Nullable parentClientGroupId;

/// :nodoc:
@property (nonatomic, strong) NSNumber * _Nullable parentKey;

/// Set the type of the channel.
///
/// This are types of channel or group:
/// PRIVATE = 1, // Only admin can add members.
/// PUBLIC = 2, // Any one can join the channel.
/// BROADCAST = 5, // One way brodcasting messages.
/// GROUP_OF_TWO = 7, // Channel of two members its same as one to one conversation.
/// CONTACT_GROUP = 9 // Is used in categorized contact channel can be used in showing contacts.
@property(nonatomic) short type;

/// Sets the channel meta data.
@property (nonatomic, strong) NSMutableDictionary * _Nullable metadata;

/// Sets the array of the channel users of type `KBMGroupUser`.
@property (nonatomic, strong) NSMutableArray * _Nullable groupRoleUsers;

@end

NS_ASSUME_NONNULL_END
