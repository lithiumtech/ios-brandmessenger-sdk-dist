//
//  KBMJson.h
//  LearnApp
//
//  Created by devashish on 24/07/2015.
//  Copyright (c) 2015 devashish. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `KBMJson` is used for parsing json from server the each class can extend `KBMJson` to handle the parsing.
@interface KBMJson : NSObject

/// Use this `initWithJSONString` to parsing JSON string from server.
/// @param JSONString Pass the JSON string for parsing.
- (instancetype)initWithJSONString:(NSString *)JSONString;

/// JSON dictionary used for printing or converting to JSON data.
- (NSDictionary * _Nullable)dictionary;

/// Used for getting the string value from JSON.
/// @param jsonValue Pass the JSON value to this method for String.
/// @return It returns the String from JSON value.
- (NSString * _Nullable)getStringFromJsonValue:(id)jsonValue;

/// Used for getting the BOOL value from JSON value.
/// @param jsonValue Pass the JSON value to this method for BOOL.
/// @return It returns the BOOL from JSON value.
- (BOOL)getBoolFromJsonValue:(id)jsonValue;

/// Used for validating the JSON class is nil or NULL from NSDictionary.
/// @param jsonClass Pass the NSDictionary for validating.
- (BOOL)validateJsonClass:(NSDictionary *)jsonClass;

/// Used for validating the JSON Array class is nil or NULL from NSDictionary
/// @param jsonClass Pass the NSArray for validating.
- (BOOL)validateJsonArrayClass:(NSArray *)jsonClass;

/// Used for getting the short value from JSON value.
/// @param jsonValue Pass the JSON value to this method for short.
/// @return It returns the short from JSON value.
- (short)getShortFromJsonValue:(id)jsonValue;

/// Used for getting the NSNumber value from JSON value.
/// @param jsonValue Pass the JSON value to this method for NSNumber.
/// @return It returns the NSNumber from JSON value.
- (NSNumber * _Nullable)getNSNumberFromJsonValue:(id)jsonValue;

/// Used for getting the int value from JSON value.
/// @param jsonValue Pass the JSON value to this method for int.
/// @return It returns the int from JSON value.
- (int)getIntFromJsonValue:(id)jsonValue;

/// Used for getting the long value from JSON value.
/// @param jsonValue Pass the JSON value to this method for long.
/// @return It returns the long from JSON value.
- (long)getLongFromJsonValue:(id)jsonValue;

@end
NS_ASSUME_NONNULL_END
