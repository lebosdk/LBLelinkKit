//
//  LBService.h
//  LBService
//
//  Created by Mingxing Liu on 2021/10/11.
//

#import <Foundation/Foundation.h>
@class LBLelinkService;
typedef void(^LBServerDevsResultCallback)(BOOL isSuccess ,NSArray <LBLelinkService *>* _Nullable result, NSError * _Nullable error);
typedef void(^LBServerDevsCallback)(BOOL isSuccess , NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface LBLelinkServiceCategroy : NSObject

#pragma mark 收藏设备

/**
 描述：设置收藏关系ID
   1.设置该devsId后，才能使用收藏功能
   2.设置的devsId进行收藏设备管理，作为唯一标识
 
 @param devsId 收藏设备的唯一标识ID
 */
+ (void)setFavoriteId:(NSString *)devsId;

/**
 描述: 是否支持收藏
   1. 需设置唯一标识，调+setFavoriteId:方法
 @param server 需收藏的设备信息
 @param error 错误
 @return 结果,YES：支持，NO：不支持
 */
+ (BOOL)canFavoriteServer:(LBLelinkService *)server
                  onError:(NSError **)error;

/**
 描述: 添加收藏设备
   1. 需设置唯一标识，调+setFavoriteId:方法
 @param server 需收藏的设备信息
 @param callBlock 返回结果
 */
+ (void)setFavoriteServer:(LBLelinkService *)server
                callBlock:(LBServerDevsCallback)callBlock;

/**
 描述: 删除收藏关系

 @param servers 需收藏的设备信息组,支持单和多个删除
 @param callBlock 返回结果
 */
+ (void)deleteFavoriteServers:(NSArray <LBLelinkService*> *)servers
                    callBlock:(LBServerDevsCallback)callBlock;


/**
 描述: 获取收藏设备
    
 @param online 在线状态, 1:返回在线设备, 传空:返回全部设备(包含不在线设备和在线设备)，默认返回全部设备
 @param state  联网状态, 1:返回局域网设备, 传空:返回全网设备(包含局域网设备和公网设备)，默认返回全部设备
 @param callBlock 返回结果
 */
+ (void)getFavoriteDevsWithOnline:(NSString *)online
                   ConnectedState:(NSString *)state
                        callBlock:(LBServerDevsResultCallback)callBlock;


/**
 描述: 设置/清除收藏设备别名
 
 @param server 设置别名的设备
 @param name 别名，当name传空的时候，则清除别名
 */
+ (void)setFavoriteAliasServer:(LBLelinkService *)server
                     aliasName:(NSString *)name
                     callBlock:(LBServerDevsCallback)callBlock;


/**
 描述: 基于APPID+UID查询设备信息
   1.提供外面APP调用，传入参数直接查询
 
 @param servers 需查询的设备ID组
 @param callBlock 返回结果
 */
+ (void)getFavoriteServerWithApIdAndUid:(NSArray <LBLelinkService *>*)servers
                              callBlock:(LBServerDevsResultCallback)callBlock;

#pragma mark 保存历史记录

/**
 描述: 开启保存历史设备开关
    1.打开开关，投屏成功后自动保存设备记录到云端
    2.历史投屏设备按上次投屏时间，最多保存最新的10个设备（去重）
 
 @param isOn YES：打开，NO：关闭; 默认 NO
 */
+ (void)setHistoryDevSwitch:(BOOL)isOn;

/**
 描述: 查询历史投屏设备
 
 @param online 在线状态, 1:在线, 传空:全部，默认返回全部
 @param state  联网状态, 1:返回局域网设备, 传空:返回全网设备(包含局域网设备和公网设备)，默认返回全部设备
 @param callBlock 返回结果
 */
+ (void)getHistoryServiceWithOnline:(NSString *)online
                     ConnectedState:(NSString *)state
                          callBlock:(LBServerDevsResultCallback)callBlock;

/**
 描述: 删除历史投屏设备
 
 @param server 需删除的设备组
 @param type 删除类型；type: 1:全部删除 2:部分删除
 @param callBlock 返回结果
 */
+ (void)deleteHistoryServices:(NSArray <LBLelinkService*> *)server
                       deType:(NSString *)type
                    callBlock:(LBServerDevsCallback)callBlock;

#pragma mark - - - 连接设备关系 (以下方法仅供乐播内部使用)

/**
 描述：添加连接设备记录
 
 @param server 连接的设备信息
 @param callBlock 返回结果
 */
+ (void)setConnectionServer:(LBLelinkService *)server
                  callBlock:(LBServerDevsCallback)callBlock;

/// 添加连接设备记录
/// @param server 连接的设备信心
/// @param otherParam 附加信息
/// @param callBlock 返回结果
+ (void)setConnectionServer:(LBLelinkService *)server otherParam:(NSDictionary *_Nullable)otherParam callBlock:(LBServerDevsCallback)callBlock;

/**
 描述: 获取用户连接设备记录
    
 @param online 在线状态, 1:返回在线设备, 传空:返回全部设备(包含不在线设备和在线设备)，默认返回全部设备
 @param state  连接网络的类型, 1:返回局域网设备, 传空:返回全网设备(包含局域网设备和公网设备)，默认返回全部设备
 @param otherParam 附加参数
 @param callBlock 返回结果
 */
+ (void)getConnectionDevsWithOnline:(NSString *_Nullable)online
                     connectedState:(NSString *_Nullable)state otherParam:(NSDictionary *_Nullable)otherParam callBlock:(LBServerDevsResultCallback)callBlock;

/**
 描述: 删除连接设备记录

 @param servers 需收藏的设备信息组,支持单和多个删除
 @param callBlock 返回结果
 */
+ (void)deleteConnectionServers:(NSArray <LBLelinkService*> *)servers
                      callBlock:(LBServerDevsCallback)callBlock;

/**
 描述: 设置连接列表的设备别名
 
 @param server 设置别名的设备
 @param name 别名，当name传空的时候，则清除别名
 */
+ (void)setConnectionAliasServer:(LBLelinkService *)server
                       aliasName:(NSString *)name
                       callBlock:(LBServerDevsCallback)callBlock;
@end

NS_ASSUME_NONNULL_END
