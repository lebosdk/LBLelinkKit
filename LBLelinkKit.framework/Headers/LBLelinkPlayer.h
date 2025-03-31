//
//  LBLelinkPlayer.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import "LBLelinkBase.h"
#import <UIKit/UIKit.h>

@class LBLelinkPlayer;
@class LBLelinkConnection;
@class LBLelinkPlayerItem;
@class LBLelinkTextBarrage;
@class LBBarrageSetting;
@class LBLelinkBase;
@class LBLelinkService;

NS_ASSUME_NONNULL_BEGIN

@protocol LBLelinkPlayerDelegate <NSObject>

@optional

/**
 播放错误代理回调

 @param player 当前播放器
 @param error 错误信息
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player onError:(NSError *_Nullable)error;

/**
 播放状态代理回调

 @param player 当前播放器
 @param playStatus 播放状态
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player playStatus:(LBLelinkPlayStatus)playStatus;

/**
 播放广告状态代理回调，从发端推送广告时会有回调

 @param player 当前播放器
 @param playADStatus 广告播放状态
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player playADStatus:(LBLelinkPlayStatus)playADStatus;

/**
 播放进度信息代理回调

 @param player 当前播放器
 @param progressInfo 进度信息
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player progressInfo:(LBLelinkProgressInfo *_Nullable)progressInfo;

/**
 播放广告进度信息代理回调，从发端推送广告时会有回调

 @param player 当前播放器
 @param aDProgressInfo 广告进度信息
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player aDProgressInfo:(LBLelinkProgressInfo *_Nullable)aDProgressInfo;

/**
 设置检测行为错误代理回调，注意此方法不是在调用“- (void)setMonitorActions:(NSArray <LBMonitorAction *> *)monitorActions;”后立即回调，
 而是在调用推送行为过程中才设置的，并且是设置错误才有回调，设置正确不回调。

 @param player 当前播放器
 @param error 错误信息
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player setMonitorActionError:(NSError *_Nullable)error;

/**
 防骚扰信息代理回调

 @param player 当前播放器
 @param harassInfo 防骚扰信息
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player harassInfo:(LBLelinkHarassInfo)harassInfo;

/**
 乐播使用的透传数据

 @param player 当前播放器
 @param dataObj 从接收端透传过来数据对象
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player passthLeboInternalData:(id _Nullable)dataObj;


/**
 外部使用的透传数据

 @param player 当前播放器
 @param dataObj 从接收端透传过来的数据对象
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player passthExternalData:(id _Nullable)dataObj;

/// 秘听功能的回调
/// @param player 当前播放器
/// @param data 音频数据
- (void)lelinkPlayer:(LBLelinkPlayer *)player secretListenAudioData:(NSData * _Nullable)data;
/**
 播放倍速获取和同步回调

 @param player 当前播放器
 @param playSpeed 播放速度
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player playSpeed:(double)playSpeed;

/**
 倍速播放代理回调

 @param player 当前播放器
 @param error 倍速播放状态
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player playSpeedError:(NSError *_Nullable)error;

/**
 播放片源代理回调，在推送视频列表时有效

 @param player 当前播放器
 @param mediaId 当前播放的片源Id,视频列表时设置的LBLelinkPlayerItem.mediaId
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player currentMediaId:(NSString *_Nullable)mediaId;


/** 媒体资源推送后收端的响应，媒体推送到收端成功
 @param player 当前播放器
 @param mediaObject 媒体对象，item或itemArray
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player pushResponse:(id _Nullable)mediaObject;

@end



@interface LBLelinkPlayer : NSObject

/** 播放器代理 */
@property (nonatomic, weak) id<LBLelinkPlayerDelegate> delegate;
/** 当前连接 */
@property (nonatomic, strong) LBLelinkConnection *lelinkConnection;
/** 播放媒体对象 */
@property (nonatomic, strong) LBLelinkPlayerItem *item;
/// 播放状态传入的 uri
@property (nonatomic, copy, readonly) NSString *playStatusURI;

/**
 初始化播放器，使用此方法初始化播放器后需要设置连接和代理

 @return 播放器实例
 */
- (instancetype)init;

/**
 初始化播放器

 @param connection 连接
 @return 播放器实例
 */
- (instancetype)initWithConnection:(LBLelinkConnection *)connection;

/**
 设置接收端需要上报的监测行为

 @param monitorActions 监测行为数组
 */
- (void)setMonitorActions:(NSArray <LBMonitorAction *> *)monitorActions;

/**
 推送播放

 @param item 播放的媒体
 */
- (void)playWithItem:(LBLelinkPlayerItem *)item;

/**
 推送播放，如果已经设置了媒体，则可直接调用此方法
 */
- (void)play;

/**
 暂停播放
 */
- (void)pause;

/**
 继续播放
 */
- (void)resumePlay;

/**
 进度调节

 @param seekTime 调节进度的位置，单位秒
 */
