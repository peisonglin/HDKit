//
//  UIViewController+HDKit.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface UIViewController (HDKit)

///顶部nvcBar高度
@property (nonatomic,assign)CGFloat hdTopBar;
///底部tabbar高度
@property (nonatomic,assign)CGFloat hdBottom;
///状态栏高度
@property (nonatomic,assign)CGFloat hdTopStatus;
///导航栏全部高度
@property (nonatomic,assign)CGFloat hdTop;
///底部安全高度
@property (nonatomic,assign)CGFloat hdBottomSafe;

@end

NS_ASSUME_NONNULL_END
