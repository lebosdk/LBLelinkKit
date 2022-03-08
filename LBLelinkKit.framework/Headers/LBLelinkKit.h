//
//  LBLelinkKit.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LBLelinkBrowser.h"
#import "LBLelinkService.h"
#import "LBLelinkConnection.h"
#import "LBLelinkPlayer.h"
#import "LBLelinkPlayerItem.h"
#import "LBLelinkError.h"
#import "LBLelinkBase.h"
#import "LBADInterface.h"
#import "LBADInfo.h"
#import "LBLelinkTextBarrage.h"
#import "LBLelinkReverseControl.h"

NS_ASSUME_NONNULL_BEGIN

@interface LBLelinkKit : NSObject

/**
 是否打开log，打印输出在控制台

 @param enable YES代表打开，NO代表关闭，默认为NO
 */
+ (void)enableLog:(BOOL)enable;

/**
 授权认证接口。
 注意：请在调试阶段确保SDK能正确的授权成功，否则，当连续出现100次授权请求失败，且没有任何一次授权成功过，则SDK功能搜索功能不再可用。
 
 @param appid 乐播开发者平台中注册的appID
 @param secretKey 乐播开发者平台中注册的密钥
 @param errPtr 错误信息，授权成功时为nil，授权失败时不为nil，可log出Error的信息以便调试
 @return 是否授权成功，YES：授权成功，NO：授权失败
 */
+ (BOOL)authWithAppid:( NSString * _Nonnull )appid secretKey:( NSString * _Nonnull )secretKey error:( NSError * _Nullable *)errPtr;


/**
 注册成为互动广告的监听者
 
 默认不是互动广告的监听者，需要调用此接口来注册成为互动广告的监听者，可以在投屏时监听到互动广告，通过LBLelinkConnectionDelegate的代理方法传出
 - (void)lelinkConnection:(LBLelinkConnection *)connection didReceiveAdInfo:(LBADInfo *)adInfo;
 */
+ (void)registerAsInteractiveAdObserver;

/**
 设置用户唯一标识，用于云端存取用户的远程设备信息
 非必要的设置，不设置，则不进行云端存取，仅本地存取
 在用户登录成功的时候可进行设置

 @param userID 用户的唯一标识
 */
+ (void)setUserID:(NSString *)userID;

/**
设置用户唯一标识，用于云端存取用户的远程设备信息
非必要的设置，不设置，则不进行云端存取，仅本地存取
在用户登录成功的时候可进行设置

@param userID 用户的唯一标识
@param token 用户登录的令牌
 */
+ (void)setUserID:(NSString *)userID token:(NSString *_Nullable)token;

/**
设置用户唯一标识，用于云端存取用户的远程设备信息
非必要的设置，不设置，则不进行云端存取，仅本地存取
在用户登录成功的时候可进行设置

@param userID 用户的唯一标识
@param token 用户登录的令牌
@param nickName 用户的昵称
 */
+ (void)setUserID:(NSString *)userID token:(NSString *)token nickName:(NSString *_Nullable)nickName;

/// 设置用户唯一标识，用于云端存取用户的远程设备信息
/// 非必要的设置，不设置，则不进行云端存取，仅本地存取
/// 在用户登录成功的时候可进行设置
/// @param userID 用户的唯一标识，对应的是 uuid
/// @param token 用户的令牌，    对应的是 token
/// @param nickName 用户的昵称, 对应的是 nickname
/// @param uid 用户的uid，      对应的是 uid
+ (void)setUserID:(NSString *_Nullable)userID token:(NSString *_Nullable)token nickName:(NSString *_Nullable)nickName uid:(NSString *_Nullable)uid;

/// 设置用户唯一标识，用于云端存取用户的远程设备信息或企业授权
/// 非必要的设置，不设置，则不进行云端存取，仅本地存取
/// 在用户登录成功的时候可进行设置
/// @param userID 用户的唯一标识，对应的是 uuid
/// @param token 用户的令牌，    对应的是 token
/// @param nickName 用户的昵称, 对应的是 nickname
/// @param uid 用户的uid，      对应的是 uid
/// @param ehid 用户的uid，    企业付费的设备id或license授权时租户提供设备id
+ (void)setUserID:(NSString *_Nullable)userID token:(NSString *_Nullable)token nickName:(NSString *_Nullable)nickName uid:(NSString *_Nullable)uid ehid:(NSString *_Nullable)ehid;

+ (void)clearUserID;


/// 设置appGroupId，用与扩展程序集成SDK共享使用
/// @param appGroupId appGroupId
+ (void)setAppGroupId:(NSString *)appGroupId;

+ (NSArray *)getinterestsArray:(NSError * _Nullable *)error;

/**
 设置搜索到设备时的本地通知
 本地通知发送的策略：
 1）APP在后台，搜索到新的设备
 2）同一局域网IP，在一天内仅发送一次通知

 @param enable YES->代表使用本地通知，NO->代表不是用本地通知，默认为YES
 @param title 本地通知的title文本，默认文本为“发现一台可以投屏的电视”
 @param body 本地通知的body文本，默认文本为“把你手机上的内容投到大屏电视上，快来试试！”
 */
+ (void)enableLocalNotification:(BOOL)enable alertTitle:(NSString *_Nullable)title alertBody:(NSString *)body;

/**
 是否打开log文件保存，保存在沙盒Caches文件夹,（最大10M日志）
 日志指定保存路径默认在/dailyLogFile 路径下
 
@param enable YES代表打开，NO代表关闭，默认为NO
*/
+ (void)enableLogFileSave:(BOOL)enable;

/**
 是否打开云镜像log文件保存，保存在沙盒
 1）若设置enableLogFileSave:方法设置YES，也同等打开
 2）若设置 1 的操作且不打印云日志，需调此方法设置NO，顺序在enableLogFileSave:后
 
 @param enable YES代表打开，NO代表关闭，默认为NO
 @param path   日志指定保存路径，不传默认在/dailyLogFile 路径下
 */
+ (void)enableCloudLogFileSave:(BOOL)enable cloudLogPath:(NSString *_Nullable)path;

/**
 log文件上传到乐播服务器

@param problemType 问题类型
@param contactInfo 用户联系信息
@param callBlock 上传成功与否回调
*/
+ (void)logFileUploadToLeBoServerWithProblemType:(LBLogReportProblemType)problemType userContactInfo:(NSString *)contactInfo callBlock:(void(^)(BOOL succeed ,NSString *_Nullable euqid,NSError * _Nullable error))callBlock;

/**
 上报关系数据
 
 1) 上报关系数据接口开关，打开此开关，需用户知情
 2) desensitization需传入脱敏手机号，且enable为YES才生效
 3) 传入脱敏的字符串可以调 +desensitizationString:(NSString *)string 方法所返回的参数
 
 @param phone  传入手机号(非必传)
 @param desensitization  脱敏手机号(必传)
 @param enable YES代表打开，NO代表关闭，默认为NO
 */
+ (void)enablePhoneReport:(NSString *)phone desensitization:(NSString *)desensitization  enable:(BOOL)enable;

/**
 脱敏规则
 
 字符串—>SHA256加密—>转成16进制字符串（64位字符串）—>转成大写—>去掉前两位及后两位（60位字符串）
 @param  string 需脱敏字符串
 @return 脱敏后的数据
 */
+ (NSString *)desensitizationString:(NSString *)string;


@end

NS_ASSUME_NONNULL_END
