#import "ORACoreAdditions.h"
#import "ORACoreProtectedImports.h"

void ORALog(BOOL shouldLog, NSString *string, ...) {
    if (!string) {
        return;
    }
    va_list args;
    va_start(args, string);
    // Temporarily suppress non literal string warning, since it's unavoidable in this context
    // See http://stackoverflow.com/questions/17322163/warning-format-string-is-not-a-string-literal
    // for some more detailed information
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
    NSString *logString = [[NSString alloc] initWithFormat:string arguments:args];
#pragma clang diagnostic pop
    va_end(args);
//    NSString *log = [NSString stringWithFormat:@"<%@> %@",LOG_NAME,logString];
    NSString *log = [NSString stringWithFormat:@"<%@> %@",@"OMCSDK",logString];
    if (shouldLog) {
        NSLog(@"%@",log);
    }
    return;
}

@implementation NSDictionary (ORAAdditions)

/**
 *  Make dictionary items (key,value) in lowercase
 *
 *  @return lowercase strings key/value
 */
- (NSDictionary *)ora_lowercaseDictionary {
    
    NSMutableDictionary *lowercaseCustomParams = [NSMutableDictionary dictionary];
    [self enumerateKeysAndObjectsUsingBlock:^(NSString *key, id obj, BOOL *stop) {
        lowercaseCustomParams[[key lowercaseString]] = obj;
    }];
    return lowercaseCustomParams;
}

/**
 *  Looping through the dictionary and create %key=%value pair and concatiating all list items to create a query string
 *
 *  @return a url query string
 */
- (NSString *)ora_queryString {
    __block NSMutableArray *array = [NSMutableArray array];
    [self enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        [array addObject:[NSString stringWithFormat:@"%@=%@",[key stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding],[obj stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]]];
    }];
    return [array componentsJoinedByString:@"&"];
}

@end

#import <CommonCrypto/CommonDigest.h>

@implementation NSString(ORAAdditions)

- (NSString*)ora_MD5 {
    // Create pointer to the string as UTF8
    const char *ptr = [self UTF8String];
    
    // Create byte array of unsigned chars
    unsigned char md5Buffer[CC_MD5_DIGEST_LENGTH];
    // Create 16 byte MD5 hash value, store in buffer
    CC_MD5(ptr, (CC_LONG)strlen(ptr), md5Buffer);
    // Convert MD5 value in the buffer to NSString of hex values
    NSMutableString *output = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    for(int i = 0; i < CC_MD5_DIGEST_LENGTH; i++) {
        [output appendFormat:@"%02x",md5Buffer[i]];
    }
    return output;
}

@end

#import "ORATaskInitiateEventSend.h"

@interface ORATaskInitiateEventSend ()

@property (nonatomic) NSString *moduleId;

@end

@implementation NSURL (ORAAdditions)

- (BOOL)isRemote {
    return self.host.length > 0 && self.scheme.length > 0;
}

@end

BOOL ORAShouldLog(NSString *moduleId) {
    ORACoreDataCollector *collector = [ORACoreDataCollector sharedCollector: moduleId];
    if (!collector.config || [[collector.config.settings[kORAConfigDebug] parsedValue] boolValue]) {
        return YES;
    }
    return NO;
}
