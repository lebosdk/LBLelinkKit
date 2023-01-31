//
//  LBLelinkBase.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 SDK服务类型
 */
typedef NS_OPTIONS(NSUInteger, LBLelinkServiceType) {
    LBLelinkServiceTypeLelink = 1 << 0,         // 乐联：局域网内的乐联投屏协议
    LBLelinkServiceTypeDlnaDMC = 1 << 1,        // DLNA的DMC：局域网内的DLNA的DMC投屏协议
    LBLelinkServiceTypePublickNetwork = 1 << 2, // 公网：通过服务器与接收端建立连接
};

/**
 服务来源方式
 */
typedef NS_OPTIONS(NSUInteger, LBLelinkServiceSourceStyle) {
    LBLelinkServiceSourceStyleUnkown = 0,               // 来源未知
    LBLelinkServiceSourceStyleSearchMDNS = 1 << 0,      // mdns搜索
    LBLelinkServiceSourceStyleSearchUPNP = 1 << 1,       // upnp搜索
    LBLelinkServiceSourceStyleInputCastCode = 1 << 2,    // 输入投屏码
    LBLelinkServiceSourceStyleScanQRCode = 1 << 3,    // 扫描二维码码
    LBLelinkServiceSourceStyleSearchUltrasound = 1 << 4, // 超声波搜索
    LBLelinkServiceSourceStyleSearchBluetooth = 1 << 5,  // 蓝牙搜索
    LBLelinkServiceSourceStyleWifiDirect = 1 << 6,  // wifiDirect
    LBLelinkServiceSourceStyleBssidMatch = 1 << 7,  // 云端匹配发现（bssid+ip）
    LBLelinkServiceSourceStyleTvUidAndAppIdMatch = 1 << 8,  // tvuid和appid云端匹配发现
    LBLelinkServiceSourceStyleTvDsnAndAppIdMatch = 1 << 9,  // tvdsn和appid云端匹配发现
    LBLelinkServiceSourceStylePhoneMatch = 1 << 10,  // 脱敏数据云端匹配发现
    LBLelinkServiceSourceStyleServerMatch = 1 << 11, // 收藏或历史记录的数据从云端返回的设备数据
};

/**
系统权限类型
*/
typedef NS_OPTIONS(NSUInteger, LBLelinkSystemPermissionsType) {
    LBLelinkSystemPermissionsTypeLocalNetwork = 1,   // 本地网络权限
    LBLelinkSystemPermissionsTypeMicrophone = 2,     // 麦克风录制权限，用于超声波搜索设备
    LBLelinkSystemPermissionsTypeBluetooth = 3,      // 蓝牙权限，用于蓝牙扫描周边设备
};

/**
 播放状态
 */
typedef NS_ENUM(NSUInteger, LBLelinkPlayStatus) {
    LBLelinkPlayStatusUnkown = 0,       // 未知状态
    LBLelinkPlayStatusLoading,          // 视频正在加载状态
    LBLelinkPlayStatusPlaying,          // 正在播放状态
    LBLelinkPlayStatusPause,            // 暂停状态
    LBLelinkPlayStatusStopped,          // 退出播放状态
    LBLelinkPlayStatusCommpleted,       // 播放完成状态
    LBLelinkPlayStatusEpisodeCommpleted,// 单集播放完成状态，还有续集将播放（推送视频列表时有效）
    LBLelinkPlayStatusError,            // 播放错误
};

/**
 播放状态原因，因dlna和历史版本无法获取，暂不对提供
 */
typedef NS_ENUM(NSUInteger, LBLelinkPlayStatusReason) {
    LBLelinkPlayStatusReasonUnkown = 0,         // 原因未知
    LBLelinkPlayStatusReasonPreemptStopped,     // 抢占结束
};
/**
 媒体类型
 */
typedef NS_ENUM(NSUInteger, LBLelinkMediaType) {
    LBLelinkMediaTypeVideoOnline = 0,    // 在线视频媒体类型
    LBLelinkMediaTypeAudioOnline,        // 在线音频媒体类型
    LBLelinkMediaTypePhotoOnline,        // 在线图片媒体类型
    LBLelinkMediaTypePhotoLocal,         // 本地图片媒体类型
    LBLelinkMediaTypeVideoLocal,         // 本地视频媒体类型 注意：需要APP层启动本地的webServer，生成一个本地视频的URL
    LBLelinkMediaTypeAudioLocal,         // 本地音频媒体类型 注意：需要APP层启动本地的webServer，生成一个本地音频的URL
};

