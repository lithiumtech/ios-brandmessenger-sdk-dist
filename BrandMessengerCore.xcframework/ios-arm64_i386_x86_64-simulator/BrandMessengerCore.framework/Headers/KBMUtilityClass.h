//
//  KBMUtilityClass.h
//  BrandMessengerCore
//
//  Copyright (c) 2015 Khoros, LLC. All rights reserved.
//

#import "KBMMessage.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMUtilityClass` has utility methods releated to date, file, notification showing, image compression and other.
@interface KBMUtilityClass : NSObject

/// Used in method `getExactDate` access the message date.
@property (nonatomic, strong) NSString * _Nullable msgdate;

/// Used in method `getExactDate` access the message time.
@property (nonatomic, strong) NSString * _Nullable msgtime;

/// This method is used for formate the date in string.
/// @param timeInterval Time in milliseconds
/// @param formatString Date formate string.
+ (NSString *)formatTimestamp:(NSTimeInterval)timeInterval toFormat:(NSString *)formatString;

/// This method is used for generating a JSON string from dictionary.
/// @param dictionary Pass the JSON dictionary.
+ (NSString * _Nullable)generateJsonStringFromDictionary:(NSDictionary *)dictionary;

/// This method used for checking is current data is today or not.
/// @param todayDate Pass the date.
+ (BOOL)isToday:(NSDate *)todayDate;

/// This method used for getting file mime type.
/// @param filePath Pass the name of file.
+ (NSString * _Nullable)fileMIMEType:(NSString *)filePath;

/// This method used for size of text given the max width, font name and font size.
/// @param text Pass the message tex.
/// @param width Pass the max width.
/// @param fontName Pass the font name.
/// @param fontSize Pass the size of font.
+ (CGSize)getSizeForText:(NSString *)text maxWidth:(CGFloat)width font:(NSString *)fontName fontSize:(float)fontSize;

/// This method used for geeting location URL.
/// @param message Pass the `KBMMessage` object.
+ (NSString *)getLocationURL:(KBMMessage *)message;

/// This method used for geeting location URL.
/// @param message Pass the `KBMMessage` object.
/// @param withSize Pass the size of the image that you want to for location.
+ (NSString *)getLocationURL:(KBMMessage *)message size:(CGRect)withSize;

/// This method is used for showing the notification for if not in screen.
/// @param toastMessage Pass the notification title.
/// @param contactId Pass userId in case of one to one.
/// @param groupID Pass the groupId in case of group or channel.
/// @param mqttNotification Flag to identify the notification is from MQTT or APNs.
/// @param handler Once the completed showing the notification the handler will be called.
+ (void)thirdDisplayNotificationTS:(NSString *)toastMessage
                   andForContactId:(NSString * _Nullable)contactId
                       withGroupId:(NSNumber * _Nullable)groupID
              fromMqttNotification:(BOOL)mqttNotification
                 completionHandler:(void (^)(BOOL))handler;


/// This method is used for getting string time for image by appending the current time stamp.
+ (NSString *)getFileNameWithCurrentTimeStamp;

/// This method is used for geeting last seen date for user.
/// @param dateValue Pass the time in millisecond.
- (void)getExactDate:(NSNumber *)dateValue;

/// This method is used for checking the app is in debug mode or release.
+ (BOOL)isThisDebugBuild;

/// This method is used for geeting random UUID String.
+ (NSString *)getDevieUUID;
/// This method is used for getting the call duration time in string.
/// @param interval Pass the time in millisecond.
+ (NSString *)stringFromTimeInterval:(NSTimeInterval)interval;

/// This method is used geeting the file extension from file name.
/// @param fileName Pass the name of the file.
+ (NSString * _Nullable)getFileExtensionWithFileName:(NSString *)fileName;

/// This method is used URL of Application document directory.
+ (NSURL *)getDocumentDirectory;

/// This method is used URL of Apps group directory.
+ (NSURL * _Nullable)getAppsGroupDirectory;

/// This method is used for geeting file URL from Apps group directory.
/// @param path Pass the name of the file.
+ (NSURL * _Nullable)getAppsGroupDirectoryWithFilePath:(NSString *)path;

/// This method is used for geeting file URL from application directory if the file exist else it will be nil.
/// @param path Pass the name of the file.
+ (NSURL *)getApplicationDirectoryWithFilePath:(NSString *)path;

/// This method is used for compressing the image 50% for 10MB, 10% for more then 10MB.
/// @param data Pass image data to compress.
+ (NSData * _Nullable)compressImage:(NSData *)data;

/// This method is used for moving a file to documents directory.
/// @param url Pass the file URL that file you want to move.
+ (NSURL * _Nullable)moveFileToDocumentsWithFileURL:(NSURL *)url;

/// Used for geeting NSBundle of the Framework if its SPM it will use the dynamic bundle of SPM else it will pick from the Framework class bundle.
+ (NSBundle *)getBundle;

/// This method is used for getting a path of file from Application or from App groups directory.
/// @param imageFilePath Pass the name of the file it will look into the dcoument directory for the file.
+ (NSString *)getPathFromDirectory:(NSString *)imageFilePath;

/// This method used for creating an UIImage using video file path.
/// @param videoFilePATH Pass the video file dcoument directory path.
+ (UIImage * _Nullable)setVideoThumbnail:(NSString *)videoFilePATH;

/// This method is used for saving a image to dcoument.
/// @param image Pass the UIImage for saving to dcoument directory.
+ (NSString * _Nullable)saveImageToDocDirectory:(UIImage *)image;

/// This method is used for getting the App groups name the deatult App group name is `group.com.brandmessenger.share`
+ (NSString *)getAppGroupsName;

/// This method is used for generating random numbers between two given int.
/// @param minimum Pass the number where it should start from.
/// @param maximum Pass the number where it should end.
+ (NSInteger)randomNumberBetween:(NSInteger)minimum maxNumber:(NSInteger)maximum;

+ (KBMMessage *)addDefaultMetadataToMessage:(KBMMessage *) message;

@end

NS_ASSUME_NONNULL_END
