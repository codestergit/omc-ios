//
//  ORACoreDataCollector.h
//  OracleInfinity
//
//  Created by Taron Kalashyan on 8/23/18.
//  Copyright © 2018 Oracle. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "ORASession.h"
#import "ORACoreConfig.h"

/**
 *  ORACoreDataCollector is the central class. Its central purpose is to log and send events to the collection servers.
 *  It's primarily accessed through its sharedCollector singleton. It should not be manually initialized.
 */
@interface ORACoreDataCollector : NSObject

/**
 * @name Singleton
 */

/**
 *  ORACoreDataCollector should not be initialized manually, but should instead be messaged through this singleton instance.
 *
 *  @param moduleId  Specifies an ID of the module.
 *
 *  @return The ORACoreDataCollector singleton for passed module id.
 */
+ (instancetype)sharedCollector: (NSString *)moduleId;

@property (strong, nonatomic) ORACoreConfig *config;
@property (strong, nonatomic) ORASession *session;

/**
 *  Immediately creates a event and schedules to send.
 *
 *  @param event Specifies a object that stores parameters attached to this event.
 *  @param automatic Whether or not this event was generated automatically.
 *
 */
- (void)triggerEventImmediately:(NSDictionary *) event automatically:(BOOL)automatic;

/**
 *   Creates and schedules a custom event,
 *
 *  @param event Specifies a object that stores parameters attached to this event.
 *  @param automatic Whether or not this event was generated automatically.
 *
 */
- (void)triggerEvent:(NSDictionary *) event automatically:(BOOL)automatic;

/**
 *   Creates and schedules a custom event,
 *
 *  @param event Specifies a object that stores parameters attached to this event.
 *
 */
- (void)triggerEvent:(NSDictionary *) event;
- (void)setValue:(NSString *)value forConfigKey:(NSString *)key;
- (void)setValue:(NSString *)value forConfigKey:(NSString *)key persists:(BOOL)persists;
- (void)scheduleSend;
- (void)scheduleSendAll;
- (void)pause;
- (void)resume;
- (id)valueForConfigKey:(NSString *)key;
- (void) addOperation:(nonnull NSOperation *) task;
- (void) setTaskQueueSuspended: (BOOL) suspended;
- (BOOL) isTaskQueueSuspended;
- (BOOL) isRunning;
- (NSInteger)eventStoreCount;
- (void)resetEventStore;
- (NSArray *)eventsData;
- (void) resetUserDefault:(Class<ORAResettable>)class;

@end
