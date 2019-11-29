//
//  ZYAdNative.h
//  ZYAdSDK
//
//  Created by liuyaqiang on 2019/4/24.
//  Copyright © 2019 zhangyu. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZYAdNativeAssetIdentifier.h"

@protocol ZYAdNativeDelegate;

@interface ZYAdNative : NSObject
/**
 广告的标题
 */
@property (nonatomic, copy, readonly) NSString *adTitle;

/**
 ad 的描述
 */
@property (nonatomic, copy, readonly) NSString *adDescription;

/**
 大图url
 */
@property (nonatomic, copy, readonly) NSURL *imageUrl;

/**
 icon url
 */
@property (nonatomic, copy, readonly) NSURL *iconUrl;

/**
 提示字段 如：install，click 等
 */
@property (nonatomic, copy, readonly) NSString *callToAction;

/**
 当前的广告平台
 */
@property (nonatomic, copy, readonly) NSString *platform;

/**
 设置当前native展示的controller
 */
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 设置native代理
 */
@property (nonatomic, weak) id<ZYAdNativeDelegate>delegate;

/**
 加载native
 */
- (void)load;

/**
 注册native

 @param containerView native
 @param clickableViews 点击的视图Dictionary
 */
- (void)registerContainerView:(UIView *)containerView withClickableViews:(NSDictionary<ZYAdNativeAssetIdentifier, UIView *> *)clickableViews;

@end


@protocol ZYAdNativeDelegate <NSObject>
@optional
//native加载成功
- (void)nativeDidLoad:(ZYAdNative *)ad;
//native加载失败 
- (void)nativeDidFail:(ZYAdNative *)ad withError:(NSError *)error;
//native 被点击
- (void)nativeDidClick:(ZYAdNative *)ad;
@end
