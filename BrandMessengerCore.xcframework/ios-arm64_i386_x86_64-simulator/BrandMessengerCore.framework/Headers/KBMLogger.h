//
//  KBMLogger.h
//
//  Created by Matt Coneybeare on 09/1/13.
//  Copyright (c) 2013 Urban Apps, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// `KBMLoggerVerbosity` levels for showing  none, basic, plain or full logs.
typedef enum {
    KBMLoggerVerbosityNone = 0,
    KBMLoggerVerbosityPlain,
    KBMLoggerVerbosityBasic,
    KBMLoggerVerbosityFull
} KBMLoggerVerbosity;

/// `KBMLoggerSeverity` log levels for showing in Xcode log console.
typedef enum {
    /// Unset means it is not factored in on the decision to log, defaulting to the production vs debug and user overrides.
    KBMLoggerSeverityUnset = 0,
    /// Lowest log level.
    KBMLoggerSeverityDebug,
    KBMLoggerSeverityInfo,
    KBMLoggerSeverityWarn,
    KBMLoggerSeverityError,
    /// Highest log level.
    KBMLoggerSeverityFatal
} KBMLoggerSeverity;


#define KBMSLogFull( s, f, ... )	[KBMLogger logWithVerbosity:KBMLoggerVerbosityFull\
												  severity:s\
												formatArgs:@[\
															self,\
															[[NSString stringWithUTF8String:__FILE__] lastPathComponent],\
															[NSNumber numberWithInt:__LINE__],\
															NSStringFromSelector(_cmd),\
															[NSString stringWithFormat:(f), ##__VA_ARGS__]\
															]\
								]

#define KBMSLogBasic( s, f, ... ) [KBMLogger logWithVerbosity:KBMLoggerVerbosityBasic\
												   severity:s\
												 formatArgs:@[\
															 [[NSString stringWithUTF8String:__FILE__] lastPathComponent],\
															 [NSNumber numberWithInt:__LINE__],\
															 [NSString stringWithFormat:(f), ##__VA_ARGS__]\
															 ]\
								 ]

#define KBMSLogPlain( s, f, ... ) [KBMLogger logWithVerbosity:KBMLoggerVerbosityPlain\
												   severity:s\
												 formatArgs:@[\
															 [NSString stringWithFormat:(f), ##__VA_ARGS__]\
															]\
								 ]

#define KBMLogFull( format, ... )			KBMSLogFull( KBMLoggerSeverityUnset, format, ##__VA_ARGS__ )
#define KBMLogBasic( format, ... )			KBMSLogBasic( KBMLoggerSeverityUnset, format, ##__VA_ARGS__ )
#define KBMLogPlain( format, ... )			KBMSLogPlain( KBMLoggerSeverityUnset, format, ##__VA_ARGS__ )

#define KBMLog( format, ... )				KBMLogBasic( format, ##__VA_ARGS__ )
#define KBMSLog( severity, format, ... )		KBMSLogBasic( severity, format, ##__VA_ARGS__ )

#ifdef KBMLogGER_SWIZZLE_NSLOG
#define NSLog( s, ... )		KBMLog( s, ##__VA_ARGS__ )
#endif

/// This is just convenience
#define NSStringFromBool(b) (b ? @"YES" : @"NO")

/// This is the default NSUserDefaults key
static NSString *const KBMLogger_LoggingEnabled = @"KBMLogger_LoggingEnabled";

/// `KBMLogger` is used for logging logs of BrandMessenger
@interface KBMLogger : NSObject
/// Returns the format string for the verbosity. See [+ initialize] for defaults
+ (NSString *)formatForVerbosity:(KBMLoggerVerbosity)verbosity;
/// Overrides the default formats for verbosities.
+ (void)setFormat:(NSString *)format
     forVerbosity:(KBMLoggerVerbosity)verbosity;
/// Resets the formats back to KBMLogger defaults.
+ (void)resetDefaultLogFormats;
/// Set the Minimum for showing logs.
+ (void)setMinimumSeverity:(KBMLoggerSeverity)severity;
/// Defaults to KBMLoggerSeverityUnset (not used in determining whether or not to log).
+ (KBMLoggerSeverity)minimumSeverity;
/// Yes if minimumSeverity has been set.
+ (BOOL)usingSeverityFiltering;
/// Yes if severity is greater than or equal to minimumSeverity
+ (BOOL)meetsMinimumSeverity:(KBMLoggerSeverity)severity;
/// Returns YES when DEBUG is not present in the Preprocessor Macros
+ (BOOL)isProduction;
/// Default is NO.
+ (BOOL)shouldLogInProduction;
/// Default is YES.
+ (BOOL)shouldLogInDebug;
/// Default is NO. Cached BOOL of the userDefaultsKey.
+ (BOOL)userDefaultsOverride;
/// :nodoc:
+ (void)setShouldLogInProduction:(BOOL)shouldLogInProduction;
/// :nodoc:
+ (void)setShouldLogInDebug:(BOOL)shouldLogInDebug;
/// :nodoc:
+ (void)setUserDefaultsOverride:(BOOL)userDefaultsOverride;
/// returns true if (not production and shouldLogInDebug) OR (production build and shouldLogInProduction) or (userDefaultsOverride == YES)
+ (BOOL)loggingEnabled;
/// Default key is KBMLogger_LoggingEnabled
+ (NSString *)userDefaultsKey;
/// :nodoc:
+ (void)setUserDefaultsKey:(NSString *)userDefaultsKey;

/// Logs a format, and variables for the format.
+ (void)log:(NSString *)format, ...;

/// Logs a preset format based on the vspecified verbosity, and variables for the format.
+ (void)logWithVerbosity:(KBMLoggerVerbosity)verbosity
                severity:(KBMLoggerSeverity)severity
              formatArgs:(NSArray *)args;

/// gets singleton instance of logArray - from disk, or new
+ (NSMutableArray *)logArray;
/// use inside applicationWillTerminate: for continuous logging
+ (void)saveLogArray;
/// :nodoc:
+ (NSString *)logArrayFilepath;
/// convenience method / migration from -applicationLog
+ (NSString *)logArrayAsString;

@end
