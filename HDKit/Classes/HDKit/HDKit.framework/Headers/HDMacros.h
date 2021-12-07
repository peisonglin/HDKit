//
//  HDMacros.h
//  ToolObject
//
//  Created by air on 2021/4/25.
//  Copyright © 2021 Apple. All rights reserved.
//

#ifndef HDMacros_h
#define HDMacros_h

#pragma mark----------------------------------------Key
#define DEF_BaiDu_MAP_KEY @""
#define DEF_GaoDe_MAP_KEY @""
#define DEF_UMEN_KEY @"5c779fc83fc19501da0001ec"
#define DEF_GoogleMap_KEY @""



#pragma mark----------------------------------------代码块

//打印信息
#define HDLog(format, ...)  if (DEBUG) NSLog(format, ##__VA_ARGS__)
//销毁打印
#define HDLogClass HDLog(@"%@", MXStringFormat(NSStringFromClass([self class]), @"销毁"));

//单利
#define MXSingleInterface(className) \
+ (className *)sharedManager;\

#define MXSingleImplementation(className)\
static dispatch_once_t onceToken;\
static className * _manager;\
+(className *)sharedManager{\
    dispatch_once(&onceToken, ^{\
        _manager = [[super allocWithZone:NULL] init];\
    });\
    return _manager;\
}\
+(id)allocWithZone:(struct _NSZone *)zone{\
    return [className sharedManager];\
}\
-(id)copyWithZone:(struct _NSZone *)zone{\
    return [className sharedManager];\
}\

#define MXSingleInterfaceClose(className) \
+ (className *)sharedManager;\
+(void)close;\

#define MXSingleImplementationClose(className)\
static dispatch_once_t onceToken;\
static className * _manager;\
+(className *)sharedManager{\
    dispatch_once(&onceToken, ^{\
        _manager = [[super allocWithZone:NULL] init];\
    });\
    return _manager;\
}\
+(id)allocWithZone:(struct _NSZone *)zone{\
    return [className sharedManager];\
}\
-(id)copyWithZone:(struct _NSZone *)zone{\
    return [className sharedManager];\
}\
+(void)close{\
    onceToken = 0;\
    _manager=nil;\
}\

//语言国际化
#define MXLanguage(textName,content)\
^(){\
NSString *string=NSLocalizedString(textName, content);\
return string;\
}()

#define MXLanguageImage(textName,content)\
^(){\
NSString *string=NSLocalizedString(textName, content);\
return string;\
}()

#define HDLanguage(key) \
        [NSBundle.mainBundle localizedStringForKey:(key) value:@"" table:nil]
#define MXStringLanguage(str,int) [NSString stringWithFormat:HDLanguage(str),int]
#define MXStringLanguageInt(str,int) [NSString stringWithFormat:HDLanguage(str),int]
#define MXStringLanguageFloat(str,int) [NSString stringWithFormat:HDLanguage(str),int]
#define MXStringLanguageInteger(str,int) [NSString stringWithFormat:HDLanguage(str),int]
#define MXStringLanguageFloatTwo(str,int,int1) [NSString stringWithFormat:HDLanguage(str),int,int1]
//"Updata_connect_DVR_Wifi"="请连接Wi-Fi：%@%@"; MXStringLanguageIntTwo(@"Updata_connect_DVR_Wifi",1,2);
#define MXStringLanguageIntTwo(str,int,int1) [NSString stringWithFormat:HDLanguage(str),int,int]





///2个数字string 相除 有返回值宏代码块
#define ObjectScale(numberStringA,numberStringB)\
^(){\
if (numberStringA.floatValue==0 && numberStringB.floatValue==0) {return 16.0/9.0;}\
NSDecimalNumber *num1 = [NSDecimalNumber decimalNumberWithString:numberStringA];\
NSDecimalNumber *num2 = [NSDecimalNumber decimalNumberWithString:numberStringB];\
NSDecimalNumber *resultNum = [num1 decimalNumberByDividingBy:num2];\
double ss =[resultNum doubleValue];\
return ss;\
}()
///系统触感
#define Sound_System(vaue)\
({\
    UIImpactFeedbackGenerator *feedBackGenertor = [[UIImpactFeedbackGenerator alloc] initWithStyle:vaue];\
    [feedBackGenertor impactOccurred];\
})

