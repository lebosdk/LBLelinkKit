//
//  LBLelinkKit.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <LBLelinkKit/LBLelinkBrowser.h>
#import <LBLelinkKit/LBLelinkService.h>
#import <LBLelinkKit/LBLelinkConnection.h>
#import <LBLelinkKit/LBLelinkPlayer.h>
#import <LBLelinkKit/LBLelinkPlayerItem.h>
#import <LBLelinkKit/LBLelinkError.h>
#import <LBLelinkKit/LBLelinkBase.h>
#import <LBLelinkKit/LBLelinkCast.h>
#import <LBLelinkKit/LBADInterface.h>
#import <LBLelinkKit/LBADInfo.h>
#import <LBLelinkKit/LBLelinkTextBarrage.h>

NS_ASSUME_NONNULL_BEGIN

@interface LBLelinkKit : NSObject

/**
 是否打开log

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
+ (void)clearUserID;

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

@end

NS_ASSUME_NONNULL_END
