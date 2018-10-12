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

 - LBLelinkTextBarrageTypeFromeRight: 从屏幕右边飞出的弹幕 默认
 - LBLelinkTextBarrageTypeFormeLeft: 从屏幕左边飞出的弹幕
 - LBLelinkTextBarrageTypeBottomFixed: 屏幕底部固定的弹幕 显示时间为4秒
 - LBLelinkTextBarrageTypeTopFixed: 屏幕顶部固定的弹幕 显示时间为4秒
 */
typedef NS_ENUM(NSUInteger, LBLelinkTextBarrageType) {
    LBLelinkTextBarrageTypeFromeRight = 1,
    LBLelinkTextBarrageTypeFormeLeft = 6,
    LBLelinkTextBarrageTypeBottomFixed = 4,
    LBLelinkTextBarrageTypeTopFixed = 5,
};

NS_ASSUME_NONNULL_BEGIN

@interface LBLelinkTextBarrage : NSObject

/** 弹幕id */
@property (nonatomic, assign) NSInteger barrageId;
/** 弹幕类型    默认HPBarrageTypeFromRight */
@property (nonatomic, assign) LBLelinkTextBarrageType type;
/** 弹幕文本 */
@property (nonatomic, copy) NSString *text;
/** 弹幕字体大小  默认20 */
@property (nonatomic, assign) NSUInteger fontSize;
/** 文字颜色     默认whiteColor  可设颜色透明度 */
@property (nonatomic, strong) UIColor *textColor;
/** 文字边缘颜色  默认clearColor */
@property (nonatomic, strong) UIColor *textEdgeColor;
/** 下划线颜色   默认clearColor */
@property (nonatomic, strong) UIColor *underlineColor;
/** 边框颜色    默认clearColor */
@property (nonatomic, strong) UIColor *borderColor;
/** 边距(边框与文字距离) 默认值10 */
@property (nonatomic, assign) NSInteger margin;
/** 延迟出现时间（单位为毫秒）默认值 0 */
@property (nonatomic, assign) NSUInteger delayTime;
/** 用户id */
@property (nonatomic, assign) NSInteger userId;

@end

NS_ASSUME_NONNULL_END
