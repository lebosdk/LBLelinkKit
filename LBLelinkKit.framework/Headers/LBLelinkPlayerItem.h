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

@end