/**
视频清晰度类型
*/
typedef NS_OPTIONS(NSUInteger, LBLelinkVideoClarityType) {
    LBLelinkVideoClarityTypeUnkown = 0,     // 视频清晰度未知
    LBLelinkVideoClarityTypeStd = 2,        // 标清视频类型
    LBLelinkVideoClarityTypeHigh = 4,       // 高清视频类型
    LBLelinkVideoClarityTypeSuper = 6,      // 超清视频类型
};

/**
 媒体格式类型
 */
typedef NS_ENUM(NSUInteger, LBLelinkMediaFormatType) {
    LBLelinkMediaFormatTypePhotoJpeg = 0,  // 图片jpeg格式
    LBLelinkMediaFormatTypePhotoPng,       // 图片png格式
};


/**
 弹幕飞行速度类型
 */
typedef NS_ENUM(NSUInteger, LBLelinkBarrageFlySpeedType) {
    LBLelinkBarrageFlySpeedTypeFastestFirst = 1,   // 最快第一飞行速度
    LBLelinkBarrageFlySpeedTypeSecond,             // 第二飞行速度
    LBLelinkBarrageFlySpeedTypeThird,              // 第三飞行速度
    LBLelinkBarrageFlySpeedTypeFourth,             // 第四飞行速度
    LBLelinkBarrageFlySpeedTypeSlowestFifth,       // 最慢第五飞行速度
};


/**
 弹幕行数
 */
typedef NS_ENUM (NSUInteger, LBLelinkBarrageSettingLines) {
    LBLelinkBarrageSettingLinesONE = 1,  // 1行
    LBLelinkBarrageSettingLinesTWO,      // 2行
    LBLelinkBarrageSettingLinesTHREE,    // 3行
    LBLelinkBarrageSettingLinesFOUR,     // 4行
    LBLelinkBarrageSettingLinesFIVE,     // 5行
    LBLelinkBarrageSettingLinesSIX,      // 6行
    LBLelinkBarrageSettingLinesSEVEN,    // 7行
    LBLelinkBarrageSettingLinesEIGHT,    // 8行
    LBLelinkBarrageSettingLinesNINE,     // 9行
    LBLelinkBarrageSettingLinesTEN       // 10行
};


/**
 弹幕飞行速度系数
 */
typedef NS_ENUM(NSUInteger, LBLelinkBarrageSettingSpeed) {
    LBLelinkBarrageSettingSpeed_ONE = 1,     // 0.2
    LBLelinkBarrageSettingSpeed_TWO,         // 0.4
    LBLelinkBarrageSettingSpeed_THREE,       // 0.6
    LBLelinkBarrageSettingSpeed_FOUR,        // 0.8
    LBLelinkBarrageSettingSpeed_FIVE,        // 1.0
    LBLelinkBarrageSettingSpeed_SIX,         // 1.1
    LBLelinkBarrageSettingSpeed_SEVEN,       // 1.2
    LBLelinkBarrageSettingSpeed_EIGHT,       // 1.3
    LBLelinkBarrageSettingSpeed_NINE,        // 1.4
    LBLelinkBarrageSettingSpeed_TEN           // 1.5
};

/**
 防骚扰状态
 */
typedef NS_ENUM(NSInteger, LBLelinkHarassState) {
    LBLelinkHarassStateWait = 1,   // 等待
    LBLelinkHarassStateAllow = 2,  // 允许
    LBLelinkHarassStateReject = 3, // 拒绝
};

/**
 防骚扰选择状态详情
 */
typedef NS_ENUM(NSInteger, LBLelinkHarassStateDetail) {
    LBLelinkHarassStateDetailDefault = 0,            // 默认无意义,在LBLelinkHarassStateWait时详情
    LBLelinkHarassStateDetailTimeout = 1,            // 超时触发
    LBLelinkHarassStateDetailUserChoose = 2,         // 用户手动选择
    LBLelinkHarassStateDetailListHistoryChoose = 3,  // 发送端设备在白名单或者黑名单中,自动选择（允许 st为2）（拒绝 st为3)
};

