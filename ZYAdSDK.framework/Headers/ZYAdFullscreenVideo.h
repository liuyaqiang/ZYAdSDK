//
//  ZYAdFullscreenVideo.h
//  ZYAdSDK
//
//  Created by liuyaqiang on 2019/5/22.
//  Copyright © 2019 zhangyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol ZYAdFullscreenVideoDelegate;


@interface ZYAdFullscreenVideo : NSObject
/**
 当前的广告平台
 */
@property (nonatomic, copy, readonly) NSString * _Nullable platform;

/**
 设置代理
 */
@property (nonatomic, weak) id<ZYAdFullscreenVideoDelegate> _Nullable delegate;

/**
 Video是否已准备好
 */
@property (nonatomic, assign, readonly) BOOL isReady;

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
 加载Video
 */
- (void)load;

/**
 展示Video
 
 @param rootViewController Video当前展示的controller
 */
- (void)showFromRootViewController:(UIViewController *_Nonnull)rootViewController;


@end

@protocol ZYAdFullscreenVideoDelegate <NSObject>
@optional
//Video 加载成功
- (void)fullscreenVideoDidLoad:(ZYAdFullscreenVideo *_Nullable)ad;
//Video 加载失败 
- (void)fullscreenVideoDidFail:(ZYAdFullscreenVideo *_Nullable)ad withError:(NSError *_Nullable)error;
//Video 展示成功
- (void)fullscreenVideoDidShow:(ZYAdFullscreenVideo *_Nullable)ad;
//Video 被点击
- (void)fullscreenVideoDidClick:(ZYAdFullscreenVideo *_Nullable)ad;
//Video 已关闭
- (void)fullscreenVideoDidClose:(ZYAdFullscreenVideo *_Nullable)ad;
@end
