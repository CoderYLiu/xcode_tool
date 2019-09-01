//
//  MPFileCacheManager.m
//
//  Created by LiuY on 16/5/20.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#import "FileCacheManager.h"

@implementation FileCacheManager

+ (NSUInteger)getFileCacheSize:(NSString *)filePath {
    NSFileManager *manager = [NSFileManager defaultManager];
    NSDictionary *attributes = [manager attributesOfItemAtPath:filePath error:nil];
    return [attributes[NSFileSize] integerValue];
}

+ (void)getDirectoryCacheSize:(NSString *)directoryPath completeBlock:(void (^)(NSUInteger))completeBlock {
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        // 创建文件管理者
        NSFileManager *mgr = [NSFileManager defaultManager];
        
        // 判断下传入路径是否是文件夹路径
        BOOL isDirectory;
        BOOL isExist = [mgr fileExistsAtPath:directoryPath isDirectory:&isDirectory];
        
        // 文件不存在 或者 传入不是文件夹
        if (!isExist || !isDirectory) {
            // 创建异常对象
            NSException *excp = [NSException exceptionWithName:@"FilePathError" reason:@"传入文件不存在或者传入的不是文件夹" userInfo:nil];
            // 抛异常
            [excp raise];
        }
        
        NSArray *subPaths = [mgr subpathsAtPath:directoryPath];
        
        NSUInteger total = 0;
        for (NSString *subPath in subPaths) {
            NSString *filePath = [directoryPath stringByAppendingPathComponent:subPath];
            BOOL isDirectory;
            BOOL isExist = [mgr fileExistsAtPath:filePath isDirectory:&isDirectory];
            if (isExist && ! isDirectory) { // 文件存在 并且 不是文件夹
                total += [self getFileCacheSize:filePath];
            }
            
        }
        dispatch_sync(dispatch_get_main_queue(), ^{
            BLOCK_EXEC(completeBlock, total)
        });
        
    });
}


+ (void)deleteCacheWithPath:(NSString *)filePath {
    NSFileManager *manager = [NSFileManager defaultManager];
    BOOL isDirectory;
    BOOL isExist = [manager fileExistsAtPath:filePath isDirectory:&isDirectory];
    
    if (!isExist) return;
    
    if (isDirectory) {
        NSArray *subPaths = [manager subpathsAtPath:filePath];
        for (NSString *subPath in subPaths) {
            NSString *subfilePath = [filePath stringByAppendingPathComponent:subPath];
            
            [manager removeItemAtPath:subfilePath error:nil];
        }
    } else {
        [manager removeItemAtPath:filePath error:nil];
    }
    
}

@end
