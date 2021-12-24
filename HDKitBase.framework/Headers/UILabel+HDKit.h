//
//  UILabel+HDKit.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UILabel (HDKit)
/**
 保存用户默认设置修改
 @param font 字体大小
 @param overstriking 是否加粗
 @param color 字体颜色
 @param integer 显示模式 1、居中 0靠左 2靠右
 */
-(void)labelFont:(int)font isOverstriking:(BOOL)overstriking andColor:(UIColor *)color andTextAlignment:(int)integer;
@end

NS_ASSUME_NONNULL_END
