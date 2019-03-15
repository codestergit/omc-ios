#import <Foundation/Foundation.h>

#import "ORACoreConstants.h"
#import "ORAProtectedProtocols.h"
#import "ORASession.h"

@class ORAConfig;

@interface ORASession : NSObject <ORAResettable>

/**
 *  The max length of the session, in milliseconds
 */
@property (nonatomic) long long maxSessionMilliseconds;
/**
 *  The session timeout, in milliseconds
 */
@property (nonatomic) long long sessionTimeoutMilliseconds;
/**
 *  The ORAConfig object associated with the session
 */
@property (strong, nonatomic) ORAConfig *config;
/**
 *  The timestamp, in milliseconds, when the session started
 */
@property (nonatomic) long long sessionStart;
/**
 *  The timestamp, in milliseconds, of the last event
 */
@property (nonatomic) long long lastEvent;
/**
 *  Whether or not to store session params in the persistent preferences.
 *  When the application is open from the browser the session params are not stored
 *  persistently until the application relaunch.
 */
@property (nonatomic) BOOL storeSessionInUserDefaults;

@property (strong, nonatomic) NSString *visitorId;

-(instancetype)initWithConfig:(ORAConfig *)config forModule:(NSString *) moduleId;
-(NSDictionary *)processNextEventDictionary:(NSDictionary *)event;

@end
