//
//  HDTool.h
//  HDKitBase
//
//  Created by air on 2021/12/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
NS_ASSUME_NONNULL_BEGIN

@interface HDTool : NSObject

/**
 *  @brief 延迟执行任务
 *  @param seconds  延长秒数
 *  @param executeBlock 执行任务block
 *  @return 返回延迟对象 （延迟对象需要全局 weak 修饰，才能使用完后自动销毁）
 */
+(id)createDelayBlockAfterTime:(CGFloat)seconds withBlock:(dispatch_block_t)executeBlock;

/**
 *  @brief 取消延迟任务
 *  @param delayedObject 创建延迟时返回的延迟对象
 */
+(void)cancelDelayedBlock:(__nonnull id)delayedObject;


/**
 *  @brief 点击手势
 *  @param view   添加点击手势的view
 *  @param object 代理者
 *  @param method 响应方法
 */
+(void)tapView:(UIView *)view Target:(id)object SEL:(SEL)method;

/**
 *  @brief 计算字符串高度、宽度
 *  @param string 字符串
 *  @param font   字符串的字体大小
 *  @param size   如果计算高度：CGSize(30,1000000),计算宽度：CGSize(1000000,30)
 *  @return 返回Size
 */
+(CGSize)sizeString:(NSString *)string WithFont:(int)font withSize:(CGSize)size;


/**
 *  创建LineView线条
 *  @param frame rect
 *  @param view 父视图
 *  @return 返回LineView
 */
+(UILabel *)lienViewFrame:(CGRect)frame subView:(UIView *)view;

/**放大缩小动画
 *  @brief view 放大缩小动画
 *  @param view view
 *  @param delegate delegate
 */
+(void)viewFrameAnimation:(UIView *)view delegate:(id <CAAnimationDelegate>)delegate;


/**
*  @brief 获取当前显示的UIViewController
*  @return UIViewController
*/
+(UIViewController *)getCurrentVC;

/**
 获取当前显示的TabBarController
 @return UITabBarController
 */
+(UITabBarController * )getCurrentTabBarController;


/**
 改变push动画
 @param view self.navigationController.view
 */
+(void)addControllerPushTransitionAnimation:(UIView *)view;

/**
 view 变大 变小动画
 @param view 变化的view
 @param time 时间
 @param isBig  是否放大
 @param scale 变化起始倍数 0-1
 @param scale1 变化结束倍数 0-1
 */
+(void)viewZoomAnimation:(UIView *)view
        andTime:(CGFloat)time
        andBig:(BOOL)isBig
        andMakeScaleFrom:(CGFloat)scale
        andMakeScaleTo:(CGFloat)scale1
        andFinishBlock:(void (^__nullable)(void))finishBlock;

+(void)viewZoomAnimation1:(UIView *)view
        andTime:(CGFloat)time
        andBig:(BOOL)isBig
        andMakeScaleFrom:(CGFloat)scale
        andMakeScaleTo:(CGFloat)scale1
        andFinishBlock:(void (^__nullable)(void))finishBlock;

/**
 保存用户默认设置修改
 @param fileNaem 文件名
 @param ext 文件后缀
 @param defaultDic 保存的数据字典
 @return 是否成功
 */
+(BOOL)saveUserDefaultSetingFileName:(NSString *)fileNaem ofType:(NSString *)ext andDic:(NSDictionary *)defaultDic;

/**
 获取指定document文件数据
 @param fileNaem 文件名
 @param ext 文件后缀
 @return 返回数据字典
 */
+(NSMutableDictionary *)getUserDefaultSetingFileName:(NSString *)fileNaem ofType:(NSString *)ext;


/**
 移动资源文件到document下
 @param fileNaem 文件名
 @param ext 文件后缀
 @return 是否成功
 */
+(BOOL)movePlistFileToDocument:(NSString *)fileNaem ofType:(NSString *)ext;


/**
不规则的标签 计算高度
@param array 标签数组
@param width mark最大的宽
@return 最总所有mark的高度
*/
+(CGFloat)getMarkerHight:(NSArray *)array widthMax:(CGFloat )width;


/**
data转string 剔除非UTF-8的字符
@param data data
@return data data
*/
+(NSData *)cleanUTF8:(NSData *)data;


/**
字典转json
@param dic 字典
@return jsonString
*/
+(NSString *)dicToJsonString:(NSDictionary *)dic;



/**
data转json
@param data data数据
@return jsonString
*/
+(NSString *)dataToJsonString:(NSData *)data;

/**
array转json
@param arrJson 数组
@return jsonString
*/
+(NSString *)arrayToJsonString:(NSArray *)arrJson;


/**
获取设备剩余空间大小 单位M
@return 剩余大小 单位M
*/
+(NSString *)iphoneFreeSpace;


/**
获取设备总空间大小 单位M
@return 总大小 单位M
*/
+(NSString *)iphoneTotalSpace;


///获取手机型号 Yes:支持h265 no:不支持h265
+(BOOL)getIPhone;
///获取手机名称
+(NSString *)getNameIPhone;

/**
整个字符串用*替换
@return ******
*/
+(NSString *)replaceStarString:(NSString *)string;


/**
 计算有行间距的文字的高度
 @param str 计算文字的内容
 @param font 字的font
 @param size size
 @param line 行间距
 @param word 字间距
 @return cgsize
 */
+(CGSize)getSpaceLabelHeight:(NSString*)str withFont:(CGFloat)font withSize:(CGSize)size LineSpacing:(CGFloat)line wordSpace:(CGFloat)word;

