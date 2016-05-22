//
//  AntRNRootView.h
//  AntReactNative
//
//  Created by Denis Swain on 15/11/11.
//  Copyright © 2015年 Alipay. All rights reserved.
//
#import "RCTRootView.h"
#import "AntRNRootViewDelegate.h"

@interface AntRNRootView : RCTRootView

@property(nonatomic, weak) id<AntRNRootViewDelegate>    antRNDelegate;
@property(nonatomic, weak) id                           delegate;
@property(nonatomic, readonly, strong) NSURLRequest     *request;
@property(nonatomic, readonly, assign) BOOL             isLoading;
@property(nonatomic, readonly, assign) BOOL             isContentDidAppear;
@property(nonatomic, copy) NSString                     *channelId;
@property(nonatomic, assign) NSTimeInterval             timeoutInterval; // default is 15seconds

- (instancetype)initWithAppBundleURL:(NSURL *)appBundleURL
                          moduleName:(NSString *)moduleName
                       antRNDelegate:(id<AntRNRootViewDelegate>)antRNDelegate
                   initialProperties:(NSDictionary *)initialProperties;

- (void)loadRequest:(NSURLRequest *)request moduleName:(NSString *)moduleName;

- (void)loadRequest:(NSURLRequest *)request; // `moduleName` providered by `request.URL`，request.URL suffix is `kAntRNURLSuffix[_1]`

- (void)sendDeviceEventWithName:(NSString *)name body:(id)body;

- (void)evaluateJavaScript:(NSString *)js completionHandler:(void (^)(id result, NSError *error))completionHandler;

- (void)reload;

@end
