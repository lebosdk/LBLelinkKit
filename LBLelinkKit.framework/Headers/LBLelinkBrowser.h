//
//  LBLelinkBrowser.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LBLelinkBase.h"

@class LBLelinkBrowser;
@class LBLelinkService;

/**
 设备搜索协议
 */
@protocol LBLelinkBrowserDelegate <NSObject>

@optional

/**
 搜索错误代理回调

 @param browser 当前搜索工具
 @param error 错误信息
 */
- (void)lelinkBrowser:(LBLelinkBrowser *)browser onError:(NSError *)error;

/**
 发现设备代理回调：一旦设备列表有变化就会回调

 @param browser 当前搜索工具
 @param services 设备列表
 */
- (void)lelinkBrowser:(LBLelinkBrowser *)browser didFindLelinkServices:(NSArray <LBLelinkService *> *)services;

@end




/**
 设备搜索类
 */
@interface LBLelinkBrowser : NSObject

/** 搜索代理 */
@property (nonatomic, weak) id<LBLelinkBrowserDelegate> delegate;
/** 搜索到的设备列表 */
@property (nonatomic, strong, readonly) NSMutableArray *lelinkServices;

/**
 搜索服务
 */
- (void)searchForLelinkService;

/**
 该接口废弃，请使用 - (void)searchForLelinkService;
 根据需要的服务类型进行设备搜索

 @param type 服务类型
 */
- (void)searchForLelinkServiceOfType:(LBLelinkServiceType)type;

/**
 停止搜索，停止搜索后设备列表不会被清空，但是不会更新列表了
 */
- (void)stop;

/**
 从二维码的字符串值中获取服务

 @param QRCodeStringValue 二维码字符串值
 @param errPtr 错误
 @return 结果,YES：代表识别二维码成功，服务将在代理方法中回调出来；NO：代表获取失败
 */
- (BOOL)searchForLelinkServiceFormQRCode:(NSString *)QRCodeStringValue onError:(NSError **)errPtr;

#pragma mark - 服务管理，仅针对支持跨网投屏的服务有效

/**
 删除保存的服务，仅将用户连接过并被自动保存的服务，从保存的服务列表中删除掉，并不会将当前搜索到的局域网内的服务移除。

 @param lelinkService 被删除的服务
 */
- (void)deleteLelinkService:(LBLelinkService *)lelinkService;

/**
 该接口废弃
 将支持跨网连接的服务设置为是否常用服务

 @param lelinkService 支持跨网连接的服务
 @param isFrequentlyUsed 是否常用
 */
- (void)setLellinkService:(LBLelinkService *)lelinkService toFrequentlyUsed:(BOOL)isFrequentlyUsed;

/**
 更新支持跨网连接的服务信息，主要用于修改设备别名并保存更新

 @param lelinkService 服务
 @param completeBlock 完成回调，block中参数为YES时表示修改成功，否则修改失败
 */
- (void)updateLelinkService:(LBLelinkService *)lelinkService completeBlock:(void(^)(BOOL isSuccess))completeBlock;

/**
 更新支持跨网连接的服务信息，主要用于修改设备别名并保存更新
 
 @param lelinkService 服务
 */
- (void)updateLelinkService:(LBLelinkService *)lelinkService;


#pragma mark -
/**
 点击搜索设备时上报
 */
+ (void)reportAPPTVButtonAction;

/**
 设备列表消失
 */
- (void)reportServiceListDisappear;

@end



