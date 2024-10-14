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
extern NSString * const __nonnull LBLelinkReverseControlErrorDomain;
extern NSString * const __nonnull LBLelinkUploadFileErrorDomain;
extern NSString * const __nonnull LBLelinkNetworkErrorDomain;
extern NSString * const __nonnull LBLelinkSaaSInterfaceErrorDomain;
extern NSString * const __nonnull LBLelinkFavoriteErrorDomain;
extern NSString * const __nonnull LBLelinkIMMessageErrorDomain;

/** 搜索相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkBrowserErrorCode) {
    LBLelinkBrowserErrorUnknown = -1000,                            // 未知错误
    LBLelinkBrowserErrorCodeNotAuth = -1005,                        // 乐播SDK未授权
    LBLelinkBrowserErrorIncorrectParameter = -1010,                 // 参数错误
    LBLelinkBrowserErrorReceiverLanUnableConnect = -1011,           // 与接收端局域网无法连接
    LBLelinkBrowserErrorReceiverVersionNotSupport = -1012,          // 接收端版本不支持
    LBLelinkBrowserErrorReceiverNotOnline = -1013,                  // 接收端不在线
    LBLelinkBrowserErrorCanNotStartDLNA = -1100,                    // 启动DLNA搜索失败，此问题已优化，不会再有此错误码
    LBLelinkBrowserErrorUnsupportedQRCodeStringValue = -1200,       // 无法识别的二维码信息
    LBLelinkBrowserErrorCastCodeNotExist = -1201,                   // 投屏码不存在
    LBLelinkBrowserErrorCastCodeIsMeetingID = -1202, ///< 当前输入的是会议号
    LBLelinkBrowserErrorNoInternet = -1300,                         // 无网络
    LBLelinkBrowserErrorNoServiceType = -1400,                      // SDK服务类型设置错误
    LBLelinkBrowserErrorMissingRequiredConfiguration = -1500,       // 缺少本地网络访问所需的配置，Info.plist中需要配置NSBonjourServices(_leboremote._tcp)和NSLocalNetworkUsageDescription，兼容iOS14
    LBLelinkBrowserErrorDisableSearchStyleNotSupport = -1600,       // 禁止搜索方式不支持
    LBLelinkBrowserErrorPauseSearchStyleNotSupport = -1601,         // 暂停搜索方式不支持
    LBLelinkBrowserErrorContinueSearchStyleNotSupport = -1602,      // 继续搜索方式不支持
    LBLelinkBrowserErrorNetworkRequestFailed = -1603,               // 网络请求失败
    LBLelinkBrowserErrorRequestResponseStateAbnormal = -1604,       // 网络响应状态异常
    LBLelinkBrowserErrorDLNAAnalysisData = -1605,                   // DLNA解析异常
    LBLelinkBrowserErrorDLNASearchFiled = -1606,                    // DLNA搜索错误
    LBLelinkBrowserErrorMDNSAnalysisData = -1607,                   // MDNS解析异常
    LBLelinkBrowserErrorMDNSSearchFiled = -1608,                    // MDNS搜索错误
    LBLelinkBrowserErrorResponseDataIsEmpty = -1609,                // 脱敏字符匹配数据为空
    LBLelinkBrowserErrorBluetoothSearchFiled = -1610,               // 蓝牙搜索失败
    LBLelinkBrowserErrorSimplifyIsOpen = -1611,                     // simplify模式
};

/** 连接相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkConnectionErrorCode) {
    LBLelinkConnectionErrorUnknown = -2000,                         // 未知错误
    LBLelinkConnectionErrorLelinkServiceIsNil = -2001,              // LBLelinkService为空
    LBLelinkConnectionErrorIncrrectServiceType = -2002,             // 错误的ServiceType
    LBLelinkConnectionErrorServiceAvailableAllInvalid = -2003,      // 服务所有有效性是无效的
    LBLelinkConnectionErrorInnerLelinkServiceIsNil = -2100,         // 内部的乐联服务数据为空
    LBLelinkConnectionErrorInnerLelinkReceiverLowVersion = -2101,   // 接收端的版本低，低于3.0
    LBLelinkConnectionErrorInnerLelinkReceiverRefused = -2102,      // 被收端拒绝连接
    LBLelinkConnectionErrorIMUidOfReceiverIsNil = -2200,            // 接收端uid为空
    LBLelinkConnectionErrorIMPushRequestFail = -2201,               // 网络请求失败
    LBLelinkConnectionErrorIMWaitForTimout = -2202,                 // 防骚扰模式：等待用户允许超时
    LBLelinkConnectionErrorIMUserRefused = -2203,                   // 防骚扰模式：用户拒绝连接（老版本的所有绝状态，没有细分）
    LBLelinkConnectionErrorIMUserRefusedDueToTimeout = -2204,       // 防骚扰模式：超时拒绝（新版本接收端增加）
    LBLelinkConnectionErrorIMUserRefusedDueToUserAction = -2205,    // 防骚扰模式：用户点击拒绝（新版本接收端增加）
    LBLelinkConnectionErrorIMUserRefusedDueToBlacklist = -2206,     // 防骚扰模式：发送端在接收端的黑名单列表中被自动拒绝（新版本接收端增加）
    LBLelinkConnectionErrorIMRequestParametersNotCorrect = -2207,   // IM请求参数不对
    LBLelinkConnectionErrorIMAuthFailed = -2208,                   // IM授权失败
    LBLelinkConnectionErrorIMTVOffline = -2209,                     // TV公网不在线
    LBLelinkConnectionErrorIMServerError = -2210,                   // IM服务器错误
    LBLelinkConnectionErrorIMTokenExpired = -2211,                  // IM的tonken过期
    LBLelinkConnectionErrorIMResponseDataNil = -2212,               // IM响应参数为空
    LBLelinkConnectionErrorIMUserRefusedDueToGetPictureFailed = -2213, // 防骚扰模式：接收端获取认证图片失败
    LBLelinkConnectionErrorIMUserRefusedDueToVerificateFailed = -2214, // 防骚扰模式：验证图片失败
    LBLelinkConnectionErrorIMReceiverNotSupport = -2215,            // 收端不支持 IM 功能
    LBLelinkConnectionErrorInitiateConnectFailed = -2301,           // 发起连接失败
    LBLelinkConnectionErrorDataEncryptFailed = -2302,               // 数据加密失败
    LBLelinkConnectionErrorXMLFormatFailed = -2303,                 // 数据xml格式化失败
    LBLelinkConnectionErrorShakeHandsVerifyFailed = -2304,          // 握手验证失败
    LBLelinkConnectionErrorHmacDataVerifyFailed = -2305,            // 数据签名验证失败
    LBLelinkConnectionErrorScreenCodeAuthError = -2400,             // 屏幕码错误
    LBLelinkConnectionErrorUserScreenCodeInputCancel = -2401,       // 用户屏幕码输入取消
    LBLelinkConnectionErrorScreenCodeModelProhibitGrab = -2402,     // 屏幕码模式禁止抢占
    LBLelinkConnectionErrorScreenCodeError = -2403,                 // 屏幕码连接错误
    LBLelinkConnectionErrorReceiverResponseError = -2500,           // 对端回复错误
    LBLelinkConnectionErrorDisconnectAbnormal = -2600,              // 连接异常断开错误
    LBLelinkConnectionErrorConnectionReceiverSocketFailed = -2601,  // 连接接收端Socket失败
    LBLelinkConnectionErrorJsonSerializationFailed = -2602,         //json序列化失败
    LBLelinkConnectionErrorTokenTokenEmptyNeedReauthorize = -2603,  //token为空需重新授权
    LBLelinkConnectionErrorCurrentTemporaryNotAllowed  = -2604,     // 不允许抢占当前模式
    LBLelinkConnectionErrorCurrentTemporaryMirroring = -2605,       // 设备镜像中
    LBLelinkConnectionErrorPinCodeIsNil = -2606,                    // 投屏码为空
    LBLelinkConnectionErrorAtRisk = -2607, /**< 当前连接的设备为风险设备 */
    LBLelinkConnectionErrorNOConfirm = -2608, /**< 不用确认 */
    LBLelinkConnectionErrorFaceRecognition = -2709, /**< 当前连接需要人脸识别 */
    LBLelinkConnectionErrorRecordFailed = -2710,    /**< Record 错误 */
    LBLelinkConnectionErrorBadRequestRejected = -2711,              // 坏的请求被拒绝
};

