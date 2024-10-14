//
//  LBLelinkConnection.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LBLelinkBase.h"
NS_ASSUME_NONNULL_BEGIN

@class LBLelinkConnection;
@class LBLelinkService;
@class LBADInfo;
@class LBDecodabilityModel;
@class LBRetryConnectManager;

/// IM消息的命令字
typedef NS_ENUM(NSInteger,LBIMOperationType) {
    /// 25、订阅设备状态请求(客户端->服务器)
    LBIMOperationTypeSubsDeviceStatusSen    = 25,
    /// 26、订阅设备状态响应(服务器->客户端)
    LBIMOperationTypeSubsDeviceStatusRec    = 26,
    /// 27、查询订阅列表请求(客户端->服务器)
    LBIMOperationTypeQuerySubsListSen       = 27,
    /// 28、查询订阅列表响应(服务器->客户端)
    LBIMOperationTypeQuerySubsListRec       = 28,
    /// 29、服务器推送事件消息(服务器->客户端)
    LBIMOperationTypeEventNotifRec          = 29,
};

typedef NS_ENUM(NSInteger,LBMicroAppType) {
    LBMicroAppTypeApk = 0,
    LBMicroAppTypeWeex= 1,
};
typedef NS_ENUM(NSInteger,LBPlayerControlType) {
    LBPlayerControlTypeSwitch = 0, /// 播放器切换
    LBPlayerControlTypeModel = 1, /// 视频播放模式
    LBPlayerControlTypeRotating = 2, /// 角度旋转
};
typedef NS_ENUM(NSInteger, LBServerNorMsgType) {
    LBServerNorMsgTypeUnknown = 0, /**< 未知类型 */
    LBServerNorMsgTypeTVLoginSucceed = 1, /**< 扫码授权登录成功 */
    LBServerNorMsgTypePaymentSucceed = 2, /**< 付费成功 */
    LBServerNorMsgTypeLogoutReason = 3, /**< 登录退出，账号绑定了其它设备 */
    LBServerNorMsgTypeAuthSqueezedOut = 4, /**< 临时授权被挤掉 */
    LBServerNorMsgTypeFaceRecognition = 100, /**< 接收端需要人脸识别 */
};
@protocol LBLelinkWRMeetingDelegate <NSObject>
/** 收到水兔透传信息
@param connection 当前
@param dict 透传的信息
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection waterRabbitMessageWithDict:(NSDictionary*)dict;
/**服务器传递给app指令信息
@param connection 当前
@param action 消息方法
@param body 消息体,可能是NSDictionary或 NSString
*/
- (void)lelinkConnection:(LBLelinkConnection *)connection serverPassAppDataWithAction:(NSString *)action body:(id)body;

/**
 返回发送端是否具有云镜像/云桌面功能
 @param connection 当前连接
 @param bodyDic 返回数据 是否支持云镜像/云桌面功能，isSupported：1:支持（默认值）；0:不支持
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection passthReceiverCloudFunctionReply:(NSDictionary *_Nullable)bodyDic;

/**
 自定义的业务错误代理回调
 比如：查询当前设备是否在会议中时，403（TV离线）错误时的回调

 @param connection 当前连接
 @param error 错误信息
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection onBusinessError:(NSError *)error;
@end

@protocol LBLelinkCMirrorDelegate <NSObject>

- (void)lelinkConnection:(LBLelinkConnection *)connection mirrorStatus:(NSInteger)playStatus reason:(NSInteger)reason;

@end

@protocol LBLelinkConnectionDelegate <NSObject>


@optional

/**
 连接出错代理回调

 @param connection 当前连接
 @param error 错误信息
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection onError:(NSError *)error;

/**
 连接成功代理回调

 @param connection 当前连接
 @param service 当前连接的服务
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection didConnectToService:(LBLelinkService *)service;

/**
 连接断开代理回调

 @param connection 当前连接
 @param service 当前服务
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection disConnectToService:(LBLelinkService *)service;

/// 开始重连
/// @param connection 当前连接
- (void)lelinkConnectionDidStartRetryConnect:(LBLelinkConnection *)connection;

/// 重连成功
/// @param connection 当前连接
- (void)lelinkConnectionRetryConnectSuccessfully:(LBLelinkConnection *)connection;

/// 重连失败
/// @param connection 当前连接
/// @param error 重连失败错误信息
- (void)lelinkConnection:(LBLelinkConnection *)connection retryConnectFailed:(NSError *_Nullable)error;

/// 重连结束
/// @param connection 当前连接
- (void)lelinkConnectionRetryConnectFinished:(LBLelinkConnection *)connection;


/// IM 重连
/// @param connection connection
/// @param service 连接服务
/// @param reconnectCount 重连次数，会重试 60 次，超过 60 次连接不成功不再继续重连
- (void)lelinkConnection:(LBLelinkConnection *)connection reconnectToService:(LBLelinkService *)service reconnectCount:(NSInteger)reconnectCount;

/// 防骚扰超时时长
/// @param connection 当前连接
/// @param time 超时时长
- (void)lelinkConnection:(LBLelinkConnection *)connection harassTime:(NSInteger)time DEPRECATED_MSG_ATTRIBUTE("use  lelinkConnection:harassTime:harassType:pictures:");

/// 防骚扰确认消息
/// @param connection 当前连接
/// @param time 超时时长
/// @param harassType 防骚扰确认类型 备注：图片防骚扰目前只支持乐播APP
/// @param pictures 图片数据
- (void)lelinkConnection:(LBLelinkConnection *)connection harassTime:(NSInteger)time harassType:(LBLelinkHarassType)harassType pictures:(NSArray<LBHarassPictureInfo *> *_Nullable)pictures;

/**
 收到互动广告信息

 @param connection 当前
 @param adInfo 广告信息
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection didReceiveAdInfo:(LBADInfo *)adInfo;

/**
 收到支持的解码器信息

 @param connection 当前
 @param decoderArray 解码器列表
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection decoderList:(NSArray <LBDecodabilityModel *>*)decoderArray;

/**
权益查询同步信息

@param connection 当前
@param rightsDict 权益字典
@param error 权益查询错误，比如接收端不支持权益查询
*/
- (void)lelinkConnection:(LBLelinkConnection *)connection rightsSynchronous:(NSDictionary *_Nullable)rightsDict error:(NSError *_Nullable)error;