- (void)seekTo:(NSInteger)seekTime;

/**
 退出播放
 */
- (void)stop;

/**
 设置音量值

 @param value 音量值，范围0 ~ 100
 */
- (void)setVolume:(NSInteger)value;

/**
 增加音量
 */
- (void)addVolume;

/**
 减小音量
 */
- (void)reduceVolume;

/**
 是否支持修改倍速播放，倍速修改能力查询
 */
- (BOOL)isSupportChangePlaySpeed;

/**
查询当前的播放速率
 */
- (void)getPlaySpeed;

/**
设置播放速率
 */
- (void)setPlaySpeedWithRate:(LBPlaySpeedRateType)rateType;

/**
播放速率换播放速率类型
 */
- (LBPlaySpeedRateType)playSpeedRateTypeWithRate:(double)rate;


/**
 是否支持倍速同步，收端修改倍速，同步发端，在- (void)lelinkPlayer:(LBLelinkPlayer *)player playSpeed:(double)playSpeed方法回调
 */
- (BOOL)canSupportPlaySpeedSync;

/**
 支持的媒体类型判断，在调用- (void)playWithItem:(LBLelinkPlayerItem *)item;之前，先进行判断是否支持该类型的媒体。
 注意：此接口在连接成功后有效，如果没有连接成功，则返回的都是NO

 @param mediaType 媒体类型
 @return YES支持，NO不支持
 */
- (BOOL)canPlayMedia:(LBLelinkMediaType)mediaType;

/**
 是否支持推送弹幕,支持弹幕,不代表现在可以推送,需在播放视频的情况下才会显示弹幕,可以用- (BOOL)canCurrentPushBarrage;判断

 @return YES支持，NO不支持
 */
- (BOOL)canSupportPushBarrage;

/**
 是否现在可以推送弹幕,支持推送弹幕的情况下且有视频正在播放,才能显示推送的弹幕

 @return YES可以,NO不可以
 */
- (BOOL)canCurrentPushBarrage;

/**
 快速推送弹幕,调用前先判断设备是否支持推送弹幕- (BOOL)canPushBarrage;
 
 @param barrage 单个弹幕
 */
- (void)pushPriorityBarrage:(LBLelinkTextBarrage *)barrage;

/**
 设置弹幕属性
 
 @param barrageSetting 弹幕属性
 */
- (void)modifyBarrageSetting:(LBBarrageSetting *)barrageSetting;

/**
 云镜像退出方式
 
 @param mode 退出方式
 */
- (void)cloudMirrorExitMode:(LBLelinkCloudMirrorExitMode)mode;

/**
 是否支持播放器所需header信息,支持情况下在LBLelinkPlayerItem.headerInfo设置属性生效

 @return YES可以,NO不可以
 */
- (BOOL)canSetterHeader;


/**
 是否支持播放地址所需AES信息,支持情况下在LBLelinkPlayerItem.aesInfo设置属性生效

 @return YES可以,NO不可以
 */
- (BOOL)canSetterAes;

/**
 是否支持透传

 @return YES:支持,NO:不支持
 */
- (BOOL)canPassthData;

/**
 乐播app透传到对端数据
 
 @param dataDic 数据字典
 @param handlerType 对端处理模块
 */
- (void)passthLeBoInternalUseDataDic:(NSDictionary *)dataDic handlerType:(LBLelinkPassthHandlerType)handlerType;


/**
 第三方app透传到对端数据
 
 @param dataDic 数据字典
 @param handlerType 对端处理数据模块,必填
 @param targetAppId 对端处理数据的appid,必填
 */
- (void)passthThirdPartyExternalUseDataDic:(NSDictionary *)dataDic handlerType:(LBLelinkPassthHandlerType)handlerType targetAppId:(NSString *)targetAppId;

/**
 透传错误数据到对端
 */
- (void)passthErrorInfoWithErrorCode:(NSInteger)errorCode error:(NSString *)error handlerType:(LBLelinkPassthHandlerType)handlerType;

/// 是否支持秘听
- (BOOL)canPassthSecretListen;

/// 透传启动秘听功能
- (void)passthStartOverSecretListening;

/// 透传关闭秘听功能
- (void)passthStopSecretListening;

/// 是否能缓存视频列表
- (BOOL)canCacheVideoList;

/// 缓存视频列表
/// 暂只支持LBLelinkMediaTypeVideoOnline和LBLelinkMediaTypeVideoLocal视频片源，不支持缓存AES和设置headerInfo的片源，
/// 可设置Item.mediaURLString和Item.firstFrameImgURLString视频首帧的图片地址，用于快速显示视频首帧画面
/// 接收端会在后台下载片源，在播放时可以快速播放，预加载一组视频的作用,
/// @param itemArray 视频item数组,设置Item.mediaURLString和Item.firstFrameImgURLString即可
/// @param index 起始缓存的索引值
- (void)cacheVideoList:(NSArray <LBLelinkPlayerItem *>*)itemArray startIndex:(NSInteger)index;

