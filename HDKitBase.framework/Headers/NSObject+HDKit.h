//
//  NSObject+HDKit.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <HDKit/HDMacros.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (HDKit)

///必须先运行 HDPingObject 单利 当前默认使用的网络状态
@property (nonatomic,assign)HDNetWorkState netWorkState;

///必须先运行 HDPingObject 单利 当前使用路由ip地址 并非手机分配的ip vpn连接的情况下是获取失败的
@property (nonatomic,strong)NSString *netWorkIP;

/**
强制横屏竖屏
@param interfaceOrientation 横屏竖屏参数
*/
-(void)switchNewOrientation:(UIInterfaceOrientation)interfaceOrientation;
@end

NS_ASSUME_NONNULL_END
