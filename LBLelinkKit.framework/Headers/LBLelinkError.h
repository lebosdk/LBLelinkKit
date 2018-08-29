//
//  LBLelinkError.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/26.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const __nonnull LBLelinkBrowserErrorDomain;
extern NSString * const __nonnull LBLelinkConnectionErrorDomain;
extern NSString * const __nonnull LBLelinkPlayerErrorDomain;
extern NSString * const __nonnull LBADInterfaceErrorDomain;

/** 搜索相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkBrowserErrorCode) {
    LBLelinkBrowserErrorUnknown = -1000,                            // 未知错误
    LBLelinkBrowserErrorCodeNotAuth = -1005,                        // 乐播SDK未授权
    LBLelinkBrowserErrorCanNotStartDLNA = -1100,                    // 启动DLNA搜索失败
    LBLelinkBrowserErrorUnsupportedQRCodeStringValue = -1200,       // 无法识别的二维码信息
};

/** 连接相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkConnectionErrorCode) {
    LBLelinkConnectionErrorUnknown = -2000,                         // 未知错误
    LBLelinkConnectionErrorLelinkServiceIsNil = -2001,              // LBLelinkService为空
    LBLelinkConnectionErrorIncrrectServiceType = -2002,             // 错误的ServiceType
    LBLelinkConnectionErrorInnerLelinkServiceIsNil = -2100,         // 内部的乐联服务数据为空
    LBLelinkConnectionErrorInnerLelinkReceiverLowVersion = -2101,   // 接收端的版本低，低于3.0
    LBLelinkConnectionErrorIMUidOfReceiverIsNil = -2200,            // 接收端uid为空
    LBLelinkConnectionErrorIMPushRequestFail = -2201,               // 网络请求失败
    LBLelinkConnectionErrorIMWaitForTimout = -2202,                 // 防骚扰模式：等待用户允许超时
    LBLelinkConnectionErrorIMUserRefused = -2203,                   // 防骚扰模式：用户拒绝连接（老版本的所有绝状态，没有细分）
    LBLelinkConnectionErrorIMUserRefusedDueToTimeout = -2204,       // 防骚扰模式：超时拒绝（新版本接收端增加）
    LBLelinkConnectionErrorIMUserRefusedDueToUserAction = -2205,    // 防骚扰模式：用户点击拒绝（新版本接收端增加）
    LBLelinkConnectionErrorIMUserRefusedDueToBlacklist = -2206,     // 防骚扰模式：发送端在接收端的黑名单列表中被自动拒绝（新版本接收端增加）
};

/** 播放相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkPlayerErrorCode) {
    LBLelinkPlayerErrorUnknown = -3000,                             // 未知错误
    LBLelinkPlayerErrorPlayerItemIsNil = -3001,                     // LBLelinkPlayerItem为空
    LBLelinkPlayerErrorInnerLelinkConnectionNotConnected = -3100,   // 乐联：未连接
    LBLelinkPlayerErrorInnerLelinkReceiverPlayFailed = -3101,       // 乐联：接收端播放失败
    LBLelinkPlayerErrorUpnpUnavailable = -3200,                     // DLNA不可用
    LBLelinkPlayerErrorIMConnectionNotConnected = -3300,            // IM未连接
    LBLelinkPlayerErrorIMUidIsNil = -3301,                          // 接收端的uid为空
    LBLelinkPlayerErrorIMMediaUrlIsNil = -3302,                     // 媒体播放url为空
    LBLelinkPlayerErrorIMPushFailed = - 3303,                       // IM推送失败
};

typedef NS_ENUM(NSInteger, LBADInterfaceErrorCode) {
    LBADInterfaceErrorCodeAppIDAbsence = -4000,                     // APPID缺失
    LBADInterfaceErrorCodeADInfoNull = -4001,                       // 没有广告数据
    LBADInterfaceErrorCodeIncorrectParameter = -4002,               // 参数不正确
    LBADInterfaceErrorCodeServerError = -4003,                      // 服务器错误
    LBADInterfaceErrorCodeUnknown = -4004,                          // 未知错误
};


