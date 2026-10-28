//
//  LBLelinkBrowser.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LBLelinkBase.h"

NS_ASSUME_NONNULL_BEGIN

@class LBLelinkBrowser;
@class LBLelinkService;

/**
 设备搜索协议
 */
@protocol LBLelinkBrowserDelegate <NSObject>

@required
/**
 某种权限被否认，APP层需引导用户去系统设置中打开
 LBLelinkSystemPermissionsTypeLocalNetwork本地网络权限被禁用时，将搜索不到任何设备，也无法连接局域网设备，需引导用户去设置中打开,强烈建议处理
 LBLelinkSystemPermissionsTypeMicrophone麦克风权限被禁止时，无法通过超声波搜索设备，超声波可搜索不在同一wifi下的近距离设备
 LBLelinkSystemPermissionsTypeBluetooth蓝牙权限被禁止时，无法通过BLE扫描设备，BLE可搜索不在同一wifi下的近距离设备
 
 @param browser 当前搜索工具
*/
- (void)lelinkBrowser:(LBLelinkBrowser *)browser permissionsPolicyDenied:(LBLelinkSystemPermissionsType)systemPermissionsType;

@optional

/**
 搜索错误代理回调
 内部采用多种搜索方式，当其中一种搜索方式出现error的时候，不会影响其它搜索方式
 @param browser 当前搜索工具
 @param error 错误信息
 */
- (void)lelinkBrowser:(LBLelinkBrowser *)browser onError:(NSError *_Nullable)error;

/**
 发现设备代理回调：一旦设备列表有变化就会回调
 
 @param browser 当前搜索工具
 @param services 设备列表
 */
- (void)lelinkBrowser:(LBLelinkBrowser *)browser didFindLelinkServices:(NSArray <LBLelinkService *> *_Nullable)services;

/**
 扫码发现设备回调

 @param browser 当前搜索工具
 @param lelinkService 扫码发现的设备
 */
- (void)lelinkBrowser:(LBLelinkBrowser *)browser didFindLelinkServiceFromQRCode:(LBLelinkService *)lelinkService;

/**
 某种方式发现一个设备回调
 例如：searchForLelinkServiceFormQRCode和searchForLelinkServiceFormTvUid方式获得的lelinkService

@param browser 当前搜索工具
@param lelinkService 发现的设备
@param sourceStyle 设备来源方式
*/
- (void)lelinkBrowser:(LBLelinkBrowser *)browser didFindLelinkService:(LBLelinkService *)lelinkService fromSourceStyle:(LBLelinkServiceSourceStyle)sourceStyle;

/**
 检查设备状态代理：设备状态发生变化会触发，
 
 只调用checkOnlineStatus时才回调，会回调多次
 */
- (void)lelinkBrowser:(LBLelinkBrowser *)browser onlineStatusChanged:(BOOL)changed;

/**
 本地网络权限被拒绝
 APP层需引导用户去系统设置中打开本地网络开关(受苹果接口限制，xcode12及更高版本打出的包运行无本地网络权限才会有此回调)
 无本地网络权限，将搜索不到任何设备，也无法连接局域网设备
 
 @param browser 当前搜索工具
*/
- (void)lelinkBrowserLocalNetworkPermissionsPolicyDenied:(LBLelinkBrowser *)browser;

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
 从二维码的字符串值中获取服务，必须子线程调用，会卡主线程

 @param QRCodeStringValue 二维码字符串值
 @param errPtr 错误
 @return 结果,YES：代表识别二维码成功，服务将在代理方法中回调出来；NO：代表获取失败
 */
- (BOOL)searchForLelinkServiceFormQRCode:(NSString *)QRCodeStringValue onError:(NSError **)errPtr;

/**I
 从投屏码中获取服务
 服务在代理方法中-lelinkBrowser:(LBLelinkBrowser *)browser didFindLelinkService:(LBLelinkService *)lelinkService fromSourceStyle:(LBLelinkServiceSourceStyle)sourceStyle 回调出来，sourceStyle == LBLelinkServiceSourceStyleInputCastCode时

 @param castCode 接收端乐播投屏码
 @param callBlock succeed:YES：解析成功，会在代理方法回调 NO：代表获取失败，不会在代理方法回调，originalInfo：请求的原始数据
*/
- (void)searchForLelinkServiceFormCastCode:(NSString *)castCode callBlock:(void(^)(BOOL succeed ,NSError * _Nullable error, NSDictionary *originalData))callBlock;

