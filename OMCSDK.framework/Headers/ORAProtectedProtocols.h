#ifndef ORAProtectedProtocols_h
#define ORAProtectedProtocols_h

@protocol ORAConfigSettingsDataSource <NSObject>

+(NSArray *)sdkSettingsClasses;
+(BOOL)keyIsFirstParty:(NSString *)key;

@end

@protocol ORAResettable <NSObject>

/**
 *
 *  @return An array of strings of keys in the key/value store whose values will be set to nil. Effectively, this resets all key/value pairs to defaults. This class is only used in unit testing to reset the  SDK to a known state.
 */
+(NSArray *)resettableKeys;

@optional
+(void)oraResetModule:(NSString *) moduleId;

@end

#endif

