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
// ad_sessionid 广告sessionid 标识唯一的一次广告行为；（hid+sessionid+uri+stamp）大写后 MD5 32位大写
@property (nonatomic, copy) NSString *ads;
// 广告位
@property (nonatomic, copy) NSString *adpos;
// is_interaction 是否交互跨屏，0不是，1是
@property (nonatomic, assign) NSInteger itc;
// 投屏的sessionid
@property (nonatomic, copy) NSString *sessionId;
//creative_id 广告创意节目id
@property (nonatomic, assign) NSInteger cid;
// thirdpartyPvMonitorUrls 第三方曝光检测 url数组
@property (nonatomic, strong) NSArray *tpurl;
// thirdpartyPvMonitorUrls 第三方曝光检测 url数组
@property (nonatomic, strong) NSArray *tpurl2;
// 上报监测时,header中是否上报UA,1为上报,0为不上报
@property (nonatomic, assign) NSInteger postua;
/// 广告协议
@property (nonatomic, copy) NSString *apv;
// 扩展字段
@property (nonatomic, copy) NSString *ext;
// 广告的uri
@property (nonatomic, copy) NSString *uri;
// 播放时间
@property (nonatomic, assign) NSInteger playTime;
// 记录上报步骤，1：playing 2:stop 只需上报一次
@property (nonatomic, assign) NSInteger reportSteps;

@end

NS_ASSUME_NONNULL_END