/** 播放相关错误代码 */
typedef NS_ENUM(NSInteger, LBLelinkPlayerErrorCode) {
    LBLelinkPlayerErrorUnknown = -3000,                             // 未知错误
    LBLelinkPlayerErrorPlayerItemIsNil = -3001,                     // LBLelinkPlayerItem为空
    LBLelinkPlayerErrorPlayerAvailableBarrageIsNil = -3002,         // 有效LBLelinkTextBarrage为空
    LBLelinkPlayerErrorConnectionNotConnected = -3003,              // LBLelinkConnection未连接
    LBLelinkPlayerErrorInnerLelinkConnectionNotConnected = -3100,   // 乐联：未连接
    LBLelinkPlayerErrorInnerLelinkReceiverPlayFailed = -3101,       // 乐联：接收端播放失败
    LBLelinkPlayerErrorUpnpPlayerPlayFailed = -3102,                // 播放失败
    LBLelinkPlayerErrorUpnpPlayerPauseFailed = -3103,               // 暂停失败
    LBLelinkPlayerErrorUpnpPlayerStopFailed  = -3104,               // 停止失败
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
    LBLelinkPlayerErrorNotSupportCacheVideoList = -3702,            // 不支持缓存视频列表
    LBLelinkPlayerErrorNotSupportOperateOnADPlaying = -3703,        // 不支持操作在广告播放中
    LBLelinkPlayerErrorNotSupportPushVideoList = -3801,             // 不支持推送视频列表
    LBLelinkPlayerErrorItemArrayAbnormal = -3802,                   // ItemArray数据异常
    LBLelinkPlayerErrorItemArrayCountExceedLimit = -3803,           // ItemArray数量超限，最大100个
    LBLelinkPlayerErrorLelinkPlayerConnectionNotConnected = -3804,  // lelink播放器连接未连接
    LBLelinkPlayerErrorJsonSerializationFailed = -3805,             //json序列化失败
    LBLelinkPlayerErrorNotSupportSwitchAudioTrack = -3860,          // 不支持切换音轨
    LBLelinkPlayerErrorNotSupportSwitchTemporaryPrivateMode = -3861,// 不支持临时独占模式
    LBLelinkPlayerErrorNotSupportContorPlayerCommand = -3862, // 不支持发送播放器切换指令
    LBLelinkPlayerErrorNotSupportSetPlayerPortCommand = -3862, // 不支持播放器设置端口
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
    LBLelinkPassthErrorReceiverSocketErrorDisConnection = -6021,    // 接收端回应socket断开错误
    LBLelinkPassthErrorReceiverSocketDataError = -6022,             // 接收端回应socket参数出错
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
    LBLelinkInterestsErrorCodeRequestFailed = -7008,    // 请求失败
    LBLelinkInterestsErrorCodeSignVerifyFailed = -7009, // 签名验证失败
    LBLelinkInterestsErrorCodeChannelNotEnabledLicenseAuthMode = -7010,  //渠道未启用License授权模式
    LBLelinkInterestsErrorCodeDisabledLicenseAuthMode = -7011,           //已禁用License授权模式
    LBLelinkInterestsErrorCodeLicenseAuthNumberFull = -7012,             //License授权数量已满
    LBLelinkInterestsErrorCodeLicenseAuthOutsideTimeRange = -7013,       //超出License授权时间范围
    LBLelinkInterestsErrorCodeLicenseAuthOther = -7014,                  //License授权其它错误
    LBLelinkInterestsErrorCodeNoLocalLicenseData = -7015,                //无本地License授权数据，请联网授权
    LBLelinkInterestsErrorCodeLackParam = -7016,                         //缺失必要参数
};

