//
//  LBLelinkReverseControl.h
//  AppleSenderSDK
//
//  Created by wangzhijun on 2020/12/22.
//  Copyright © 2020 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LBLelinkReverseControl;
@class LBLelinkConnection;
@class LBLelinkTouch;

NS_ASSUME_NONNULL_BEGIN

@protocol LBLelinkReverseControlDelegate <NSObject>

/// 反控错误
/// @param rverseControl rverseControl
/// @param error error
- (void)lelinkReverseControl:(LBLelinkReverseControl *)rverseControl onError:(NSError *)error;

/// 开始反控
/// @param rverseControl rverseControl
/// @param lelinkConnection 设备连接模型
- (void)lelinkReverseControl:(LBLelinkReverseControl *)rverseControl beginReverse:(LBLelinkConnection *)lelinkConnection;

/// 结束反控
/// @param rverseControl rverseControl
/// @param lelinkConnection 设备连接模型
- (void)lelinkReverseControl:(LBLelinkReverseControl *)rverseControl endReverse:(LBLelinkConnection *)lelinkConnection;

/// 更新反控数据
/// @param rverseControl rverseControl
/// @param touches 反控数据模型
- (void)lelinkReverseControl:(LBLelinkReverseControl *)rverseControl updateTouchArray:(NSArray<LBLelinkTouch *> *)touches;
@end

@interface LBLelinkReverseControl : NSObject

/** 反控代理 */
@property (nonatomic, weak) id<LBLelinkReverseControlDelegate> delegate;
/** 当前连接 */
@property (nonatomic, strong) LBLelinkConnection *lelinkConnection;

- (instancetype)init;
- (instancetype)initWithConnection:(LBLelinkConnection *)connection;

/// 准备接收反控数据
- (void)prepare;
- (void)stop;

@end

NS_ASSUME_NONNULL_END
