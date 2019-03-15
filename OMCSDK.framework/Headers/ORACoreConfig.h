#import "ORAConfig.h"

@interface ORACoreConfig : ORAConfig

@property (nonatomic, readonly) NSInteger apiVersion;
@property (strong, nonatomic, readonly) NSURL *collectionUrl;
@property (strong, nonatomic, readonly) NSURL *rcsUrl;

- (instancetype)initForModule:(NSString *)moduleId;

@end
