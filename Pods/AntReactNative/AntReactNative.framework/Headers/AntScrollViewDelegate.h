//
//  AntScrollViewDelegate.h
//
//  Created by 古云(guyun) on 15/11/18.
//  Copyright (c) 2015年 mybank. All rights reserved.
//
//  用于对RN框架层创建的scrollView，代理其delegate，以在native层同样可以得到UIScrollViewDelegate的回调。

#import <UIKit/UIKit.h>

@interface AntScrollViewDelegate : NSObject <UIScrollViewDelegate>

- (void)addDelegate: (id<UIScrollViewDelegate>)delegate;

- (void)removeDelegate: (id<UIScrollViewDelegate>)delegate;

- (void)removeAllDelegate;

@end