/**
 给UILabel设置行间距和字间距
 @param label 计算文字的内容
 @param str str
 @param font 字的font
 @param line 行间距
 @param word 字间距
 */
+(void)setLabelSpace:(UILabel*)label withValue:(NSString*)str withFont:(CGFloat)font LineSpacing:(CGFloat)line wordSpace:(CGFloat)word;

    
/**
判断设备是否打开了相册权限
*/
+ (void)isCanVisitPhotoLibrary:(void(^)(BOOL isSuccess))result;
/**
 判断当前是否在中国
 @param latitude 纬度
 @param longitude 经度
 @return yes 在中国 no 不在中国
 */
+(BOOL)locationOutOfChina:(CGFloat)latitude longitude:(CGFloat)longitude;


/**
 根据经纬度判断使用哪一种地图加载视频行车轨迹
 @param latitude 纬度
 @param longitude 经度
 @return 地图类型
 */
+(int)judgeUseMapSelectTypeLatitude:(CGFloat)latitude longitude:(CGFloat)longitude;


/**
 获取sim卡信息 判断是否是国内运营商手机
 @return CN 表示国内
 */
+(NSString *)getPhoneSIMCardMessage;


/**
判断string 是否为纯数字string
@param string 字符串
@return 是否为纯数字
*/
+(BOOL)checkStringIsNumber:(NSString *)string;



/**
图片压缩
@param sourceImage 图片
@param maxSize 压缩后图片最大的大小
@return 图片data
*/
+(NSData *)resetSizeOfImageData:(UIImage *)sourceImage maxSize:(NSInteger)maxSize;


/**
 等比压缩图片
 @param sourceImage 资源图片
 @return 压缩后的图片
 */
+ (UIImage *)imageByScalingToMaxSize:(UIImage *)sourceImage;


/**
获取链接的Wi-Fi网关、本机ip地址（Wi-Fi分配的ip地址）、4G网络的ip地址、以及4G网络的网关
*/
+(NSString *)GetOurIpAddress;

/**
获取路径下所有文件名字，包含子文件夹中的文件
@param path 文件路径
@return 所有文件信息
*/
+(NSArray *)getAllFilesName:(NSString *)path;

/**
字符串分割为数组
@param string string
@param identifier 间隔符号
@return 分割后的数组
*/

+(NSArray *)stringToArray:(NSString *)string withIdentifier:(NSString *)identifier;

/**
数组分割为字符串
@param array 数组
@param identifier 间隔符号
@return 所有文件信息
*/
+(NSString *)arrayToString:(NSArray *)array withIdentifier:(NSString *)identifier;


///清除NSUserDefaults
+(BOOL)userDefaultsRemoveKey:(NSString *)key;

/**
view添加四边阴影效果
@param theView view
@param theColor 阴影效果颜色
@param round 圆角大小
*/
+(void)addShadowToView:(UIView *)theView withColor:(UIColor *)theColor forRect:(UIRectEdge)rectType roundFloat:(CGFloat)round;

///给view添加圆角
+(void)addLayerRounded:(UIView *)view roundCorners:(UIRectCorner)corners cornerRadius:(CGFloat)cornerRadius;

///去除array1 与 array2 中 array2对应array1 相同的元素
+(NSArray *)removeArrayObjectsForIdentifierArray:(NSArray *)array1 withResultArray:(NSArray *)array2;


///判断图片是否完整 1、图片绝对地址 2、图片data 3、图片的byte
+(BOOL)isCompletedImage:(id)imagePath withType:(int)fileType;


/**
获取设备UUID
@return UUID string
*/
+(NSString *)getUUIValue;


/**
检查经纬度是否有效
@param location 验证的经纬度
@return bool
*/
+(BOOL)checkLocationgAvailable:(CLLocationCoordinate2D)location;

/**
创建文件夹
@param filePath 文件夹绝对路径 包含Document路径
@return 如果文件已经有返回路径，没有则创建，创建失败返回nil；
*/
+(NSString *)createFilePath:(NSString *)filePath;


/**
创建日志文件:比如log.txt文件 ,日志名字默认使用app显示的名字
@param content 文件内容 可以为：NSString 也可以是 string的data
 @param fileName 必须包含文件格式，如：txt
@return 文件存在，就将内容添加进文件，如不存在创建文件并添加内容，执行失败返回nil；
*/
+(NSString *)createLogContent:(id __nullable)content withFileName:(NSString *)fileName;

/**
获取日志路径
@return 日志路径包含Document路径 //文件名默认是项目app BundleId，最后一部分
*/
+(NSString *)getLogFile;


/**
判断文件是否存在
@param filePath 文件绝对路径
@return bool
*/
+(BOOL)isHasFileExistAtPath:(NSString *)filePath;

/**
type 分钟数 time需要计算的时间
@param time
@param minutes
@return
*/
+(BOOL)timeCompare:(NSString *)time offsetTimeMinutes:(int)minutes;

/**
yes time>oneTime 2分钟
@param time
@param oneTime
@return
*/
+(BOOL)timeCompare:(NSTimeInterval)time withTime:(NSTimeInterval)oneTime;

/**
检测当前使用的语言，文字显示前后问题，入希伯来语 和汉语是反过来显示的
@return yes :右到左。no：左到右
*/
+(BOOL)judgeUserInterfaceHabit;


/// 判断蜂窝授权 2、受限制状态 3、正常可用状态 其他值都是不可用的 ，block里面我返回的是异步的。
+(void)judge4GEmpowerState:(void (^)(int type))netStateBlock;

@end

NS_ASSUME_NONNULL_END
