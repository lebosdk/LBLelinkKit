//
//  LBADInfo.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/6/12.
//  Copyright © 2018 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 乐播广告类型
 */
typedef NS_ENUM(NSUInteger, LBADType) {
    LBADTypePicture = 1,     // 图片广告
    LBADTypeVideo,           // 视频广告
    LBADTypeInteractive,     // 互动广告
};


/**
 子广告
 */
@interface LBSubADInfo : NSObject

/** 子广告类型 */
@property (nonatomic, assign) LBADType subADType;
/** 子广告资源地址 */
@property (nonatomic, copy) NSString *subADSourceUrl;
/** 子广告点击落地页地址 */
@property (nonatomic, copy) NSString *subADClickUrl;
/** 子广告文本 */
@property (nonatomic, copy) NSString *subADText;
/** 子广告时长 */
@property (nonatomic, assign) NSInteger subADDuration;

@end


/**
 主广告
 */
@interface LBADInfo : NSObject

/** 广告类型 */
@property (nonatomic, assign) LBADType adType;
/** 广告资源地址 */
@property (nonatomic, copy) NSString *sourceUrl;
/** 广告点击落地页地址 */
@property (nonatomic, copy) NSString *clickUrl;
/** 广告文本 */
@property (nonatomic, copy) NSString *text;
/** 广告时长 */
@property (nonatomic, assign) NSInteger duration;

/** 子广告 */
@property (nonatomic, strong) LBSubADInfo *subADInfo;


@end

NS_ASSUME_NONNULL_END
