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

typedef NS_ENUM(NSInteger,LBMicroAppType) {
    LBMicroAppTypeApk = 0,
    LBMicroAppTypeWeex= 1,
};
typedef NS_ENUM(NSInteger,LBPlayerControlType) {
    LBPlayerControlTypeSwitch = 0, /// 播放器切换
    LBPlayerControlTypeModel = 1, /// 视频播放模式
    LBPlayerControlTypeRotating = 2, /// 角度旋转
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

/// 防骚扰超时时长
/// @param connection 当前连接
/// @param time 超时时长
- (void)lelinkConnection:(LBLelinkConnection *)connection harassTime:(NSInteger)time;

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
/// @param userInfo 信息
/*
 {

  "uuid":13658 //用户账号，注意如果uuid不为空，终端要判断一下uuid是否与当前登录的账号一致，不一致就忽略这条消息
  "type": 1      //消息含义 ：1 TV端二维码登录成功， 2 付费成功通知，  3 登录退出，账号绑定了其它设备，4 临时授权被挤掉
  "content"："test"   //消息内容
 }
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection serverPassthNormalMessage:(NSDictionary *_Nullable)message;

/**
 返回查询到播放器的设置端口数据
 调用[-passthCheckReceiverSetParma]查询播放器端口设置
 @param connection 当前连接
 @param mediaObject 媒体对象，item或itemArray
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection passthReceiverSetReply:(NSDictionary *_Nullable)mediaObject;

@end




@interface LBLelinkConnection : NSObject

/** 用于连接的服务 */
@property (nonatomic, strong) LBLelinkService *lelinkService;
/** 连接代理 */
@property (nonatomic, weak) id<LBLelinkConnectionDelegate> delegate;
@property (nonatomic, weak) id<LBLelinkWRMeetingDelegate> meetingDelegate;
/** 连接状态，YES代表已连接，NO代表未连接 */
@property (nonatomic, assign, getter=isConnected, readonly) BOOL connected;
/// 当前连接的镜像能力，0代表支持镜像，-1代表不支持镜像；默认为0
@property (nonatomic, assign) NSInteger mirrorAbility;


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
- (BOOL)supportWaterRabbit;

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

@end
NS_ASSUME_NONNULL_END
