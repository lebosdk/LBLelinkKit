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

 - LBLelinkServiceTypeLelink: 乐联：局域网内的乐联投屏协议
 - LBLelinkServiceTypeDlnaDMC: DLNA的DMC：局域网内的DLNA的DMC投屏协议
 - LBLelinkServiceTypePublickNetwork: 公网：通过服务器与接收端建立连接
 */
typedef NS_OPTIONS(NSUInteger, LBLelinkServiceType) {
    LBLelinkServiceTypeLelink = 1 << 0,
    LBLelinkServiceTypeDlnaDMC = 1 << 1,
    LBLelinkServiceTypePublickNetwork = 1 << 2,
};

/**
 播放状态

 - LBLelinkPlayStatusUnkown: 未知状态
 - LBLelinkPlayStatusLoading: 视频正在加载状态
 - LBLelinkPlayStatusPlaying: 正在播放状态
 - LBLelinkPlayStatusPause: 暂停状态
 - LBLelinkPlayStatusStopped: 退出播放状态
 - LBLelinkPlayStatusCommpleted: 播放完成状态
 - LBLelinkPlayStatusError: 播放错误
 */
typedef NS_ENUM(NSUInteger, LBLelinkPlayStatus) {
    LBLelinkPlayStatusUnkown = 0,
    LBLelinkPlayStatusLoading,
    LBLelinkPlayStatusPlaying,
    LBLelinkPlayStatusPause,
    LBLelinkPlayStatusStopped,
    LBLelinkPlayStatusCommpleted,
    LBLelinkPlayStatusError,
};


/**
 媒体类型

 - LBLelinkMediaTypeVideoOnline: 在线视频媒体类型
 - LBLelinkMediaTypeAudioOnline: 在线音频媒体类型
 - LBLelinkMediaTypePhotoOnline: 在线图片媒体类型
 - LBLelinkMediaTypePhotoLocal: 本地图片媒体类型
 - LBLelinkMediaTypeVideoLocal: 本地视频媒体类型 注意：需要APP层启动本地的webServer，生成一个本地视频的URL
 - LBLelinkMediaTypeAudioLocal: 本地音频媒体类型 注意：需要APP层启动本地的webServer，生成一个本地音频的URL
 */
typedef NS_ENUM(NSUInteger, LBLelinkMediaType) {
    LBLelinkMediaTypeVideoOnline = 0,
    LBLelinkMediaTypeAudioOnline,
    LBLelinkMediaTypePhotoOnline,
    LBLelinkMediaTypePhotoLocal,
    LBLelinkMediaTypeVideoLocal,
    LBLelinkMediaTypeAudioLocal,
};


/**
 媒体格式类型

 - LBLelinkMediaFormatTypePhotoJpeg: 图片jpeg格式
 - LBLelinkMediaFormatTypePhotoPng: 图片png格式
 */
typedef NS_ENUM(NSUInteger, LBLelinkMediaFormatType) {
    LBLelinkMediaFormatTypePhotoJpeg = 0,
    LBLelinkMediaFormatTypePhotoPng,
};


/**
 弹幕飞行速度类型

 - LBLelinkBarrageFlySpeedTypeFastestFirst: 最快第一飞行速度
 - LBLelinkBarrageFlySpeedTypeSecond: 第二飞行速度
 - LBLelinkBarrageFlySpeedTypeThird: 第三飞行速度
 - LBLelinkBarrageFlySpeedTypeFourth: 第四飞行速度
 - LBLelinkBarrageFlySpeedTypeSlowestFifth: 最慢第五飞行速度
 */
typedef NS_ENUM(NSUInteger, LBLelinkBarrageFlySpeedType) {
    LBLelinkBarrageFlySpeedTypeFastestFirst = 1,
    LBLelinkBarrageFlySpeedTypeSecond,
    LBLelinkBarrageFlySpeedTypeThird,
    LBLelinkBarrageFlySpeedTypeFourth,
    LBLelinkBarrageFlySpeedTypeSlowestFifth,
};

/**
 防骚扰状态

 - LBLelinkHarassStateWait: 等待
 - LBLelinkHarassStateAllow: 允许
 - LBLelinkHarassStateReject: 拒绝
 */
typedef NS_ENUM(NSInteger, LBLelinkHarassState) {
    LBLelinkHarassStateWait = 1,
    LBLelinkHarassStateAllow = 2,
    LBLelinkHarassStateReject = 3,
};

/**
 防骚扰选择状态详情

 - LBLelinkHarassStateDetailDefault: 默认无意义,在LBLelinkHarassStateWait时详情
 - LBLelinkHarassStateDetailTimeout: 超时触发
 - LBLelinkHarassStateDetailUserChoose: 用户手动选择
 - LBLelinkHarassStateDetailListHistoryChoose: 发送端设备在白名单或者黑名单中,自动选择（允许 st为2）（拒绝 st为3)
 */
typedef NS_ENUM(NSInteger, LBLelinkHarassStateDetail) {
    LBLelinkHarassStateDetailDefault = 0,
    LBLelinkHarassStateDetailTimeout = 1,
    LBLelinkHarassStateDetailUserChoose = 2,
    LBLelinkHarassStateDetailListHistoryChoose = 3,
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

 - LBLelinkMediaPlayLoopModeDefault: 默认模式,播完结束
 - LBLelinkMediaPlayLoopModeSingleCycle: 单曲循环
 - LBLelinkMediaPlayLoopModeAllCycle: 全部循环
 - LBLelinkMediaPlayLoopModeOrderPlay: 顺序循环
 - LBLelinkMediaPlayLoopModeRandomPlay: 随机循环
 */
typedef NS_ENUM(NSInteger, LBLelinkMediaPlayLoopMode) {
    LBLelinkMediaPlayLoopModeDefault = 0,
    LBLelinkMediaPlayLoopModeSingleCycle,
    LBLelinkMediaPlayLoopModeAllCycle,
    LBLelinkMediaPlayLoopModeOrderPlay,
    LBLelinkMediaPlayLoopModeRandomPlay,
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
 
 - LBMonitorActionTypeOnStartPlay: 开始播放
 - LBMonitorActionTypeOnStop: 停止播放(结束播放)
 - LBMonitorActionTypeOnPause: 暂停播放
 - LBMonitorActionTypeOnResume: 继续播放
 */
typedef NS_ENUM(NSUInteger, LBMonitorActionType) {
    LBMonitorActionTypeOnStartPlay = 1,
    LBMonitorActionTypeOnStop,
    LBMonitorActionTypeOnPause,
    LBMonitorActionTypeOnResume,
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

