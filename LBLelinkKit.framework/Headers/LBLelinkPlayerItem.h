//
//  LBLelinkPlayerItem.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LBLelinkBase.h"

@interface LBLelinkPlayerItem : NSObject

/**
 媒体类型
 */
@property (nonatomic, assign) LBLelinkMediaType mediaType;

/**
 在线媒体的URL
 */
@property (nonatomic, copy) NSString *mediaURLString;

/**
 在线媒体的封面URL
 */
@property (nonatomic, copy) NSString *mediaAlbumArtURLString;

/**
 音视频媒体的起播位置，单位秒
 */
@property (nonatomic, assign) NSInteger startPosition;

/**
 图片媒体的data：当mediaType为LBLelinkMediaTypePhotoLocal，以及LBLelinkService的serviceType包含LBLelinkServiceTypeLelink时，可将图片转为NSData推送
 */
@property (nonatomic, strong) NSData *mediaData;

/**
 媒体格式,当mediaType为LBLelinkMediaTypePhotoLocal,需指定mediaData的格式
 */
@property (nonatomic, assign) LBLelinkMediaFormatType mediaFormatType;


/**
 播放器所需header信息
 */
@property (nonatomic, strong) NSDictionary *headerInfo;

/**
 播放加密url地址所需的信息
 */
@property (nonatomic, strong) LBPlayerAesModel *aesModel;

/**
 播放循环模式
 */
@property (nonatomic, assign) LBLelinkMediaPlayLoopMode loopMode;

/**
 片源唯一ID,如需在接收端展现片源相关信息,需设置
 */
@property (nonatomic, copy) NSString *mediaId;

/**
 视频媒体类型：直播，短视频，长视频
 */
@property (nonatomic, assign) LBPassthMediaAssetMediaType mediaAssetType;

/**
 片源名称,如“阿凡达”,多个以";"分割
 */
@property (nonatomic, copy) NSString *mediaName;

/**
 片源导演,多个以";"分割
 */
@property (nonatomic, copy) NSString *mediaDirector;

/**
 片源主演,多个以";"分割
 */
@property (nonatomic, copy) NSString *mediaActor;

/**
自定义dlna协议DIDL-Lite中id的值
*/
@property (nonatomic, copy) NSString *dlnaDIDLId;

/**
自定义dlna协议DIDL-Lite中resolution的值
*/
@property (nonatomic, copy) NSString *dlnaDIDLResolution;

/**
 视频首帧的图片地址，用于快速显示视频画面，仅支持设置缓存视频列表cacheVideoList接口时生效
 */
@property (nonatomic, copy) NSString *firstFrameImgURLString;
/**
自定义dlna协议DIDL-Lite中metaData的值
*/
@property (nonatomic, copy) NSString *metaData;

/**
 不同清晰度的片源数组，仅推送视频列表有效
*/
@property (nonatomic, strong)NSArray<LBLelinkPlayerItem *> *itemClarityArray;

/**
 清晰度类型，仅推送视频列表有效
*/
@property (nonatomic, assign) LBLelinkVideoClarityType clarityType;


/// 视频分辨率宽
@property (nonatomic, assign) NSInteger pixelWidth;
/// 视频分辨率高
@property (nonatomic, assign) NSInteger pixelHeight;

/**
 片头的时长，单位是秒，设置后可跳过片头播放，仅推送视频列表有效
*/
@property (nonatomic, assign) NSInteger headDuration;

/**
 片尾部的时长，单位是秒，设置后可跳过片尾播放
*/
@property (nonatomic, assign) NSInteger tailDuration;

/**
 禁止内部重试推送, 默认：NO
 */
@property (nonatomic, assign) BOOL disableInternalRetry;

@end
