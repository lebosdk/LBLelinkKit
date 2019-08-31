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

/**
 收到互动广告信息

 @param connection 当前
 @param adInfo 广告信息
 */
- (void)lelinkConnection:(LBLelinkConnection *)connection didReceiveAdInfo:(LBADInfo *)adInfo;

@end




@interface LBLelinkConnection : NSObject

/** 用于连接的服务 */
@property (nonatomic, strong) LBLelinkService *lelinkService;
/** 连接代理 */
@property (nonatomic, weak) id<LBLelinkConnectionDelegate> delegate;
/** 连接状态，YES代表已连接，NO代表未连接 */
@property (nonatomic, assign, getter=isConnected, readonly) BOOL connected;

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

@end
NS_ASSUME_NONNULL_END