/**
 防骚扰状态和详情
 */
typedef struct {
    LBLelinkHarassState state;
    LBLelinkHarassStateDetail detail;
}LBLelinkHarassInfo;

typedef enum {//对端处理该数据的模块
    LBLelinkPassthHandlerTypeApp = 1,
    LBLelinkPassthHandlerTypeSDK = 2,
}LBLelinkPassthHandlerType;


typedef enum {//媒体资源信息
    LBPassthMediaAssetMediaTypeLongVideo = 0, //长视频
    LBPassthMediaAssetMediaTypeShortVideo = 1,//短视频
    LBPassthMediaAssetMediaTypeLiveVideo = 2,//直播
}LBPassthMediaAssetMediaType;


/**
 媒体播放循环模式
 */
typedef NS_ENUM(NSInteger, LBLelinkMediaPlayLoopMode) {
    LBLelinkMediaPlayLoopModeDefault = 0,    // 默认模式,播完结束
    LBLelinkMediaPlayLoopModeSingleCycle,    // 单曲循环
    LBLelinkMediaPlayLoopModeAllCycle,       // 全部循环
    LBLelinkMediaPlayLoopModeOrderPlay,      // 顺序循环
    LBLelinkMediaPlayLoopModeRandomPlay,     // 随机循环
};

/**
 播放进度信息
 */
@interface LBLelinkProgressInfo : NSObject

/**
 当前播放进度位置，单位秒
 */
@property (nonatomic, assign) NSInteger currentTime;

/**
 总时长，单位秒
 */
@property (nonatomic, assign) NSInteger duration;

@end


/**
 接收端监测上报的位置类型
 */
typedef NS_ENUM(NSUInteger, LBMonitorActionType) {
    LBMonitorActionTypeOnStartPlay = 1,   // 开始播放
    LBMonitorActionTypeOnStop,            // 停止播放(结束播放)
    LBMonitorActionTypeOnPause,           // 暂停播放
    LBMonitorActionTypeOnResume,          // 继续播放
};

/**
 倍速播放速率
 */
typedef NS_ENUM(NSUInteger, LBPlaySpeedRateType) {
    LBPlaySpeedRate1_0X = 1,    // 1.0
    LBPlaySpeedRate0_5X,        // 0.5
    LBPlaySpeedRate0_75X,       // 0.75
    LBPlaySpeedRate1_25X,       // 1.25
    LBPlaySpeedRate1_5X,        // 1.5
    LBPlaySpeedRate2_0X,        // 2.0
};

/**
日志上报问题反馈类型
*/
typedef NS_ENUM (NSInteger, LBLogReportProblemType){
    LBLogReportProblemTypePlayerCaton = 1 << 0,                    //播放片源卡顿
    LBLogReportProblemTypePlayerBlackScreenHaveVoice = 1 << 1,     //播放片源黑屏有声音
    LBLogReportProblemTypePlayerNotCanPlay= 1 << 2,                //播放片源无法播放
    LBLogReportProblemTypePlayerCrashBack = 1 << 3,                //播放片源闪退
    LBLogReportProblemTypePlayerImageCompression = 1 << 4,         //播放片源画面压缩
    LBLogReportProblemTypePlayerLoadFailed = 1 << 5,               //播放片源加载失败
    LBLogReportProblemTypePlayerSoundImageNotSync = 1 << 6,        //播放片源卡顿
    LBLogReportProblemTypePlayerOther = 1 << 7,                    //其它问题
    LBLogReportProblemTypeLelinkMeetingInfo = 1 << 8,              //会议信息
};

typedef NS_ENUM (NSInteger, LBPassthMirrorActionType){
    LBPassthMirrorActionTypeSuspend = 0,    //镜像暂停
    LBPassthMirrorActionTypePlay = 1,       //镜像继续
};

/**
 监测上报模型
 */
@interface LBMonitorAction : NSObject

+ (instancetype)monitorActionWithType:(LBMonitorActionType)type URLString:(NSString *)monitorURLString;

/**
 监测上报的位置类型
 */
@property (nonatomic, assign) LBMonitorActionType type;

/**
 监测上报的URL
 */
@property (nonatomic, copy) NSString *monitorURLString;

