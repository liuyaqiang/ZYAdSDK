//
//  ZYAds.h
//  ZYAdSDK
//
//  Created by liuyaqiang on 2019/4/25.
//  Copyright © 2019 zhangyu. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,ZYPublishZone) {
    ZYPublishZoneForeign = 1, //海外
    ZYPublishZoneDomestic = 2 //国内
};

typedef void (^ZYConfigurateCompletionHandler)(BOOL success,NSError * _Nullable error);

@interface ZYAds : NSObject
+ (instancetype)sharedInstance;
/**
 sdk版本
 */
@property (nonatomic, copy, readonly) NSString *sdkVersion;

#pragma mark - 测试用到参数
/**
 广告日志，默认为NO，请在configurateWithAppkey: completionHandler：之前设置
 */
@property (nonatomic, assign) BOOL logEnable;
/**
是否是测试环境，默认为NO，请在configurateWithAppkey: completionHandler：之前设置
 */
@property (nonatomic, assign) BOOL isTestEnvironment;
/**
 admob设置测试设备，请在configurateWithAppkey: completionHandler：之前设置
 */
@property (nonatomic, strong) NSArray *admobTestDevices;
/**
 facebook设置测试设备，请在configurateWithAppkey: completionHandler：之前设置
 */
@property (nonatomic, strong) NSArray *facebookTestDevices;

#pragma mark - 配置
/**
 渠道，不设置则为默认，请在configurateWithAppkey: completionHandler：之前设置
 */
@property (nonatomic, copy) NSString *appChannel;
/**
 发布地区，必须设置，请在configurateWithAppkey: completionHandler：之前设置
 */
@property (nonatomic, assign) ZYPublishZone publishZone;
/**
 当前关卡，请在调用广告之前设置，用于控制参数关卡控制
 */
@property (nonatomic, assign) NSInteger currentLevel;

/**
 配置ZYAds

 @param appkey appkey
 @param completionHandler 完成回调
 */
- (void)configurateWithAppkey:(nonnull NSString *)appkey completionHandler:(nullable ZYConfigurateCompletionHandler)completionHandler;
/**
 配置友盟
 
 @param appkey appkey
 @param launchOptions launchOptions
 */
- (void)configurateUMengWithAppkey:(NSString *)appkey launchOptions:(NSDictionary * __nullable)launchOptions;

/**
 配置AppsFlyer

 @param appkey appkey
 @param appId appId
 */
- (void)configurateAppsFlyerWithAppkey:(NSString *)appkey appId:(NSString *)appId;
@end

NS_ASSUME_NONNULL_END
