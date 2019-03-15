#import <Foundation/Foundation.h>

#ifndef ORASharedCoreProtectedImports_h
#define ORASharedCoreProtectedImports_h
#import "ORAProtectedProtocols.h"

// Notification center
extern NSString * const ORAEventManagerWillEnqueueEvents;
extern NSString * const ORAEventManagerDidResume;
extern NSString * const ORAEventDidFinishSending;
extern NSString * const ORAEventManagerDidPause;
extern NSString * const ORAEventWasInserted;
extern NSString * const ORAEventWasDeleted;

//  Adding two addtional methods added:
//  (1) method of making key in lowercase
//  (2) method for creating url query string

@interface NSDictionary (ORACoreAdditions)

- (NSDictionary *)ora_lowercaseDictionary;
- (NSString *)ora_queryString;

@end

@interface NSString(ORACoreAdditions)

- (NSString*)ora_MD5;

@end

@interface NSURL (ORACoreAdditions)

@property (nonatomic, readonly, getter=isRemote) BOOL remote;

@end

@interface NSDate (ORACoreAdditions)

- (long long)ora_timestamp;
- (NSString *)ora_timestampString;
+ (instancetype)ora_dateWithORATimestamp:(long long)eventTime;

@end

@interface NSData (ORACoreAdditions)

- (NSData *)ora_gzippedDataWithCompressionLevel:(float)level;
- (NSData *)ora_gzippedData;
- (NSData *)ora_gunzippedData;
- (BOOL)ora_isGzippedData;
@end

#import "ORANumberSetting.h"

@interface ORANumberSetting (ORAProtectedAdditions)

- (NSInteger)to;
- (NSInteger)from;

@end

BOOL ORAShouldLog(NSString *moduleId);
void ORALog(BOOL shouldLog, NSString *string, ...);

#endif /* ORAProtectedImports.h */
