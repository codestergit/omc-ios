#import <Foundation/Foundation.h>

/**
 *  Create a base event and add some aditional params
 *
 */
@interface ORACoreEventBuilder : NSObject

/**
 *  Create a base event and add custom events
 *
 *  @param customParams a dictionary
 *  @param moduleId  Specifies an ID of the module.
 *
 *  @return base event added with custom event (if custom event is not nil)
 */
+ (NSMutableDictionary *) createBaseEventWithCustomParams:(NSDictionary *) customParams
                                                forModule:(NSString *) moduleId;

@end
