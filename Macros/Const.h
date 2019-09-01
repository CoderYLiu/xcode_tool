//
//  Const.h
//
//  Created by LiuY on 16/5/12.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import <UIKit/UIKit.h>

/******************** 全局常量 ********************/

/** 全局统一的间距 */
UIKIT_EXTERN CGFloat const MPMargin;

/** 统一较小的间距 */
UIKIT_EXTERN CGFloat const MPCommonSmallMargin;

/** 导航栏最大的Y值 */
UIKIT_EXTERN CGFloat const MPNavMaxY;

/** Tabbar高度 */
UIKIT_EXTERN CGFloat const MPTabBarH;

/** StatusBar高度 */
UIKIT_EXTERN CGFloat const MPStatusBarH;

/** 导航栏高度 */
UIKIT_EXTERN CGFloat const MPNavBarH;

/** 性别-未知 */
UIKIT_EXTERN NSString * const MPUserSexUnknown;

/** 性别-男 */
UIKIT_EXTERN NSString * const MPUserSexMale;

/** 性别-女 */
UIKIT_EXTERN NSString * const MPUserSexFemale;

/******************** 网络状态 ********************/
typedef NS_ENUM(NSInteger, LYNetWorkStatus) {
    LYNetWorkStatusUnknown            = -1,   // 未知
    LYNetWorkStatusNotReachable       = 0,    // 无连接
    LYNetWorkStatusReachableViaWWAN   = 1,    // 蜂窝网络
    LYNetWorkStatusReachableViaWiFi   = 2,    // WiFi
};