/** 日志相关错误码 */
typedef NS_ENUM(NSInteger,LBLelinkLogErrorCode) {
    LBLelinkLogErrorCodeUploadLogFileNotExist = -8000,         //日志文件不存在
    LBLelinkLogErrorCodeUploadLogFilePathEmpty = -8001,         //日志上传路径为空
    LBLelinkLogErrorCodeUploadLogServerResponseFailure = -8002,    //日志上传服务器回复失败
    LBLelinkLogErrorCodeUploadLogExistsIllegalCharacter = -8003,    //日志上传存在非法字符
    LBLelinkLogErrorCodeUploadLogRequestFailed = -8004,    //日志上传请求失败
    LBLelinkLogErrorCodeUploadLogFailedOther = - 8005,           //日志上传失败其它原因
    LBLelinkLogErrorCodeUploadLogNotAllowChannle = - 8006,      // 上报日志渠道禁止
};

typedef NS_ENUM(NSInteger,LBLelinkReverseControlErrorCode) {
    LBLelinkReverseControlErrorLelinkConnectionIsNil = -9000,    //连接模型为空
    LBLelinkReverseControlErrorConnectionNotConnected = -9001,   //未连接
    LBLelinkReverseControlErrorParameterError = -9002,           //参数错误
    LBLelinkReverseControlErrorInitiateConnectFailed = -9003,    // 发起连接失败
};

