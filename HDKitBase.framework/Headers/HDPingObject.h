//
//  HDPingObject.h
//  ToolObject
//
//  Created by air on 2021/9/28.
//

#import <Foundation/Foundation.h>
#import <HDKit/HDMacros.h>



NS_ASSUME_NONNULL_BEGIN

@interface HDPingObject : NSObject

+ (HDPingObject *)sharedManager;
//销毁单利
+(void)close;

/**
 监控网络变化。
 @param handler 回调;
*/
-(void)checkNetWorkReachability:(void (^)(HDNetWorkState newState))handler;

///**
// 检测当前使用的网络是否能ping通。（仅且检测5次，网络变化后会检测失败,连接vpn也会失败,次数过多有内存释放问题）
// @param handler 回调;
//*/
//- (void)startPingCallbackHandler:(void (^)(BOOL success))handler;


//以下暂时不能使用
/////取消 凡是长时间不是用ping的时候，都需执行取消
//- (void)cancel;
////暂停ping包
//- (void)pingPause:(BOOL)pause;


@end

NS_ASSUME_NONNULL_END