/**I
 从tvuid的值中获取服务
 服务在代理方法中-lelinkBrowser:(LBLelinkBrowser *)browser didFindLelinkService:(LBLelinkService *)lelinkService fromSourceStyle:(LBLelinkServiceSourceStyle)sourceStyle 回调出来，sourceStyle == LBLelinkServiceSourceStyleTvUidAndAppIdMatch时

 @param tvUid 接收端唯一id
 @param appid 接收端渠道
 @param callBlock succeed:YES：解析成功，会在代理方法回调 NO：代表获取失败，不会在代理方法回调
*/
- (void)searchForLelinkServiceFormTvUid:(NSString *)tvUid tvAppid:(NSString *)appid callBlock:(void(^)(BOOL succeed ,NSError * _Nullable error))callBlock;

/**
 从tvDsn的值中获取服务
 同上
 @param tvDsn 接收端设备号
 @param appid 接收端渠道
 @param callBlock succeed:YES：解析成功，会在代理方法回调 NO：代表获取失败，不会在代理方法回调
*/
- (void)searchForLelinkServiceFormTvDsn:(NSString *)tvDsn tvAppid:(NSString *)appid callBlock:(void(^)(BOOL succeed ,NSError * _Nullable error))callBlock;

/**
 从tvDsn的值中获取服务
 1）服务在代理方法中 -lelinkBrowser:(LBLelinkBrowser *)browser didFindLelinkService:(LBLelinkService *)lelinkService fromSourceStyle:(LBLelinkServiceSourceStyle)sourceStyle  回调出来，sourceStyle == LBLelinkServiceSourceStylePhoneMatch时
 2）使用脱敏方法，需使用LBLelinkKit类所提供的 +desensitizationString:(NSString *)string 方法或者规则
 
 @param desensitization 脱敏字符串
 @param callBlock succeed:YES：解析成功，会在代理方法回调 NO：1）网络异常情况，不会在代理方法回调，2）查询数据为空情况，不会在代理方法回调
*/
- (void)searchForLelinkServiceFormPhone:(NSString *)desensitization callBlock:(void(^)(BOOL succeed ,NSError * _Nullable error))callBlock;

/*
 该接口废弃，请使用 -enableSearchLelinkService:sourceStyle:onError: 方法
 禁止搜索服务方式
 @param serviceSourceStyle 服务来源方式
 @param errPtr 错误
 @return 结果,YES：设置成功，NO：设置失败
 */
//- (BOOL)disableSearchLelinkServiceStyle:(LBLelinkServiceSourceStyle)serviceSourceStyle onError:(NSError **)errPtr;

/*
 启用/关闭 服务搜索方式
 
 现仅支持LBLelinkServiceSourceStyleSearchBluetooth方式
 关闭LBLelinkServiceSourceStyleSearchBluetooth，在开始搜索时，将不会蓝牙扫描，不会触发蓝牙权限申请，无法通过BLE扫描设备，BLE可搜索不在同一wifi下的近距离设备
 默认关闭 LBLelinkServiceSourceStyleSearchBluetooth 搜索
 需要在调用searchForLelinkService前设置有效
 
 @param enable 启用/关闭
 @param serviceSourceStyle 服务来源方式
 @param error 错误
 @return 结果,YES：设置成功，NO：设置失败
 */
- (BOOL)enableSearchLelinkService:(BOOL)enable sourceStyle:(LBLelinkServiceSourceStyle)serviceSourceStyle onError:(NSError *)error;
/*
 暂停搜索服务方式
 现仅支持暂停LBLelinkServiceSourceStyleSearchBluetooth方式
 暂停LBLelinkServiceSourceStyleSearchBluetooth，在搜索过程中，暂停蓝牙扫描
 需在调用enableSearchLelinkService:sourceStyle:onError:前设置有效
 @param serviceSourceStyle 服务来源方式
 @param errPtr 错误
 @return 结果,YES：设置成功，NO：设置失败
 */
- (BOOL)pauseSearchLelinkServiceStyle:(LBLelinkServiceSourceStyle)serviceSourceStyle onError:(NSError **)errPtr;
/*
 继续搜索服务方式
 现仅支持继续LBLelinkServiceSourceStyleSearchBluetooth方式
 继续LBLelinkServiceSourceStyleSearchBluetooth，在搜索过程中，继续蓝牙扫描
 需在调用enableSearchLelinkService:sourceStyle:onError:前设置有效
 @param serviceSourceStyle 服务来源方式
 @param errPtr 错误
 @return 结果,YES：设置成功，NO：设置失败
 */
- (BOOL)continueSearchLelinkServiceStyle:(LBLelinkServiceSourceStyle)serviceSourceStyle onError:(NSError **)errPtr;
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

/**
 保存设备列表
 */
- (BOOL)saveServices:(NSArray <LBLelinkService *>*_Nonnull)lelinkServices;

/**
上次保存的设备
*/
- (NSArray <LBLelinkService *>*)lastServices;

/**
 检测设备在线状态
 */
- (void)checkOnlineStatus:(NSArray <LBLelinkService *>*)services;

@end

NS_ASSUME_NONNULL_END