/**透传连接指令信息
 @param connection 当前
 @param infoDict 透传连接接收端信息字典
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection passthConnectInfoDict:(NSDictionary *_Nullable)infoDict;


/**服务器传递给app指令信息
@param connection 当前
@param action 消息方法
@param body 消息体,可能是NSDictionary或 NSString
*/
- (void)lelinkConnection:(LBLelinkConnection *)connection serverPassAppDataWithAction:(NSString *)action body:(id)body;


/**收到镜像暂停/继续透传指令
@param connection 当前
@param mirrorActionType 镜像行动类型
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection passthMirrorActionType:(LBPassthMirrorActionType)mirrorActionType;


/**收到可反控指令信息
@param connection 当前
@param bodyDic 反控信息
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection passthEventReverseControlBodyDic:(NSDictionary *)bodyDic;

/**收到遥控器事件信息
@param connection 当前
@param bodyDic 事件信息，键值信息参考 https://doc.hpplay.com.cn/web/#/20?page_id=303
 
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection passthRemoteControlEventDic:(NSDictionary *)bodyDic;

/** 收到微应用透传信息
@param connection 当前
@param dict 透传的信息
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection microAppMessageWithDict:(NSDictionary*)dict;

/** 收到微应用关闭信息
@param connection 当前
@param type  应用类型
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection microAppCloseWithType:(LBMicroAppType)type;

/// 服务器普通消息通知
/// @param connection 当前
/// @param norMsgType 消息类型
/// @param message 信息
/*
 {

  "uuid":13658 //用户账号，注意如果uuid不为空，终端要判断一下uuid是否与当前登录的账号一致，不一致就忽略这条消息
  "type": 1      //消息含义 ：1 TV端二维码登录成功， 2 付费成功通知，  3 登录退出，账号绑定了其它设备，4 临时授权被挤掉
  "content"："test"   //消息内容
 }
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection serverPassthNormalMessageType:(LBServerNorMsgType)norMsgType message:(NSDictionary *_Nullable)message;

/**
 返回查询到播放器的设置端口数据
 调用[-passthCheckReceiverSetParma]查询播放器端口设置
 @param connection 当前连接
 @param mediaObject 媒体对象，item或itemArray
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection passthReceiverSetReply:(NSDictionary *_Nullable)mediaObject;

/**
 返回发送端是否具有云镜像/云桌面功能
 @param connection 当前连接
 @param bodyDic 返回数据 是否支持云镜像/云桌面功能，isSupported：1:支持（默认值）；0:不支持（此时正在加载资源包）
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection passthReceiverCloudFunctionReply:(NSDictionary *_Nullable)bodyDic;

/**
 连接的收端通知发端上传日志
 @param connection 当前连接
 @param bodyDic 附带参数，eid:双端日志关联id，et:问题类型
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection passthUploadLogFileBodyDic:(NSDictionary *)bodyDic;

/// 云应用cookie信息
/// @param connection 当前连接
/// @param bodyDict cookie信息内容
- (void)lelinkConnection:(LBLelinkConnection *)connection passthCloudAppCookieBodyDic:(NSDictionary *)bodyDict;

/// 透传通用方法
/// @param connection 当前连接
/// @param manifestType 透传消息号
/// 例如manifestType == 57: 透传发送端推送播放器错误信息,bodyDic为错误信息,错误的类型说明https://doc.hpplay.com.cn/web/#/p/24056a1888f3338e504fb1010656c800
/// @param bodyDic 消息体
/// @param headDic 消息头
- (void)lelinkConnection:(LBLelinkConnection *)connection passthPublicManifestType:(NSInteger)manifestType bodyDic:(NSDictionary *)bodyDic headDic:(NSDictionary *)headDic;
@end




@interface LBLelinkConnection : NSObject

/** 用于连接的服务 */
@property (nonatomic, strong) LBLelinkService *lelinkService;
/** 连接代理 */
@property (nonatomic, weak) id<LBLelinkConnectionDelegate> delegate;
@property (nonatomic, weak) id<LBLelinkWRMeetingDelegate> meetingDelegate;
@property (nonatomic, weak) id<LBLelinkCMirrorDelegate> mirrorDelegate;
/** 连接状态，YES代表已连接，NO代表未连接 */
@property (nonatomic, assign, getter=isConnected, readonly) BOOL connected;
/// 当前连接的镜像能力，0代表支持镜像，-1代表不支持镜像；默认为0
@property (nonatomic, assign) NSInteger mirrorAbility;
/// 打开图形验证码防骚扰开关,默认为关。
// 打开，防骚扰类型 可能 为 LBLelinkHarassTypePicture；关闭 防骚扰类型则为 LBLelinkHarassTypeRemoteControl
@property (nonatomic, assign) BOOL openPictureAntiHarass;
// 打开镜像无缝切换水兔能力，默认NO关闭，修改在下次连接后生效
@property (nonatomic, assign) BOOL openMirrorSwitchSpace;
/// 重连管理对象
@property (nonatomic, strong, readonly) LBRetryConnectManager *retryConnectManager;

