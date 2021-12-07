//
//  UIViewController+ScreenRect.h
//  ZhongTan
//
//  Created by Apple on 2020/4/15.
//  Copyright © 2020 Apple. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (ScreenRect)

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