@end


/**
 播放器地址播放所需的AES模型
 */
@interface LBPlayerAesModel : NSObject

/**
 加密模式 ,默认:@"1"
 */
@property (nonatomic,copy) NSString *model;

/**
 加密key,必填
 */
@property (nonatomic,copy) NSString *key;

/**
 加密iv,必填
 */
@property (nonatomic,copy) NSString *iv;

@end


/**
接收端解码能力模型
*/
@interface LBDecodabilityModel : NSObject
+ (instancetype)decodabilityWithName:(NSString *)name type:(NSString *)type resolution:(NSString *)resolution;

/**
 解码器名称，包括：avc、hevc、vp8、vp9
 */
@property (nonatomic, copy) NSString *name;

/**
 解码器类型，包括：
 video/avc
 video/hevc
 video/x-vnd.on2.vp8
 video/x-vnd.on2.vp9
 */

@property (nonatomic, copy) NSString *type;

/**
最大分辨率，格式：宽*高（3840*2160）
 */
@property (nonatomic, copy) NSString *maxResolution;

@end

typedef NS_ENUM (int8_t, LBLelinkTouchType){
    LBLelinkTouchTypeBase = 0,//基础数据,例如 手指按下，手指移动，手指抬起
    LBLelinkTouchTypeEvent = 1,//手势识别后的事件数据，例如 单击，双击，长按
    LBLelinkTouchTypeZoom,//手势识别后的缩放数据
};

typedef NS_ENUM (int8_t, LBLelinkTouchActionType){
    LBLelinkTouchActionTypeDown = 0, //按下
    LBLelinkTouchActionTypeUp = 1,//抬起
    LBLelinkTouchActionTypeMove = 2,//移动
    LBLelinkTouchActionTypePointerDown = 5,//多指操作下，除第一根手指按下的其他手指按下事件
    LBLelinkTouchActionTypePointerUp = 6,//多指操作下，除第一根手指按下的其他手指抬起事件
};


typedef NS_ENUM (int8_t, LBLelinkTouchEventType){
    LBLelinkTouchEventTypeSingleTap = 0,//单击
    LBLelinkTouchEventTypeDoubleTap = 1,//双击
    LBLelinkTouchEventTypeLongPress = 2,//长按
};

@interface LBLelinkTouch : NSObject

@property (nonatomic,assign)LBLelinkTouchType type;
//x轴坐标比例（0-1.0）
@property (nonatomic,assign)float x;
//y轴坐标比例（0-1.0）
@property (nonatomic,assign)float y;
//动作类型，在type==LBLelinkTouchTypeBase有效
@property (nonatomic,assign)LBLelinkTouchActionType actionType;
//手指id，在type==LBLelinkTouchTypeBase有效
@property (nonatomic,assign)int8_t pointerId;
//活跃变化的手指Id，可能是其它手指的id，在type==LBLelinkTouchTypeBase有效
@property (nonatomic,assign)int8_t activePointerId;
//事件类型，在type==LBLelinkTouchTypeEvent有效
@property (nonatomic,assign)LBLelinkTouchEventType eventType;
//缩放比例，在type==LBLelinkTouchTypeZoom有效
@property (nonatomic,assign)float zoomScale;

@end

typedef NS_OPTIONS(NSUInteger, LBLelinkProtocolType) {
    LBLelinkProtocolTypeUnkown = 0,                 // 未知协议类型
    LBLelinkProtocolTypeLelinkV1 = 1 << 0,          // 乐联V1协议：局域网内的乐联投屏协议
    LBLelinkProtocolTypeLelinkV2 = 1 << 1,          // 乐联V2协议：局域网内的乐联投屏协议
    LBLelinkProtocolTypeDLNA = 1 << 2,          // DLNA协议：局域网内的公共投屏协议
    // DLNA的DMC：局域网内的DLNA的DMC投屏协议
    LBLelinkProtocolTypePublickNetwork = 1 << 3,    // 公网连接：通过服务器与接收端建立连接
    LBLelinkProtocolTypeAirplay = 1 << 4,           // airplay协议
    LBLelinkProtocolTypeYoumeCloud = 1 << 5,        // youme云协议
    LBLelinkProtocolTypeMiracast = 1 << 6,          // miracast协议
};

