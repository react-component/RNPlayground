//
//  AntRNBridge.h
//  AntReactNative
//
//  Created by Denis Swain on 15/11/11.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import "RCTBridge.h"
#import "AntRNRootView.h"

@interface AntRNBridge : RCTBridge

/**
 *  增加对rootView的弱引用
 *  @author AntReactNative
 */
@property(nonatomic, weak) AntRNRootView *antRNRootView;

@end