/**
 初始化方法，使用此方法初始化之后，需要设置连接代理属性以及用于连接的服务

 @return 连接实例对象
 */
- (instancetype)init;

/**
 万能初始化方法

 @param lelinkService 用于连接的服务
 @param delegate 连接代理
 @return 连接实例对象
 */
- (instancetype)initWithLelinkService:(LBLelinkService * _Nullable)lelinkService delegate:(id<LBLelinkConnectionDelegate> _Nullable)delegate;

/**
 连接，如果已经设置了用于连接的服务，则可直接调用此方法进行连接
 */
- (void)connect;

/**
 连接，如果没有设置用于连接的服务，可用此方法进行连接

 @param lelinkService 用于连接的服务
 */
- (void)connectToLelinkService:(LBLelinkService *)lelinkService;

/**
 断开当前的连接
 */
- (void)disConnect;

- (void)sendCloudMirroRoomId:(NSString *)roomId type:(NSString *)type;

/**
设置sid，// 乐播投屏APP 使用接口
*/
- (void)setSid:(NSString *)sid;

/**
 是否支持权益查询
*/
- (BOOL)canPassthRightsQuery;

/**
 是否支持透传App新权益
*/
- (BOOL)canPassthAppNewRightsQuery;
/**
 权益查询
*/
- (void)passthRightsQuery;

- (BOOL)canPassthJournalFile;

- (void)passthJournalFileWithEid:(NSString *)eid euqid:(NSString *)euqid et:(NSString *)et;

- (BOOL)canPassthPerformedMirrorAction;

- (void)passthPerformedMirrorActionType:(LBPassthMirrorActionType)mirrorActionType;

/// 能否支持反控
- (BOOL)canPassthEventReverseControl;

/// 透传通知接收端开启反控服务,收到- (void)lelinkConnection:(LBLelinkConnection *)connection passthEventReverseControlBodyDic:回调，可开始准备反控
- (void)passthEventReverseControl;

- (BOOL)canPassthRemoteControlEvent;
- (void)passthListenRemoteControlSwitch:(BOOL)open;

- (BOOL)canPushVideoList;

/// 启动多通道连接，连接之前设置生效
/// @param enable 启动与否，默认不启用
- (void)enableMultiTunnels:(BOOL)enable;

/// 是否支持水兔
- (BOOL)canWaterRabbit;
/// 是否支持投屏空间
- (BOOL)canCastSpace;

- (BOOL)canPassthPluginInfo;

/// 微应用插件信息推送
/// @param appId 应用ID
/// @param type 应用类型
/// @param pluginUrl 插件下载地址
/// @param proof 插件下载地址校验信息
/// @param loginInfo 登录信息
- (void)passthPluginAppId:(NSString *)appId
                     type:(LBMicroAppType)type
                pluginUrl:(NSString *)pluginUrl
                    proof:(NSString*)proof
                loginInfo:(NSString *)loginInfo ;

