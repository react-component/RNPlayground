//
//  AntRNRootViewDelegate.h
//  AntReactNative
//
//  Created by chenwenhong on 15/11/16.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AntRNRootView;

@protocol AntRNRootViewDelegate <NSObject>

@optional
- (void)antRNRootView:(AntRNRootView *)antRNRootView handleSoftJSExceptionWithMessage:(NSString *)message
                stack:(NSArray *)stack
          exceptionId:(NSNumber *)exceptionId;

- (void)antRNRootView:(AntRNRootView *)antRNRootView handleFatalJSExceptionWithMessage:(NSString *)message
                stack:(NSArray *)stack
          exceptionId:(NSNumber *)exceptionId;

- (void)antRNRootView:(AntRNRootView *)antRNRootView updateJSExceptionWithMessage:(NSString *)message
                stack:(NSArray *)stack
          exceptionId:(NSNumber *)exceptionId;

- (void)antRNRootView:(AntRNRootView *)antRNRootView domReady:(BOOL __unused)_;
- (void)antRNRootView:(AntRNRootView *)antRNRootView contentViewDidCreated:(BOOL __unused)_;
- (void)antRNRootView:(AntRNRootView *)antRNRootView contentDidAppear:(BOOL __unused)_;

- (BOOL)antRNRootView:(AntRNRootView *)antRNRootView shouldStartLoadWithRequest:(NSURLRequest *)request;
- (void)antRNRootView:(AntRNRootView *)antRNRootView didStartLoadRequest:(BOOL)_;
- (void)antRNRootView:(AntRNRootView *)antRNRootView didFinishLoad:(BOOL)_;
- (void)antRNRootView:(AntRNRootView *)antRNRootView didFailLoadWithError:(NSError *)error;

@required
- (void)antRNRootView:(AntRNRootView *)antRNRootView
                 call:(NSString *)methodName
           parameters:(id)parameters
             callback:(RCTResponseSenderBlock)callback;

@end
