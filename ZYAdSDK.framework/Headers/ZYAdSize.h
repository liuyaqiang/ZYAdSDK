//
//  ZYAdSize.h
//  ZYAdSDK
//
//  Created by liuyaqiang on 2019/4/29.
//  Copyright © 2019 zhangyu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"
#import "ZYAdDefines.h"

struct ZYAdSize {
    CGSize size;
};
typedef struct ZYAdSize ZYAdSize;

/// iPhone and iPod Touch ad size. Typically 320x50.
ZY_EXTERN ZYAdSize const kZYAdSize320x50;
/// iPad ad size.Typically 728x90
ZY_EXTERN ZYAdSize const kZYAdSize728x90;