- (BOOL)canPassthMessageInfo;

/// 微应用透传信息
/// @param appId 应用appid
/// @param type 插件类型
/// @param content 消息内容
- (void)passthMessageInfoWithAppId:(NSString *)appId
                              type:(LBMicroAppType)type
                           content:(NSString *)content ;

- (BOOL)canPassthCloseMicroApp;

/// 关闭微应用
/// @param type 插件类型
- (void)passthCloseMicroAppWithType:(LBMicroAppType)type;

/// 水兔透传专用
- (void)passthWaterRabbitDataDic:(NSDictionary *)dataDic tvUid:(NSString *)tvUid;
/// 获取连接的服务类型
- (LBLelinkServiceType)getConnectedServiceType;

/// 获取连接的协议类型
- (LBLelinkProtocolType)getConnectedProtocolType;

/// 是否支持切换播放器模式
- (BOOL)canPassthChangePlayerMode;
/**
 播放器切换模式的类型
 @param type 切换播放器的模式
 @param commands 切换播放器的类型;例如:[@"1"]
 type为LBPlayerControlTypeSwitch时，commands取值范围:[0:自动选择；1:系统播放器；2:乐播软解播放器；3:乐播硬解播放器];
 type为LBPlayerControlTypeModel时，commands取值范围:[0:自动选择;1:标准模式;2:兼容模式];
 type为LBPlayerControlTypeRotating时，commands取值范围:[0: 关闭;1:开启];
 
 */
- (void)passthChangePlayerCommandWithContorType:(LBPlayerControlType)type contorCommands:(NSArray <NSString *>*)commands;
/// 是否支持查询播放器的设置
- (BOOL)canPassthCheckReceiverSetParma;
/**
 查询播放器所设置的参数
 通过LBLelinkConnectionDelegate代理[- (void)lelinkConnection: passthReceiverSetReply:]方法，拿到查询接口的数据;
 */
- (void)passthCheckReceiverSetParma;

/// 通知接收端验证防骚扰图片
/// - Parameter pictureInfo: 图片信息
- (void)harassVerificateWithPicture:(LBHarassPictureInfo *_Nullable)pictureInfo;

/// 通知接收端取消防骚扰验证
- (void)cancelHarassComfirm;

/// 二次确认连接（目前只供乐播APP使用）
- (void)confirmConnect;

/// 透传给云应用cookie数据
/// - Parameters:
///   - uid: 云应用uid
///   - rtcUid: 本机trcuid
///   - domain: 域名
///   - cookieBodyDic: cookieBodyDic (json字符串)
- (void)passthCloudAppCookieUid:(NSString *)uid rtcUid:(NSString *)rtcUid domain:(NSString *)domain cookieBodyDic:(NSString *_Nullable)cookieBodyDic;

/// 能否透传接收端播放错误信息
- (BOOL)canPassthReceiverPlayerErrorInfo;

/// 将消息透传到接收端---无需连接接收端
/// - Parameters:
///   - tvuid: 收端uid
///   - passthInfo: 透传信息，需要双端约定好
- (void)passthLeboInfoToTVUid:(NSString *_Nullable)tvuid passthInfo:(NSDictionary *_Nullable)passthInfo;

#pragma mark - 通过 IM TCP 通道，进行消息发送

/// 发送带指令的IM消息（符合29号事件通知的消息回调，例如 1:连接状态事件,2:群组创建 3:群组成员加入 4:群组成员离开 5:群组结束 通用方法）
/// - Parameters:
///   - operation: 指令
///   - bodyData:  包体
///   - callback:  IM消息回调（29号事件通知消息）
- (void)sendIMFor29EventWithOperation:(NSInteger)operation andBody:(id)bodyData withCallback:(void(^_Nullable)(NSInteger operation, NSDictionary *_Nullable messageDict, NSError *_Nullable error))callback;

/// 发送订阅设备状态
/// - Parameters:
///   - infoList: 例如[{"uid": "2000", "appid":14}]，tv的uid，tv的appid
///   - callback: 设备状态变化的IM消息回调
- (void)sendIMForSubscribeDeviceStatusWithList:(NSArray *)infoList withCallback:(void(^_Nullable)(NSInteger operation, NSDictionary *_Nullable messageDict, NSError *_Nullable error))callback;

/// 取消订阅设备状态
/// - Parameters:
///   - callback: IM消息回调
- (void)sendIMForCancelSubscribeDeviceStatusWithCallback:(void(^_Nullable)(NSInteger operation, NSDictionary *_Nullable messageDict, NSError *_Nullable error))callback;

#pragma mark -

@end
NS_ASSUME_NONNULL_END
