//
//  Macros.h
//
//  Created by LiuY on 16/5/21.
//  Copyright © 2016年 DeveloperLY. All rights reserved.
//

#ifdef DEBUG
#define debugLog(...) NSLog(__VA_ARGS__)
#define debugMethod() NSLog(@"%s", __func__)
#else
#define debugLog(...)
#define debugMethod()
#endif

#define EMPTY_STRING        @""

#define APPDELEGETE             ((AppDelegate *)[[UIApplication sharedApplication] delegate])

#define WIDTH_SCREEN            [UIScreen mainScreen].bounds.size.width
#define HEIGHT_SCREEN           [UIScreen mainScreen].bounds.size.height


/**
 *  比例
 */
#define Ratio320(args) args/320.0*HEIGHT_SCREEN
#define Ratio568(args) args/568.0*HEIGHT_SCREEN
#define Ratio640(args) args/640.0*HEIGHT_SCREEN
#define Ratio1136(args) args/1136.0*HEIGHT_SCREEN

#define kScreenHeight MAX(WIDTH_SCREEN, HEIGHT_SCREEN)
#define kIPhone4s (kScreenHeight == 480)
#define kIPhone5 (kScreenHeight == 568)
#define kIPhone6 (kScreenHeight == 667)
#define kIPhone6Plus (kScreenHeight == 736)

#define kIMAGENAMED(_pointer)   [UIImage imageNamed:[UIUtil imageName:_pointer]]
#define kLOADIMAGE(file, ext)   [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:file ofType:ext]]


// 验证执行BLOCK
#define BLOCK_EXEC(block, ...)  if (block) { block(__VA_ARGS__); }

#define USER_DEFAULT [NSUserDefaults standardUserDefaults]

#define WeakSelf __weak typeof(self) weakSelf = self;


/**
 *  color
 */
#define HexRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define HexRGBAlpha(rgbValue,alp) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:alp]

#define WBColor(r, g, b)     [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1.0]
#define WBColorAlpha(r, g, b, a)     [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:a]