///发送通知
#define Not_Send_Message(NotificationName,selfObject,dic) \
({\
dispatch_async(dispatch_get_main_queue(), ^{\
NSNotificationCenter* notificationCenter = [NSNotificationCenter defaultCenter];\
[notificationCenter postNotificationName:NotificationName object:selfObject userInfo:dic];\
});\
})
///接收通知
#define Not_Accept_Event(NotificationName,selfObject,SEL) \
({\
[[NSNotificationCenter defaultCenter]addObserver:selfObject selector:SEL name:NotificationName object:nil];\
})



///针对scrollView、tableview 处理 显示内容偏移 MXNvcBottomHeight
#define MXScrollContent(view) if (@available(iOS 11.0, *)){[view appearance].contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;} view.contentInset = UIEdgeInsetsMake(0, 0, MXNvcBottomHeight, 0);

#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;
#define MXString(s) [NSString stringWithFormat:@"%d",s]
#define MXStringInteger(s) [NSString stringWithFormat:@"%lu",(long)s]
#define MXStringFloat(s) [NSString stringWithFormat:@"%0.f",s]
#define MXStringDouble(s) [NSString stringWithFormat:@"%0.lf",s]
#define MXStringFloatAll(s) [NSString stringWithFormat:@"%f",s]
#define MXStringFormat(str,string) [NSString stringWithFormat:@"%@%@",str,string]
#define MXImageUrl(name) [NSString stringWithFormat:@"HDBundle.bundle/%@",name]

///获取项目目录下的路径
#define MXGetFilePath(fileAllName) [[NSBundle mainBundle] pathForResource:fileAllName ofType:nil]

///文件Document下绝对路径
#define MXSaveFileName(fileAllName) [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0] stringByAppendingPathComponent:fileAllName]

///文件Caches下绝对路径
#define MXSaveToCachesFileName(fileAllName) [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:fileAllName]

///iOS当前系统版本判断
#define MXDeviceBig(value) [[UIDevice currentDevice] systemVersion].intValue>=value
#define MXDeviceSmall(value) [[UIDevice currentDevice] systemVersion].intValue<value

///是否是模拟器
#define IS_SimuLator (TARGET_IPHONE_SIMULATOR == 1 && TARGET_OS_IPHONE == 1)
///是否为iPhoneX
#define IS_PhoneX \
^(){\
BOOL iPhoneXSeries = NO;\
if (UIDevice.currentDevice.userInterfaceIdiom != UIUserInterfaceIdiomPhone) {return iPhoneXSeries;}\
if (@available(iOS 11.0, *)) {\
UIWindow *mainWindow = [[[UIApplication sharedApplication] delegate] window];\
if (mainWindow.safeAreaInsets.bottom > 0.0) {iPhoneXSeries = YES;}\
}\
return iPhoneXSeries;\
}()




#pragma mark----------------------------------------尺寸
#define Screen_Width ([UIScreen mainScreen].bounds.size.width)
#define Screen_Height ([UIScreen mainScreen].bounds.size.height)
#define MXNvcBarHeight (IS_PhoneX ? 88.0 : 64.0)
#define MXNvcTopHeight (IS_PhoneX ? 44 : 20)
#define MXNvcTitleHeight 44
#define MXNvcBottomHeight (IS_PhoneX ? 34.0 : 0)
#define MXTabBarHeight (IS_PhoneX ? 83.0 : 49.0)
#define MXScreenHeight (Screen_Height - MXNvcBottomHeight-MXNvcBarHeight)
#define PWWidth(value) ((value)/375.0f*Screen_Width)
#define PWHight(value) ((value)/667.0f*Screen_Height)
///按钮的高度
#define MXButtonH 50

#pragma mark----------------------------------------颜色

#define ColorFromRGB(r,g,b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define ColorFromRGBA(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define UIColorFromRGB(rgbValue)\
\
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:1.0]

