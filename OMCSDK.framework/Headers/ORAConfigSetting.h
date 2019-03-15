#import <Foundation/Foundation.h>

@interface ORAConfigSetting : NSObject

/**
 *  Base string value of the setting before it is converted to parsedValue
 */
@property (strong, nonatomic) NSString *rawValue;

- (NSString *)settingKey;
- (NSString *)humanReadableString;
- (BOOL)required;
- (NSString *)defaultValue;
- (BOOL)isValid:(NSString *)value;
- (id)parsedValue;

@end