typedef NS_ENUM(NSInteger, LBLelinkUploadFileErrorCode) {
    LBLelinkUploadFileErrorCodeFilePathIsNil = -10000,   // 文件路径为空
};

typedef NS_ENUM(NSInteger, LBLelinkNetworkErrorCode) {
    LBLelinkNetworkErrorConnectionNotConnected = -11000,  //
    LBLelinkNetworkErrorParamenterError = -11001,         // 参数出错
    LBLelinkNetworkErrorNetworkConnectionFail = -11002,            // 无效网络或网络连接错误
    
};

/** SaaS 接口相关错误码 */
typedef NS_ENUM(NSInteger, LBLelinkSaaSInterfaceErrorCode) {
    LBLelinkSaaSInterfaceErrorNotConnected = -12000,  //
    LBLelinkSaaSInterfaceErrorParamenterError = -12001,         // 参数出错
    LBLelinkSaaSInterfaceErrorNetworkConnectionFail = -12002,            // 无效网络或网络连接错误
    LBLelinkSaaSInterfaceErrorCreated = -12003,         // 已创建
    LBLelinkSaaSInterfaceErrorUnauthorized = -12004,    // 未经授权
    LBLelinkSaaSInterfaceErrorForbidden = -12005,       // 被禁止
    LBLelinkSaaSInterfaceErrorNotFound  = -12006,       // 不存在
    LBLelinkSaaSInterfaceErrorOther  = -12007,          // 其他错误 （后台返回的业务错误）
    LBLelinkSaaSInterfaceErrorDataIsNil = -12008,       // 数据为空
    LBLelinkSaaSInterfaceErrorDataInconsistency = -12009,// 图形验证码与TV端数据不一致
    LBLelinkSaaSInterfaceErrorInvalidScreenCastingCode = -12010,//无效投屏码
    LBLelinkSaasInterfaceErrorLoginInvalidation = -12011, /**< 用户登录已失效 */
};

