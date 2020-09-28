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
extern NSString * const __nonnull LBLelinkPassthErrorDomain;
extern NSString * const __nonnull LBLelinkUserInteretsErrorDomain;
extern NSString * const __nonnull LBLelinkLogErrorDomain;

/** 搜索相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkBrowserErrorCode) {
    LBLelinkBrowserErrorUnknown = -1000,                            // 未知错误
    LBLelinkBrowserErrorCodeNotAuth = -1005,                        // 乐播SDK未授权
    LBLelinkBrowserErrorCanNotStartDLNA = -1100,                    // 启动DLNA搜索失败，此问题已优化，不会再有此错误码
    LBLelinkBrowserErrorUnsupportedQRCodeStringValue = -1200,       // 无法识别的二维码信息
    LBLelinkBrowserErrorNoInternet = -1300,                         // 无网络
    LBLelinkBrowserErrorNoServiceType = -1400,                      // SDK服务类型设置错误
    LBLelinkBrowserErrorMissingRequiredConfiguration = -1500,       // 缺少本地网络访问所需的配置，Info.plist中需要配置NSBonjourServices(_leboremote._tcp)和NSLocalNetworkUsageDescription，兼容iOS14
};

/** 连接相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkConnectionErrorCode) {
    LBLelinkConnectionErrorUnknown = -2000,                         // 未知错误
    LBLelinkConnectionErrorLelinkServiceIsNil = -2001,              // LBLelinkService为空
    LBLelinkConnectionErrorIncrrectServiceType = -2002,             // 错误的ServiceType
    LBLelinkConnectionErrorServiceAvailableAllInvalid = -2003,      // 服务所有有效性是无效的
    LBLelinkConnectionErrorInnerLelinkServiceIsNil = -2100,         // 内部的乐联服务数据为空
    LBLelinkConnectionErrorInnerLelinkReceiverLowVersion = -2101,   // 接收端的版本低，低于3.0
    LBLelinkConnectionErrorIMUidOfReceiverIsNil = -2200,            // 接收端uid为空
    LBLelinkConnectionErrorIMPushRequestFail = -2201,               // 网络请求失败
    LBLelinkConnectionErrorIMWaitForTimout = -2202,                 // 防骚扰模式：等待用户允许超时
    LBLelinkConnectionErrorIMUserRefused = -2203,                   // 防骚扰模式：用户拒绝连接（老版本的所有绝状态，没有细分）
    LBLelinkConnectionErrorIMUserRefusedDueToTimeout = -2204,       // 防骚扰模式：超时拒绝（新版本接收端增加）
    LBLelinkConnectionErrorIMUserRefusedDueToUserAction = -2205,    // 防骚扰模式：用户点击拒绝（新版本接收端增加）
    LBLelinkConnectionErrorIMUserRefusedDueToBlacklist = -2206,     // 防骚扰模式：发送端在接收端的黑名单列表中被自动拒绝（新版本接收端增加）
    LBLelinkConnectionErrorInitiateConnectFailed = -2301,           // 发起连接失败
    LBLelinkConnectionErrorDataEncryptFailed = -2302,               // 数据加密失败
    LBLelinkConnectionErrorXMLFormatFailed = -2303,                 // 数据xml格式化失败
    LBLelinkConnectionErrorShakeHandsVerifyFailed = -2304,          // 握手验证失败
    LBLelinkConnectionErrorHmacDataVerifyFailed = -2305,            // 数据签名验证失败
    LBLelinkConnectionErrorScreenCodeAuthError = -2400,             // 屏幕码错误
    LBLelinkConnectionErrorUserScreenCodeInputCancel = -2401,       // 用户屏幕码输入取消
    LBLelinkConnectionErrorScreenCodeModelProhibitGrab = -2402,     // 屏幕码模式禁止抢占
    LBLelinkConnectionErrorReceiverResponseError = -2500,           // 对端回复错误
    LBLelinkConnectionErrorDisconnectAbnormal = -2600,              // 连接异常断开错误
    LBLelinkConnectionErrorConnectionReceiverSocketFailed = -2601   // 连接接收端Socket失败
};

/** 播放相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkPlayerErrorCode) {
    LBLelinkPlayerErrorUnknown = -3000,                             // 未知错误
    LBLelinkPlayerErrorPlayerItemIsNil = -3001,                     // LBLelinkPlayerItem为空
    LBLelinkPlayerErrorPlayerAvailableBarrageIsNil = -3002,         // 有效LBLelinkTextBarrage为空
    LBLelinkPlayerErrorInnerLelinkConnectionNotConnected = -3100,   // 乐联：未连接
    LBLelinkPlayerErrorInnerLelinkReceiverPlayFailed = -3101,       // 乐联：接收端播放失败
    LBLelinkPlayerErrorUpnpUnavailable = -3200,                     // DLNA不可用
    LBLelinkPlayerErrorIMConnectionNotConnected = -3300,            // IM未连接
    LBLelinkPlayerErrorIMUidIsNil = -3301,                          // 接收端的uid为空
    LBLelinkPlayerErrorIMMediaUrlIsNil = -3302,                     // 媒体播放url为空
    LBLelinkPlayerErrorIMPushFailed = -3303,                        // IM推送失败
    LBLelinkPlayerErrorNotSupportPushBarrage = -3401,               // 不支持推送弹幕
    LBLelinkPlayerErrorNotSupportGetScreenCapture = -3501,          // 不支持获取接收端屏幕截图
    LBLelinkPlayererrorAlreadyBeCapturing = -3502,                  // 正在获取截图中
    LBLelinkPlayererrorCaptureTimeOut = -3503,                      // 获取屏幕截图超时
    LBLelinkPlayerErrorPushPhotoFail = -3601,                       // 推送照片失败
    LBLelinkPlayerErrorStopPhotoFail = -3602,                       // 退出照片投屏失败
    LBLelinkPlayerErrorNotSupportChangePlaySpeed = -3701,           // 不支持倍速播放
};

/** 互动广告相关错误 */
typedef NS_ENUM(NSInteger, LBADInterfaceErrorCode) {
    LBADInterfaceErrorCodeAppIDAbsence = -4000,                     // APPID缺失
    LBADInterfaceErrorCodeADInfoNull = -4001,                       // 没有广告数据
    LBADInterfaceErrorCodeIncorrectParameter = -4002,               // 参数不正确
    LBADInterfaceErrorCodeServerError = -4003,                      // 服务器错误
    LBADInterfaceErrorCodeUnknown = -4004,                          // 未知错误
};

