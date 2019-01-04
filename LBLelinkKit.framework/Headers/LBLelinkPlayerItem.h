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

@end
