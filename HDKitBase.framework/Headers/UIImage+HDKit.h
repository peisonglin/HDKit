//
//  UIImage+HDKit.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (HDKit)

//根据颜色返回图片
+ (UIImage *)imageWithColor:(UIColor *)color rectFrame:(CGRect)rect;

//根据颜色返回图片 cornerRadius:圆角度
+ (UIImage *)imageWithColor:(UIColor *)color rectFrame:(CGRect)rect cornerRadius:(CGFloat)cornerRadius;

//获取网络图片
+ (UIImage *)imageWithUrlString:(NSString *)urlString;

///返回图片的data
+(NSData *)imageWithSizeUrlString:(NSString *)urlString;

///将view 转为图片,会堵塞当前线程
+(void)convertViewToImage:(UIView *)view withBlock:(void (^)(UIImage *image))imageBlock;

@end

NS_ASSUME_NONNULL_END
