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

@end