#pragma mark - 以下区间是推送视频列表相关接口

/// 是否能推送视频列表
- (BOOL)canPushVideoList;

/// 推送视频列表
/// @param itemArray 视频item数组
/// @param period 片源有效期时长，单位秒，必填，0代表长期有效
/// @param mediaId 开始播放视频的媒体ID，非必填，默认从首个片源开始播放
- (void)pushVideoList:(NSArray <LBLelinkPlayerItem *>*)itemArray validPeriod:(NSInteger)period startMediaId:(NSString *_Nullable)mediaId;


/// 追加视频列表
/// @param itemArray 视频item数组
/// @param period 片源有效期时长，单位秒，必填，0代表长期有效
- (void)appendVideoList:(NSArray <LBLelinkPlayerItem *>*)itemArray validPeriod:(NSInteger)period;


/// 清空视频列表
- (void)clearVideoList;

/// 指定播放视频列表中某一集
/// @param mediaId 片源ID
- (void)playVideoListToMediaId:(NSString *)mediaId;


/// 播放下一集
- (void)playNextMediaInVideoList;

/// 播放上一集
- (void)playPrevMediaInVideoList;

#pragma mark - Other

/// 能否切换音轨，需收端版本功能支持
- (BOOL)canSwitchAudioTrack;

// 切换音轨，index：音轨索引,0:收端默认播放音轨，1:索引为1的音轨，需片源包含多音轨
- (void)switchAudioTrackWithIndex:(NSInteger)index;

/// 能否切换至临时独占模式,需收端功能支持并且在推送视频后
- (BOOL)canSwitchTemporaryPrivateMode;
/// 设置临时独占模式开关，本次投屏生效，
- (void)switchTemporaryPrivateMode:(BOOL)open;

#pragma mark - 以下接口和属性已废弃
/**
 推送弹幕数组,调用前先判断设备是否支持推送弹幕- (BOOL)canPushBarrage;
 
 @param barrageAry 弹幕数组
 注意：如果弹幕数组超过1000条，请分开发送
 */
- (void)pushBarrageAry:(NSMutableArray<LBLelinkTextBarrage *> *)barrageAry DEPRECATED_MSG_ATTRIBUTE("This method has been deprecated!");
/** 是否暂停弹幕 默认NO */
@property (nonatomic,assign,getter=isPauseBarrage)BOOL pauseBarrage DEPRECATED_MSG_ATTRIBUTE("This attribute has been deprecated!");

/** 弹幕飞行速度 默认是LBLelinkBarrageFlySpeedTypeFastestFirst,同一速度下，弹幕文本越长,速度会较快 */
@property (nonatomic,assign)LBLelinkBarrageFlySpeedType barrageFlySpeed DEPRECATED_MSG_ATTRIBUTE("This attribute has been deprecated! Please use '- (void)modifyBarrageSetting:'");
/** 是否从底部开始显示 默认是No */
@property (nonatomic,assign,getter=isBarrageBottomStartShow)BOOL barrageBottomStartShow DEPRECATED_MSG_ATTRIBUTE("This attribute has been deprecated!");
/** 是否允许弹幕重叠 默认是No */
@property (nonatomic,assign,getter=isAllowOverlap)BOOL barrageAllowOverlap DEPRECATED_MSG_ATTRIBUTE("This attribute has been deprecated!");

/** 弹幕最大行数 默认10行 */
@property (nonatomic,assign)NSUInteger barrageMaxLine DEPRECATED_MSG_ATTRIBUTE("This attribute has been deprecated! Please use '- (void)modifyBarrageSetting:'");

/** 是否隐藏弹幕 默认NO */
@property (nonatomic,assign,getter=isHideBarrage) BOOL hideBarrage DEPRECATED_MSG_ATTRIBUTE("This attribute has been deprecated! Please use '- (void)modifyBarrageSetting:'");


#pragma mark - 获取接收端截图

/**
 获取接收端设备的屏幕截图

 @param service 接收端服务信息
 @param completionHandler 完成回调，如果成功获取到截图，则imageData有值，error为nil， 反之imageData为nil，error有值
 */
- (void)getScreenCaptureWithLelinkService:(LBLelinkService *)service completionHandler:(void(^)(NSData * imageData, NSError * error))completionHandler;


#pragma mark - 图片缩放和旋转指令

/**
 缩放原图到显示区域
 
 @param originalSize 原图大小
 @param displayArea 显示区域，即显示的位置和宽高
 */
- (void)zoomFromSize:(CGSize)originalSize toDisplayArea:(CGRect)displayArea;

/**
 图片旋转
 
 @param angle 旋转到的角度值
 */
- (void)rotateAngle:(NSInteger)angle;

@end

NS_ASSUME_NONNULL_END
