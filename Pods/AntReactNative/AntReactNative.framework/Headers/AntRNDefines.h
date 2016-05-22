//
//  AntRNDefines.h
//  AntReactNative
//
//  Created by chenwenhong on 15/11/16.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// 版本
#define kAntRNSDKVersion                            @"0.17.0"
#define kAntRNSDKName                               @"AntReactNative"

// 文件类型
#define kAntRNURLSuffix                             @".bundle"
#define kAntRNURLSuffix_1                           @".jsbundle"

// 处理类
#define kAntRNURLProtocolClassName                  @"PSDWebViewURLProtocol" // RN发出的请求可以经过的Protocol，除了bundle的下载、file路径；（可以修改）

// 请求头
#define kAntRNRequestHeaderKey                      @"kAntRNRequestHeaderKey" // RN发出的请求header上打的标，值是`x-rn`；（可以修改）
#define kAntRNRequestHeaderValue                    @"x-rn" // RN发出的请求header上打的标，值是`x-rn`；（可以修改）
#define kAntRNRequestHeaderKey1                     @"kPSDProxyRequestHeaderKey" // RN发出的请求header上打的标，值是`x-rn`；（可以修改）
#define kAntRNRequestHeaderValue1                   @"x-rn" // RN发出的请求header上打的标，值是`x-rn`；（可以修改）

// RN主bundle文件
#define kAntRNRequestHeaderChannelIdKey             @"kPSDProxyRequestHeaderChannelIdKey"
#define kAntRNRequestContentTypeKey                 @"kAntRNRequestContentTypeKey" //
#define kAntRNRequestContentTypeValue               @"application/x-rn" //


// 错误
#define kAntRNErrorDomain                           @"AntReactNativeDomain"

typedef enum : NSUInteger {
    AntRNErrorCode_Unknown = -1,
    
    // load
    AntRNErrorCode_JSError = 1000,
    AntRNErrorCode_RequestTimeout = 1001,
} AntRNErrorCode;
