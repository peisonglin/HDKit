//
//  UIColor+HDKit.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (HDKit)

//16进制转化RGB
+ (UIColor *)colorWithHexString:(NSString *)string;

/**
 *  @author pengrun, 16-09-14 17:09:33
 *
 *  @brief 从十六进制字符串获取颜色
 *
 *  @param color 支持@“#123456”、 @“0X123456”、 @“123456”三种格式
 *  @param alpha 透明度
 *
 *  @return UIColor
 */
+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

/**
 *  @author pengrun, 16-09-14 17:09:15
 *
 *  @brief 获取随机颜色
 *
 *  @return UIColor
 */
+ (UIColor *)randomColor;



@end

NS_ASSUME_NONNULL_END