/** 设置检测地址错误码 */
typedef NS_ENUM(NSInteger, LBSetMonitorErrorCode) {
    LBSetMonitorErrorCodeResponseNoData = -5000,
    LBSetMonitorErrorCodeServerError = -5001,
    LBSetMonitorErrorCodeParameterError = -5002,
    LBSetMonitorErrorCodeAuthError = -5003,
    LBSetMonitorErrorCodeMonitorInfoSendToTVFailed = -5004,
    LBSetMonitorErrorCodeMonitorURLInconform = -5005,
    LBSetMonitorErrorCodeTokenInvalid = -5006,
    LBSetMonitorErrorCodeUnknown = -5007,
};


/** 透传相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkPassthErrorCode) {
    LBLelinkPassthErrorNotSupportPassth = -6000,                    //不支持透传
    LBLelinkPassthErrorDataIsNil = -6001,                           //数据为空
    LBLelinkPassthErrorNotLeBoAPP = -6002,                          //不是乐播app
    LBLelinkPassthErrorNotSpecifiedTargetAppId = -6003,             //未指定对端appid
    LBLelinkPassthErrorConnectionNotConnected = -6004,              //未连接
    LBLelinkPassthErrorJsonSerializationFailed = -6005,             //json序列化失败
    LBLelinkPassthErrorDataHandleUnknown = -6006,                   //数据错误未知
    LBLelinkPassthErrorDataHandleNotSupport = -6007,                //数据不支持
    LBLelinkPassthErrorDataHandleAnalysisException = -6008,         //数据解析异常
    LBLelinkPassthErrorDataHandleLackParam = -6009,                 //缺失必要参数
    LBLelinkPassthErrorDataHandleAppIDError = -6010,                //转发的appID错误，与当前应用相同时才会转发
    LBLelinkPassthErrorReceiverNotSupportManifestType = -6011,      //接收端sm中不支持的消息类型，
    LBLelinkPassthErrorReceiverResponseUnknown = -6016,             //接收端回应未知异常
    LBLelinkPassthErrorReceiverResponseNotSupport = -6017,          //接收端回应不支持的消息类型
    LBLelinkPassthErrorReceiverResponseDataAnalysisException = -6018,//接收端回应数据解析异常
    LBLelinkPassthErrorReceiverResponseLackParam = -6019,           //接收端回应缺少必要参数
    LBLelinkPassthErrorReceiverResponseAppIDError = -6020,          //接收端回应appID错误
};

/** 权益相关错误码 */ 
typedef NS_ENUM(NSInteger, LBLelinkInterestsErrorCode) {
    LBLelinkInterestsCodeUnknownError = -7000,          // 未知错误
    LBLelinkInterestsCodeUnloadError = -7001,           // 未进行请求
    LBLelinkInterestsCodeInputDataError = -7002,        // 输入参数转json失败
    LBLelinkInterestsCodeParameterError = -7003,        // 参数错误
    LBLelinkInterestsCodeAuthError = -7004,             // 认证错误
    LBLelinkInterestsCodeServerExceptionError = -7005,  // 服务器异常
    LBLelinkInterestsCodeTokenExpireError = -7006,      // token失效
    LBLelinkInterestsCodeDataError = -7007,             // 数据错误
};

/** 日志相关错误码 */
typedef NS_ENUM(NSInteger,LBLelinkLogErrorCode) {
    LBLelinkLogErrorCodeUploadLogFileNotExist = -8000,         //日志文件不存在
    LBLelinkLogErrorCodeUploadLogFilePathEmpty = -8001,         //日志上传路径为空
    LBLelinkLogErrorCodeUploadLogServerResponseFailure = -8002,    //日志上传服务器回复失败
    LBLelinkLogErrorCodeUploadLogExistsIllegalCharacter = -8003,    //日志上传存在非法字符
    LBLelinkLogErrorCodeUploadLogRequestFailed = -8004,    //日志上传请求失败
    LBLelinkLogErrorCodeUploadLogFailedOther = - 8005,           //日志上传失败其它原因
};
