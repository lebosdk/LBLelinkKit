//
//  LBLelinkTextBarrage.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/9/22.
//  Copyright © 2018 深圳乐播科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 弹幕类型
 */
typedef NS_ENUM(NSUInteger, LBLelinkTextBarrageType) {
    LBLelinkTextBarrageTypeFromeRight = 1,     // 从屏幕右边飞出的弹幕 默认
    LBLelinkTextBarrageTypeFormeLeft = 6,      // 从屏幕左边飞出的弹幕
    LBLelinkTextBarrageTypeBottomFixed = 4,    // 屏幕底部固定的弹幕 显示时间为4秒
    LBLelinkTextBarrageTypeTopFixed = 5,       // 屏幕顶部固定的弹幕 显示时间为4秒
};

NS_ASSUME_NONNULL_BEGIN

@interface LBLelinkTextBarrage : NSObject


/** 弹幕文本 */
@property (nonatomic, copy) NSString *text;
/** 弹幕字体大小  默认20 */
@property (nonatomic, assign) NSUInteger fontSize;
/** 文字颜色     默认whiteColor  可设颜色透明度 */
@property (nonatomic, strong) UIColor *textColor;
/** 以下是新增属性 **/
/** 弹幕ID */
@property (nonatomic, copy) NSString *danmukuId;
/** 弹幕在视频的哪个时间点显示（单位：毫秒  默认为0） 设置为0则马上显示弹幕*/
@property (nonatomic, assign) NSInteger displayTime;

/** 以下属性已废弃 **/
/** 弹幕id */
@property (nonatomic, assign) NSInteger barrageId DEPRECATED_MSG_ATTRIBUTE("throw away, please use 'danmukuid'");
/** 边距(边框与文字距离) 默认值10 */
@property (nonatomic, assign) NSInteger margin DEPRECATED_MSG_ATTRIBUTE("throw away");
/** 延迟出现时间（单位为毫秒）默认值 0 */
@property (nonatomic, assign) NSUInteger delayTime DEPRECATED_MSG_ATTRIBUTE("throw away");
/** 用户id */
@property (nonatomic, assign) NSInteger userId DEPRECATED_MSG_ATTRIBUTE("throw away");
/** 弹幕类型    默认HPBarrageTypeFromRight */
@property (nonatomic, assign) LBLelinkTextBarrageType type DEPRECATED_MSG_ATTRIBUTE("throw away");
/** 文字边缘颜色  默认clearColor */
@property (nonatomic, strong) UIColor *textEdgeColor DEPRECATED_MSG_ATTRIBUTE("throw away");
/** 下划线颜色   默认clearColor */
@property (nonatomic, strong) UIColor *underlineColor DEPRECATED_MSG_ATTRIBUTE("throw away");
/** 边框颜色    默认clearColor */
@property (nonatomic, strong) UIColor *borderColor DEPRECATED_MSG_ATTRIBUTE("throw away");

@end

NS_ASSUME_NONNULL_END
