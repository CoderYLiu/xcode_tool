//
//  MPFileCacheManager.h
//
//  Created by LiuY on 16/5/20.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FileCacheManager : NSObject

/**
 *  获取文件缓存大小
 *
 *  @param filePath 文件路径
 *
 *  @return 缓存大小
 */
+ (NSUInteger)getFileCacheSize:(NSString *)filePath;

/**
 *  获取文件夹缓存大小
 *
 *  @param directoryPath 文件夹路径
 *  @param completeBlock 完成后回调Block
 */
+ (void)getDirectoryCacheSize:(NSString *)directoryPath completeBlock:(void(^)(NSUInteger total))completeBlock;

/**
 *  删除缓存
 *
 *  @param filePath 文件路径
 */
+ (void)deleteCacheWithPath:(NSString *)filePath;

@end
