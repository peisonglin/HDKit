//
//  HDKitSDK.h
//  HDKit
//
//  Created by air on 2021/12/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HDKitSDK : NSObject

/**
设置sdk的appkey，用于鉴权功能
@param appkey 开发者分配的appkey
@return 是否鉴权通过
*/
+(BOOL)starConfigAppkey:(NSString *)appkey;

/**
设置是否输出Log,用于方便开发
@param number 鉴定值
@return 是否设置生效
*/
+(BOOL)setLogEnabled:(int)number;

@end

NS_ASSUME_NONNULL_END
