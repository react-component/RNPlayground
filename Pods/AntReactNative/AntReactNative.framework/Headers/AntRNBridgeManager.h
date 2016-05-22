//
//  AntBridgeManager.h
//  AntReactNative
//
//  Created by Denis Swain on 15/11/10.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import "AntRNBridge.h"

@interface AntRNBridgeManager : NSObject
// react-native.js
@property (nonatomic, strong) NSURL *baseBundleURL;
@property (nonatomic, strong) RCTBridgeModuleProviderBlock moduleProvider;
@property (nonatomic, strong) NSDictionary *launchOptions;

+ (instancetype)sharedManager;
/**
 *  预加载框架代码
 *
 *  @param block         block description
 *  @param launchOptions launchOptions description
 */
+ (void)preInitWithBaseBundleURL:(NSURL *)baseBundleURL
              moduleProvider:(RCTBridgeModuleProviderBlock)block
               launchOptions:(NSDictionary *)launchOptions;

/**
 *  执行App启动脚本
 *
 *  @param sourceURL sourceURL description
 *  @param bridge    bridge description
 */
+ (AntRNBridge *)loadAppSourceURL:(NSURL *)appBundleURL channelId:(NSString *)channelId;

@end
