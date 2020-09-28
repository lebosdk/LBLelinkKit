//
//  LBLelinkConnection.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class LBLelinkConnection;
@class LBLelinkService;
@class LBADInfo;
@class LBDecodabilityModel;

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
@end




@interface LBLelinkConnection : NSObject

/** 用于连接的服务 */
@property (nonatomic, strong) LBLelinkService *lelinkService;
/** 连接代理 */
@property (nonatomic, weak) id<LBLelinkConnectionDelegate> delegate;
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


@end
NS_ASSUME_NONNULL_END
