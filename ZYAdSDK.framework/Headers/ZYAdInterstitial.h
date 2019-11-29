//
//  ZYAdInterstitial.h
//  ZYAdSDK
//
//  Created by liuyaqiang on 2019/4/24.
//  Copyright © 2019 zhangyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol ZYAdInterstitialDelegate;

@interface ZYAdInterstitial : NSObject
/**
 当前的广告平台
 */
@property (nonatomic, copy, readonly) NSString * _Nullable platform;

/**
 Interstitial是否已准备好
 */
@property (nonatomic, assign, readonly) BOOL isReady;

/**
 设置代理
 */
@property (nonatomic, weak) id<ZYAdInterstitialDelegate> _Nullable delegate;

/**
 是否受控制参数约束，默认为YES
 */
@property (nonatomic, assign) BOOL isAdControl;

/**
 有page参数的初始化

 @param page 此参数为自定义参数，用于后台控制参数同步控制，表示当前广告展示的位置，传nil则不受page参数控制。
             如：关卡成功位置展示传：sucess，关卡失败位置展示传：fail，主页面位置展示传：main 等。
 @return instancetype
 */
- (instancetype)initWithPage:(NSString *_Nullable)page;

/**
 加载interstitial
 */
- (void)load;

/**
 展示Interstitial

 @param rootViewController Interstitial当前展示的controller
 */
- (void)showFromRootViewController:(UIViewController *_Nonnull)rootViewController;

@end


@protocol ZYAdInterstitialDelegate <NSObject>
@optional
//Interstitial 加载成功
- (void)interstitialDidLoad:(ZYAdInterstitial *_Nullable)ad;
//Interstitial 加载失败 
- (void)interstitialDidFail:(ZYAdInterstitial *_Nullable)ad withError:(NSError *_Nullable)error;
//Interstitial 展示成功
- (void)interstitialDidShow:(ZYAdInterstitial *_Nullable)ad;
//Interstitial 被点击
- (void)interstitialDidClick:(ZYAdInterstitial *_Nullable)ad;
//Interstitial 已关闭
- (void)interstitialDidClose:(ZYAdInterstitial *_Nullable)ad;
@end
