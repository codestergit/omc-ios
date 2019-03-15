//
//  PIORegionEvent.h
//  PushIOManager
//
//  Copyright © 2018 Oracle Inc. All rights reserved.
//

#import "PIOEvent.h"

@class PIORegion;

/**
 Eventtype of regions.
 */
typedef NS_ENUM(NSUInteger, PIORegionEventType) {
    PIOGeoEntry,
    PIOGeoExit,
    PIOBeaconEntry,
    PIOBeaconExit
};

@interface PIORegionEvent : PIOEvent

/**
 Constructor to instantiate the PIORegionEvent.
 
 @param region   Region information.
 @param type     specify the region event type.
 */
- (instancetype)initWitRegion:(PIORegion *)region type:(PIORegionEventType)type;


/**
 validate the event
 @return  error with information if inavlid.
 */
- (NSError *)validateEvent;
@end
