//
//  LBLelinkPlayer.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import "LBLelinkBase.h"

@class LBLelinkPlayer;
@class LBLelinkConnection;
@class LBLelinkPlayerItem;
@class LBLelinkTextBarrage;

@protocol LBLelinkPlayerDelegate <NSObject>

@optional

/**
 播放错误代理回调

 @param player 当前播放器
 @param error 错误信息
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player onError:(NSError *)error;

/**
 播放状态代理回调

 @param player 当前播放器
 @param playStatus 播放状态
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player playStatus:(LBLelinkPlayStatus)playStatus;

/**
 播放进度信息代理回调

 @param player 当前播放器
 @param progressInfo 进度信息
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player progressInfo:(LBLelinkProgressInfo *)progressInfo;

/**
 设置检测行为错误代理回调，注意此方法不是在调用“- (void)setMonitorActions:(NSArray <LBMonitorAction *> *)monitorActions;”后立即回调，
 而是在调用推送行为过程中才设置的，并且是设置错误才有回调，设置正确不回调。

 @param player 当前播放器
 @param error 错误信息
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player setMonitorActionError:(NSError *)error;

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
- (void)lelinkPlayer:(LBLelinkPlayer *)player passthLeboInternalData:(id)dataObj;


/**
 外部使用的透传数据

 @param player 当前播放器
 @param dataObj 从接收端透传过来的数据对象
 */
- (void)lelinkPlayer:(LBLelinkPlayer *)player passthExternalData:(id)dataObj;

@end




@interface LBLelinkPlayer : NSObject

/** 播放器代理 */
@property (nonatomic, weak) id<LBLelinkPlayerDelegate> delegate;
/** 当前连接 */
@property (nonatomic, strong) LBLelinkConnection *lelinkConnection;
/** 播放媒体对象 */
@property (nonatomic, strong) LBLelinkPlayerItem *item;


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
 

 @param monitorActions 监测行为数组
 */

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
 支持的媒体类型判断，在调用- (void)playWithItem:(LBLelinkPlayerItem *)item;之前，先进行判断是否支持该类型的媒体。
 注意：此接口在连接成功后有效，如果没有连接成功，则返回的都是NO

 @param mediaType 媒体类型
 @return YES支持，NO不支持
 */
- (BOOL)canPlayMedia:(LBLelinkMediaType)mediaType;


/** 是否隐藏弹幕 默认NO */
@property (nonatomic,assign,getter=isHideBarrage)BOOL hideBarrage;
/** 是否暂停弹幕 默认NO */
@property (nonatomic,assign,getter=isPauseBarrage)BOOL pauseBarrage;
/** 弹幕最大行数 默认10行 */
@property (nonatomic,assign)NSUInteger barrageMaxLine;
/** 弹幕飞行速度 默认是LBLelinkBarrageFlySpeedTypeFastestFirst,同一速度下，弹幕文本越长,速度会较快 */
@property (nonatomic,assign)LBLelinkBarrageFlySpeedType barrageFlySpeed;
/** 是否从底部开始显示 默认是No */
@property (nonatomic,assign,getter=isBarrageBottomStartShow)BOOL barrageBottomStartShow;
/** 是否允许弹幕重叠 默认是No */
@property (nonatomic,assign,getter=isAllowOverlap)BOOL barrageAllowOverlap;


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
 推送弹幕数组,调用前先判断设备是否支持推送弹幕- (BOOL)canPushBarrage;
 
 @param barrageAry 弹幕数组
 注意：如果弹幕数组超过1000条，请分开发送
 */
- (void)pushBarrageAry:(NSMutableArray<LBLelinkTextBarrage *> *)barrageAry;

/**
 优先弹幕,快速插入的弹幕,调用前先判断设备是否支持推送弹幕- (BOOL)canPushBarrage;
 
 @param barrage 单个弹幕
 */
- (void)pushPriorityBarrage:(LBLelinkTextBarrage *)barrage;


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

- (void)passthErrorInfoWithErrorCode:(NSInteger)errorCode error:(NSString *)error handlerType:(LBLelinkPassthHandlerType)handlerType;



@end
