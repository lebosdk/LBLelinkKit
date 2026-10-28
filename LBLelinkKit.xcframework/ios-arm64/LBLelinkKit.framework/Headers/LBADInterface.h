//
//  LBADInterface.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/6/12.
//  Copyright © 2018 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class LBADInfo;

@interface LBADInterface : NSObject

#pragma mark - 获取广告接口
/**
 获取启动广告接口， APP启动后并且在SDK授权成功后可以调用此接口，以获取启动广告相关信息

 @param timeout 超时时间
 @param completeBlock 完成回调，广告请求成功，则adInfo不为nil，error为nil；否则adInfo为nil，error不为nil，错误信息将以错误码的形式给出
 */
+ (void)fetchLaunchingAdInfoTimeout:(NSTimeInterval)timeout completeHandler:(void(^)(LBADInfo * _Nullable adInfo, NSError * _Nullable error))completeBlock;

/**
 获取连接广告接口， APP与接收端连接成功后，可以调用此接口，获取连接时的广告相关信息

 @param timeout 超时时间
 @param completeBlock 完成回调，广告请求成功，则adInfo不为nil，error为nil；否则adInfo为nil，error不为nil，错误信息将以错误码的形式给出
 */
+ (void)fetchConnectionAdInfoTimeout:(NSTimeInterval)timeout completeHandler:(void(^)(LBADInfo * _Nullable adInfo, NSError * _Nullable error))completeBlock;

/**
 SDK内部使用的互动广告获取接口，APP层可在LBLelinkConnectionDelegate中收到互动广告回调

 @param timeout 超时
 @param param 所需的参数
 @param completeBlock 完成回调
 */
+ (void)fetchInteractiveAdInfoTimeout:(NSTimeInterval)timeout param:(NSDictionary *)param completeHandler:(void(^)(LBADInfo * _Nullable adInfo, NSError * _Nullable error))completeBlock;

#pragma mark - 广告展示汇报

/**
 广告开始展示时调用

 @param adInfo 广告信息
 */
+ (void)adReportOnStartShow:(LBADInfo *)adInfo;

/**
 广告结束展示时调用

 @param adInfo 广告信息
 @param duration 展示时长，单位秒
 @param state 状态：YES->成功展示，NO->展示出错
 */
+ (void)adReportOnEndShow:(LBADInfo *)adInfo duration:(NSInteger)duration state:(BOOL)state;

@end

NS_ASSUME_NONNULL_END