/** 设备收藏和保存历史投屏记录 相关接口错误码*/
typedef NS_ENUM(NSInteger, LBLelinkFavoriteHistoryErrorCode) {
    LBLelinkFavoriteHistoryErrorCodeUnknown = -12100, // 未知错误
    LBLelinkFavoriteHistoryErrorCodeBusinessExceptions = -12101, // 业务异常
    LBLelinkFavoriteHistoryErrorCodeAuthenticationFailed = -12102, // 鉴权失败
    LBLelinkFavoriteHistoryErrorCodeRequestDenied = -12103,  // 请求被拒绝
    LBLelinkFavoriteHistoryErrorCodeChannelServiceNotOpen = -12104, // 渠道服务未开通
    LBLelinkFavoriteHistoryErrorCodeRequestNotFound = -12105,  // 没找到请求
    LBLelinkFavoriteHistoryErrorCodeServerException = -12106,  // 服务异常
    LBLelinkFavoriteHistoryErrorCodeNoDataNotFound = -12107,  // 没找到对应的数据
    LBLelinkFavoriteHistoryErrorCodeMessageUnreadable = -12108,  // 消息不能读取
    LBLelinkFavoriteHistoryErrorCodeTheRequestNotSupported = -12109,  // 不支持当前请求方法
    LBLelinkFavoriteHistoryErrorCodeTheMediaTypeNotSupported = -12110, // 不支持当前媒体类型
    LBLelinkFavoriteHistoryErrorCodeRequestParameMissing = -12111,  // 缺少必要的请求参数
    LBLelinkFavoriteHistoryErrorCodeRequestParameTypeError = -12112, // 请求参数类型错误
    LBLelinkFavoriteHistoryErrorCodeRequestParameBindError = -12113,  // 请求参数绑定错误
    LBLelinkFavoriteHistoryErrorCodeParameVerificationFailure = -12114, // 参数校验失败
    LBLelinkFavoriteHistoryErrorCodeSetAliasExisting = -12115,  // 设置别名已经存在
    LBLelinkFavoriteHistoryErrorCodeSetAliasMaximum = -12116,  // 设置别名的字段超过最大字数
    LBLelinkFavoriteHistoryErrorCodeAliasSensitive = -12117, // 存在敏感词字段
    LBLelinkFavoriteHistoryErrorCodeAliasDeviceNotExisting = -12118, // 设置别名的设备不存在
    LBLelinkFavoriteHistoryErrorCodeFavoriteMaximum = -12119,  // 超过收藏最大数量
    LBLelinkFavoriteHistoryErrorCodeFavoriteInfoNotExist = -12120,  // 收藏信息不存在
    LBLelinkFavoriteHistoryErrorCodeHistoryExist = -12121,  // 收藏关系标识ID+收端APPID+收端UID已存在收藏记录
    LBLelinkFavoriteHistoryErrorCodeHistoryNotExist = -12122, // 设备历史记录不存在
    LBLelinkFavoriteHistoryErrorCodeParameterNil = -12123,  // 传参出错
    LBLelinkFavoriteHistoryErrorCodeReponseError = -12124,  // 数据异常
    LBLelinkFavoriteHistoryErrorCodeNetworkConnectionFail = -12125, // 无效网络或网络连接错误
    LBLelinkFavoriteHistoryErrorCodeGeneralNotOpen = -12126,  // 该功能未开通
    LBLelinkFavoriteHistoryErrorCodeActionUnsupport = -12127,  /**< 不支持收藏 */
    LBLelinkFavoriteHistoryErrorCodeNotConnected = -12128, /**< 设备未连接 */
    LBLelinkFavoriteHistoryErrorCodeRefused = -12129, /**< 接收端拒绝被收藏 */
    LBLelinkFavoriteHistoryErrorCodeServiceVersionLow = -12130, /**< 接收端版本过低 */
    LBLelinkFavoriteHistoryErrorCodeServiceTypeNotLelink = -12131, /**< 非乐播接收端 */
    LBLelinkFavoriteHistoryErrorCodeThisFunctionIsNotLeboAPP = -12132, /**< 非乐播APP */
    LBLelinkFavoriteHistoryErrorCodeSimplifyIsOpen = -12133,          /**< simplify 模式打开*/
};

/** IM TCP 收发消息 相关的错误码*/
typedef NS_ENUM(NSInteger, LBLelinkIMMessageErrorCode) {
    /// 未知错误
    LBLelinkIMMessageErrorCodeUnknown = -100,
    /// 异常参数
    LBLelinkIMMessageErrorCodeExceptionParam = -101,
    /// 客户端请求格式错误
    LBLelinkIMMessageErrorCodeRequestFormat = 400,
    /// 客户端不在线
    LBLelinkIMMessageErrorCodeNotOnline = 404,
    /// 频率限制
    LBLelinkIMMessageErrorCodeFrequencyLimit = 410,
    /// 服务器内部错误
    LBLelinkIMMessageErrorCodeServerInternal = 65535,
};

