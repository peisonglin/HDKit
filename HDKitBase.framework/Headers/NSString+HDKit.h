//
//  NSString+HDKit.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <Foundation/Foundation.h>
/*
 本类 时间格式处理+文件/字串md5加密+字串URLDecode URLEncode
 */
NS_ASSUME_NONNULL_BEGIN

@interface NSString (HDKit)

/// 任意时间，更具时区转换为手机系统时区对应的时间
/// @param time 时间字符串
/// @param timeFormat 转换前的时间格式
/// @param resultFormat 转换后时间的格式
+(NSString *)anyTimeZoneTransition:(NSString *)time withTimeFormat:(NSString *)timeFormat withResultFormat:(NSString *)resultFormat;

/**
 获取当前时间转的字符串
 
 @param format 时间字符串表达式
 @return 当前字符串的时间
 */
+(NSString *)getNowTime:(NSString *)format;

/**
 获取时间管理器
 
 @param format 时间字符串表达式
 @return 时间管理器
 */
+(NSDateFormatter *)setTimeFormat:(NSString *__nullable)format;


/**
 时间转换
 @param time 字符串的时间、NSDate、时间戳
 @return 转换后的时间字符串
 */
+(NSString *)timeTransferfrom:(id)time timeFormat:(NSString *)timeFormat resultFormat:(NSString *)resultFormat;

/**
 获取时间戳
 
 @param time 字符串的时间、NSDate、时间戳
 @param format 转换后的时间表达式
 @return 时间戳
 */
+(NSTimeInterval)getTimeInterval:(id)time format:(NSString *)format;


/**
 将时间戳转换为 小时：分
 
 @param time 时间差值 （单位秒）
@param format 转换后的时间表达式
 @return string
 */
+(NSString *)timeChangeHourOrMinOrSec:(NSInteger)time format:(NSString *)format;


/**
 获取前后天数的时间字符串
 
 @param day 多小天 过去的时候-1天 未来时间+1
 @param time date、时间字符串、时间戳 如果为nil 就是当前时间开始
 @param timeFormat 返回时间的表达式
 @return 时间字符串
 */
+(NSString *)getLateDay:(int)day time:(id)time timeFormat:(NSString *)timeFormat resultFormat:(NSString *)resultFormat;


/// 比较2时间相差多少天
/// @param fileTime 时间1 （字符串的时间、NSDate、时间戳）
/// @param fileTimeFormat 时间1的表达样式
/// @param currentTime 时间2 （字符串的时间、NSDate、时间戳）
/// @param currentTimeFormat 时间2的表达样式
+(int)compareCurrentTimeForFileTimeDay:(NSString *)fileTime filetimeFormat:(NSString *)fileTimeFormat currentTime:(NSString *)currentTime currentTimeFormat:(NSString *)currentTimeFormat;

/**
 时间串比较大小
 
 @param time 大的时间
 @param time1 小的时间
 @return time>time1 =yes
 */
+(BOOL)compareTime:(NSString *)time timeFormat:(NSString *)timeFormat time:(NSString *)time1 timeFormat1:(NSString *)timeFormat1;

/**
 获取时区
 */
+(NSTimeZone *)getTimeZone;



// MD5加密 文件加密（路径调用方法）或者string字串调用
- (NSString *)MD5;

// 中文、特殊字符转码
- (NSString *)transEncodingString;


/* URLEncode
 NSString *unencodedString = @"cc?p1=%+&sd f&p";
 NSString *encodedString = [unencodedString URLEncodedString];
 */
- (NSString *)URLEncodedString;


/* URLDecode
 NSString *undecodedString = @"%25+&sd%20&p2=%E4%B8%AD%E6%96%87";
 NSString *decodedString = [undecodedString URLDecodedString];
 */
-(NSString *)URLDecodedString;


@end

NS_ASSUME_NONNULL_END
