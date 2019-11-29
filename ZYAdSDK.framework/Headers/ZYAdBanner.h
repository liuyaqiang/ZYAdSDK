//
//  ZYAdBanner.h
//  ZYAdSDK
//
//  Created by liuyaqiang on 2019/4/24.
//  Copyright © 2019 zhangyu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZYAdSize.h"
@protocol ZYAdBannerDelegate;

@interface ZYAdBanner : UIView

/**   
 当前的广告平台
 */
@property (nonatomic, copy, readonly) NSString *platform;

/**
是否自动刷新，默认为YES，30秒刷新一次
 */
@property (nonatomic, assign) BOOL isAutoRrefresh;

/**
 设置当前banner展示的controller
 */
@property (nonatomic, weak) UIViewController *rootViewController;


/**
 设置banner代理
 */
@property (nonatomic, weak) id<ZYAdBannerDelegate>delegate;

/**
 初始化banner

 @param adSize banner 大小
 @param adPoint baner 位置
 @return banner
 */
- (instancetype)initWithZYSize:(ZYAdSize)adSize adPoint:(CGPoint)adPoint;

/**
 加载banner
 */
- (void)load;


@end

@protocol ZYAdBannerDelegate <NSObject>
@optional
//banner 加载成功
- (void)bannerDidLoad:(ZYAdBanner *)ad;
//banenr 加载失败 
- (void)bannerDidFail:(ZYAdBanner *)ad withError:(NSError *)error;
//banner 被点击
- (void)bannerDidClick:(ZYAdBanner *)ad;
@end

