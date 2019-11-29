//
//  ZYAdSplash.h
//  ZYAdSDK
//
//  Created by liuyaqiang on 2019/4/25.
//  Copyright © 2019 zhangyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol ZYAdSplashDelegate;


@interface ZYAdSplash : NSObject
/**
 当前的广告平台
 */
@property (nonatomic, copy, readonly) NSString *platform;

/**
 设置代理
 */
@property (nonatomic, weak) id<ZYAdSplashDelegate>delegate;

/**
 初始化开屏广告

 @param rootViewController splash展示的controller
 @return splash
 */
+ (instancetype)splashWithRootViewController:(UIViewController *)rootViewController;

/**
 加载和展示 splash
 */
- (void)loadAndShow;

@end

@protocol ZYAdSplashDelegate <NSObject>
@optional
//splash 加载成功
- (void)splashDidLoad:(ZYAdSplash *)ad;
//splash 加载失败 
- (void)splashDidFail:(ZYAdSplash *)ad withError:(NSError *)error;
//splash 展示成功
- (void)splashDidShow:(ZYAdSplash *)ad;
//splash 被点击
- (void)splashDidClick:(ZYAdSplash *)ad;
//splash 已关闭
- (void)splashDidClose:(ZYAdSplash *)ad;
@end
