#ifdef __cplusplus
#import "react-native-cpp-turbo.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNCppTurboSpec.h"

@interface CppTurbo : NSObject <NativeCppTurboSpec>
#else
#import <React/RCTBridgeModule.h>

@interface CppTurbo : NSObject <RCTBridgeModule>
#endif

@end
