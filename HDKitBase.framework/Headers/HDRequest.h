//
//  HDRequest.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface HDRequest : NSObject

///下载图片
+(void)appleRequestDownloadImage:(NSString *)apiName savePath:(NSString *)path successBlock:(void (^)(id responObject))successBlock failureBlock:(void (^)(NSError *error))failureBlock;
///下载大文件
+(void)appleRequestDownload:(NSString *)apiName savePath:(NSString *)path downProgress:(void (^)(CGFloat progress))progressBlock successBlock:(void (^)(id responObject))successBlock failureBlock:(void (^)(NSError *error))failureBlock;
///Get
+ (void)appleRequestGet:(NSString *)apiName parameters:(NSDictionary *)parameters success:(void (^)(id responObject))successBlock failure:(void (^)(NSError *error))failureBlock;
///Post
+ (void)appleRequestPost:(NSString *)apiName parameters:(NSDictionary *)parameters success:(void (^)(id responObject))successBlock failure:(void (^)(NSError *error))failureBlock;

@end

NS_ASSUME_NONNULL_END
