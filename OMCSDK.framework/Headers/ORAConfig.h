#import <Foundation/Foundation.h>

#import "ORAProtectedProtocols.h"
#import "ORAConfigSetting.h"

/**
 *  Types of configurations
 */
typedef NS_ENUM(NSUInteger, ORAConfigSDK) {
    /**
     *  Analytics configuration
     */
    ORAConfigSDKAnalytics
};

@interface ORAConfig : NSObject

@property (nonatomic) Class<ORAConfigSettingsDataSource>dataSource;
@property (strong, nonatomic) NSDictionary *settings;

- (BOOL)setValue:(NSString *)value
    forConfigKey:(NSString *)key
        persists:(BOOL)persists;

- (id)valueForConfigKey:(NSString *)key;

- (BOOL)versionUpdatedForModule: (NSString *) moduleId;

- (instancetype)initWithPath:(NSString *)path
              versionChanged:(BOOL)versionChanged
                   forModule:(NSString *) moduleId;

- (instancetype)initWithPath:(NSString *)path
              versionChanged:(BOOL)versionChanged
                  dataSource:(Class<ORAConfigSettingsDataSource>)dataSource
                   forModule:(NSString *) moduleId;

- (void)addSettingsWithPath:(NSString *)path
             versionChanged:(BOOL)versionChanged
                 dataSource:(Class<ORAConfigSettingsDataSource>)dataSource
                  forModule:(NSString *) moduleId;

@end
