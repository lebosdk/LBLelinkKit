//
//  LBCastTool.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/5/22.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LBLelinkService;

@interface LBLelinkCast : NSObject

/**
 开启镜像接口，仅限于iOS10及以下的系统版本可以实现打开系统的镜像，iOS 11及以上不支持

 @param lelinkService 仅支持局域网乐联设备
 @param block 回调，error为空则成功，不为空则失败
 */
+ (void)castToLelinkService:(LBLelinkService *)lelinkService complete:(void(^)(NSError * error))block;

/**
 停止镜像接口，仅限于iOS10及以下的系统版本可以实现关闭系统的镜像，iOS 11及以上不支持

 @param block 回调，error为空则成功，不为空则失败
 */
+ (void)stopCastComplete:(void(^)(NSError * error))block;

@end
