//
//  UIButton+HDKit.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PRButtonType){
    ///image左 label右
    PRButtonImageOnLeftWithLabelOnRight,
    ///image右 label左
    PRButtonImageOnRightWithLabelLeft,
    ///image上 label下
    PRButtonImageOnTopWithLabelBottom,
    ///image下 label上
    PRButtonImageOnBottomWithLabelTop
};

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (HDKit)

@property(nonatomic, strong) UIColor * _Nullable backgroudColorFromUIColor;
    
/**
 *  点击区域扩大Button
 *
 *  @param size 扩大size
 */
- (void)setEnlargeEdge:(CGFloat) size;

/**
 *  扩大Button的四周区域
 *
 *  @param top    上
 *  @param right  右
 *  @param bottom 下
 *  @param left   左
 */
- (void)setEnlargeEdgeWithTop:(CGFloat) top right:(CGFloat) right bottom:(CGFloat) bottom left:(CGFloat) left;

/**
 *  设置按钮
 *
 *  @param buttonType button的类型：图片、标题位置
 *  @param gap        标题 图片之间距离
 */
- (void)setButtonType:(PRButtonType)buttonType withGap:(CGFloat)gap;

/**
 *  设置按钮的方向，默认图片和title间隔10
 *
 *  @param buttonType button的类型：图片、标题位置
 */
- (void)setButtonType:(PRButtonType)buttonType;

#pragma mark - 时间倒计时

//可用时的标题
#define Verify_Button_Title_Available       @"获取验证码"

//倒计时的标题
#define Verify_Button_Title_Unavailable     @""

#define Verify_Button_BackgroundColor_Avilable kSkinBaseViewColor

#define Verify_Button_BackgroundColor_Unavilable [UIColor clearColor]

- (void)startTimer;

- (void)startTimer:(NSTimeInterval)time;

- (void)startTimer:(NSTimeInterval)time timerOut:(void (^_Nullable)(BOOL))completion;

- (void)startTimer:(NSTimeInterval)time availableTitle:(NSString *_Nonnull)available unavailableTitle:(NSString *_Nullable)unavailable availableColor:(UIColor *_Nullable)avColor unavailableColor:(UIColor *_Nullable)unColor;

- (void)startTimer:(NSTimeInterval)time availableTitle:(NSString *_Nonnull)available unavailableTitle:(NSString *_Nonnull)unavailable availableColor:(UIColor *_Nonnull)avColor unavailableColor:(UIColor *_Nullable)unColor timerOut:(void (^ __nullable)(BOOL finished))completion;

- (void)setGradualChangingFromColor:(NSString *_Nullable)fromHexColorStr toColor:(NSString *_Nullable)toHexColorStr;



@end

NS_ASSUME_NONNULL_END
