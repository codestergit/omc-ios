#import <Foundation/Foundation.h>

@import CoreTelephony;

@interface ORAClientInfo : NSObject

@property (strong) CTTelephonyNetworkInfo *carrierInfo;

+(const NSString *) connectionType;
+(NSString *)applicationNameForModule: (NSString *) moduleId;
-(void) initDeviceInfoForModule: (NSString *) moduleId;

@end
