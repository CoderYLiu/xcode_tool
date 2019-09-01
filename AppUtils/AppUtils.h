//
//  AppUntils.h
//
//  Created by LiuY on 16/5/12.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppUtils : NSObject

/**
 *  获取设备唯一标识
 *
 *  @return 唯一标识
 */
+ (NSString *)getDeviceID;

/**
 *  获取当前设备模型
 *
 *  @return 当前设备模型
 */
+ (NSString *)getDeviceModel;

/**
 *  获取App版本
 *
 *  @return App版本
 */
+ (NSString *)getAppVersion;

/**
 *  获取app build版本
 *
 *  @return app build版本
 */
+ (NSString *)getAappBuildVersion;

/**
 *  获取设备名称
 *
 *  @return 设备名称
 */
+ (NSString *)getDeviceName;

/**
 *  获取App名称
 *
 *  @return App名称
 */
+ (NSString *)getAppName;


@end
