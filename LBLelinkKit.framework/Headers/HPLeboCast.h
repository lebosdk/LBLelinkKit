//
//  HPLeboCast.h
//
//  Created by lmx on 2016/11/20.
//  Copyright © 2016年 lmx. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^CompleteBlock)(NSError * error);

/** 镜像工具错误码 */
typedef enum : NSUInteger {
    /** 繁忙 */
    HPLeboCastToolsErrorCodeBusy = 4000,
    /** 超时 */
    HPLeboCastToolsErrorCodeTimeOut,
    /** 未知状态 */
    HPLeboCastToolsErrorCodeUnknown,
    /** 打开投屏时的失败回调，因为投屏已经打开了 */
    HPLeboCastToolsErrorCodeOpenLeboCastFailBecauseIsLeboCasting,
    /** 关闭投屏失败，因为投屏已经处于关闭状态 */
    HPLeboCastToolsErrorCodeCloseLeboCastFailBecauseIsClosed,
    /** 关闭投屏失败，因为当前是AirPlay状态，请使用关闭AirPlay的接口方法关闭（接口使用错误） */
    HPLeboCastToolsErrorCodeCloseLeboCastFailBecauseIsLeboAing,
    /** 设备名称错误 */
    HPLeboCastToolsErrorCodeDeviceNameIncrrect,
    /** 版本较老，不支持投屏，需要升级电视接收端版本 */
    HPLeboCastToolsErrorCodeOldVersion,
    /** 安装设备 */
    HPLeboCastToolsErrorCodeInstallDevice,
    HPLeboCastToolsErrorCodeAuthorizeKeyFailure = 4040,//key授权失败
} HPLeboCastToolsErrorCode;

@interface HPLeboCast : NSObject

/** 设置投屏超时时间，默认5秒钟,注意：设置时值要大于3.5秒，否则无效 */
@property (nonatomic, assign) NSTimeInterval deltaTimeInterval;


/** 系统处于镜像已经连接的状态 可使用KVO监听 */
@property (nonatomic, assign,readonly) BOOL stateLeboCast;
/** 系统处于AirPlay或者镜像的关闭状态 可使用KVO监听*/
@property (nonatomic, assign,readonly) BOOL stateClosed;


/**
 根据设备名称，投屏

 @param deviceName 设备名称
 @param completeBlock 完成回调
 */
- (void)continueOpenLeboCastWithDeviceName:(NSString *)deviceName completeBlock:(CompleteBlock)completeBlock;

/**
 关闭投屏

 @param completeBlock 完成回调
 */
- (void)closeLeboCastComplete:(CompleteBlock)completeBlock;

@end
