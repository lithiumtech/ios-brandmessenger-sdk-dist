//
//  KBMCertificatePinningHandler.h
//  BrandMessengerCore
//
//  Created by Paul Kwak on 2/9/22.
//

#import <Foundation/Foundation.h>

@interface KBMCertificatePinningHandler : NSObject <NSURLSessionDelegate>

+ (KBMCertificatePinningHandler *)sharedInstance;

+ (NSURLSession*)sharedSession;

- (void) setPinningCertificateURLs:(NSArray<NSURL*>*)urls forDomains:(NSArray<NSString*>*)domains;

- (void) setPinningCertificatePublicKeys:(NSArray<NSString*>*)keys forDomains:(NSArray<NSString*>*)domains;

- (BOOL) isPinningEnabled;

@end
