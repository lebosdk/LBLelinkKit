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