#define UIColorFromRGA(rgbValue,a)\
\
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:a]
#define MXColor1 UIColorFromRGB(0x33415D)//黑色
#define MXColor2 UIColorFromRGB(0xFFFFFF)//白色文字
#define MXColor3 UIColorFromRGB(0xBBBDC3)//灰1 文字
#define MXColor4 UIColorFromRGB(0xBFC3C9)//灰2 tabar 文字
#define MXColor5 UIColorFromRGB(0x4F5767)//背景
#define MXColor6 UIColorFromRGB(0xFEFEFE)//暗白文字




#pragma mark----------------------------------------字体
#define MXFont1 16  //正常字体
#define MXFont2 15
#define MXFont3 14  //副标题
#define MXFont4 13  //大字体
#define MXFont5 12
#define MXFont6 11
#define MXFont7 10
#define MXFont8 18
#define MXFont9 22



#pragma mark----------------------------------------string
#define TimeAllOneType @"yyyy-MM-dd HH:mm:ss"
#define TimeAllTwoType @"yyyy/MM/dd HH:mm:ss"
#define TimeAllThreeType @"yyyy/MM/dd HH:mm"
#define TimeAllFourType @"yyyyMMdd HH:mm:ss"
#define TimeAllFiveType @"yyyyMMddHHmmss"
#define TimeAllAgeType @"yyyy-MM-dd hh:mm:ss.SSS"
#define TimeAllSixType @"yyyy-MM-dd HH:mm:ss +mmm"
#define TimeAllSevenType @"yyyy-MM-ddTHH:mm:ssZ"
#define TimeDateOneType @"yyyy-MM-dd"
#define TimeDateTwoType @"yyyy/MM/dd"
#define TimeDateThreeType @"yyyyMMdd"
#define TimeDateFourType @"MM-dd"
#define TimeHourOneType @"HH:mm:ss"
#define TimeHourTwoType @"HH:mm"
#define TimeHourThreeType @"mm:ss"
#define TimeHourFourType @"mmssmmm"


#pragma mark----------------------------------------URL
#define DownID @"https://itunes.apple.com/cn/lookup?id=1526765694"
#define DownIDURL @"https://apps.apple.com/cn/app/Ucam-4G/id1526765694"

#pragma mark----------------------------------------结构体
///图片类型
typedef enum : NSUInteger {
    ImageFor_PNG = 0,//
    ImageFor_Jpeg,//
    ImageFor_Gif,//
    ImageFor_Tiff,//
    ImageFor_UNknown
} MXImageType;

typedef enum : NSUInteger {
    //layer宽高比例16：9
    VideoMenuTypeDefault=0,//menu在layer上
    VideoMenuTypeDown,//menu与layer下面
    VideoMenuTypeBottom,//menu 在PlayerView底部
    VideoMenuTypeShangQi,
    VideoMenuTypeAddWater,//添加水印
    VideoMenuTypeLivew,//直播
    VideoMenuTypeNoMenuView,//没有控制view
} VideoMenuType;


typedef enum : NSUInteger {
    AutomaticType=1,//自动选择(仅限本地视频文件播放)，将根据文件类型选择性能最好的播放方式，不支持有特殊功能要求。
    AVPlayerType,//ios自带播放器
    VLCPlayerType,//VLC播放器
    FFMPlayeType,//FFMPeg播放器
    IJKPlayerType,//ijkplayer
    SpecialPlayerType,//特殊的组合模式，（仅限网络视频文件播放,vlc+ffmpeg 组合播放）
} HDPlayerType;

///拼包状态
typedef enum {
    HDPingStatusDidStart,//开始拼包
    HDPingStatusDidFailToSendPacket,//发送拼包数据失败
    HDPingStatusDidReceivePacket,//接收拼包数据
    HDPingStatusDidReceiveUnexpectedPacket,//接收到异常的拼包数据
    HDPingStatusDidTimeout,//拼包接收超时
    HDPingStatusError,//拼包错误
    HDPingStatusFinished,//拼包结束
} HDPingStatus;

///当前网络状态
typedef enum {
    HDNetWorkStateUNknown,//未知网络
    HDNetWorkStateDefault,//默认网络
    HDNetWorkState4G,//4G网络
    HDNetWorkStateWiFi,//Wi-Fi网络
} HDNetWorkState;




#endif /* HDMacros_h */
