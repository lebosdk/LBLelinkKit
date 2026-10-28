//
//  LBLelinkService.h
//  AppleSenderSDK
//
//  Created by 刘明星 on 2018/4/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LBLelinkBase.h"

@class LEBUPnPDevice;
@class LBInnerLelinkDeviceModel;
@class LBIMServiceModel;
@class LBInnerFairplayDeviceModel;
//@class LBLelinkConnection;

@interface LBLelinkService : NSObject

/** 服务类型，即使用的服务协议支持乐联、DLNA、公网，以及三者的组合。注意，该字段使用者不用关心，仅仅SDK内部逻辑处理使用 */
@property (nonatomic, assign) LBLelinkServiceType serviceType;
/** 服务来源方式 */
@property (nonatomic, assign) LBLelinkServiceSourceStyle sourceStyle;
/**
 服务基本信息
 */
/** 服务名称，即搜索到的接收端的名称 */
@property (nonatomic, copy) NSString *lelinkServiceName;
/** 接收端的唯一标识，公网连接使用 */
@property (nonatomic, copy) NSString *tvUID;
/** 接收端的IP地址 */
@property (nonatomic, copy) NSString *ipAddress;
/** linux端口 */
@property (nonatomic, assign) NSInteger remotePort;
/** android端口 */
@property (nonatomic, assign) NSInteger port;
/** 乐联服务端口 */
@property (nonatomic, assign) NSInteger lelinkPort;


/** 接收端包名 TV端乐播投屏apk的包名为com.hpplay.happyplay.aw，可在设备列表中判断receviverPackageName是否等于此包名，UI上可以加上推荐二字，用户的投屏体验更好*/
@property (nonatomic, copy) NSString *receviverPackageName;
/** 接收端DLNA的uuid，注意此字段只针对特殊渠道有效，非通用字段 */
@property (nonatomic, copy) NSString *UDN;
/** 接收端是否有可升级的新版本 此属性是搜到TV端乐播投屏apk有新版可更新时，可提示用户升级接收端，体验更好*/
@property (nonatomic, assign) BOOL hasNewVersion;
/**（非必要的）别名，开发者可开放出来供用户修改服务名称的别名，方便用户自己识别和区分自己的服务 */
@property (nonatomic, copy) NSString *alias;
/**（非必要的）发送端登录的账号 */
@property (nonatomic, copy) NSString *vuuid;
/**（非必要的）是否为常用 */
@property (nonatomic, assign, readonly, getter=isFrequentlyUsed) BOOL frequentlyUsed;
/** (非必要的)曾经连接过的服务 */
@property (nonatomic, assign, readonly, getter=isOnceConnected) BOOL onceConnected;
/** (非必要的)上次连接过的服务 */
@property (nonatomic, assign, readonly, getter=isLastTimeConnected) BOOL lastTimeConnected;
/** 是否从二维码获得的设备 */
@property (nonatomic, assign, readonly, getter=isFromQRCode) BOOL fromQRCode;
/** 接收端的渠道id */
@property (nonatomic, copy) NSString *appID;
/** 接收端的mirrorReconnect,内部使用*/
@property (nonatomic, assign)NSInteger mirrorReconnect;
/// 镜像唯一标识，内部使用
@property (nonatomic, copy) NSString *mirrorUriId;
/**
 服务可用状态，该服务包含三种类型的服务：乐联服务、DLNA服务和公网服务
 */
/** 服务是否可用，三个服务中的任意一个可用，则isLelinkServiceAvailable为YES，否则为NO */
@property (nonatomic, assign, getter=isLelinkServiceAvailable,readonly) BOOL lelinkServiceAvailable;
/** 乐联服务是否可用 */
@property (nonatomic, assign, getter=isInnerLelinkServiceAvailable, readonly) BOOL innerLelinkServiceAvailable;
/** DLNA服务是否可用 */
@property (nonatomic, assign, getter=isUpnpServiceAvailable, readonly) BOOL upnpServiceAvailable;
/** 公网服务是否可用 */
@property (nonatomic, assign, getter=isImServiceAvailable, readonly) BOOL imServiceAvailable;

/**
 各类服务数据模型，可以结合服务可用状态判断当前的服务使用的何种投屏方式
 1、如果只有upnpDevice有值，则当前的接收端仅仅支持DLNA服务，非乐播的接收端的DLNA就属于此种情况
 
 2、如果只有imDevice有值，且isImServiceAvailable为YES，则当前服务使用公网投屏
 3、如果innerLelinkDevice和upnpDevice任意一个有值，则当前服务使用局域网投屏
 
 4、当多个服务有值时，服务使用的优先级，乐联 > DLNA > 公网
    1）都有值——>使用乐联
    2）乐联和DLNA都有值——>使用乐联
    3）乐联和公网都有值——>使用乐联
    4）DLNA和公网都有值——>使用DLNA
    5）注意此逻辑是SDK内部在使用服务建立连接和投屏时的选择逻辑，SDK使用者可忽略，感兴趣的可以了解一下
 */
/** 乐联服务数据模型 */
@property (nonatomic, strong) LBInnerLelinkDeviceModel *innerLelinkDevice;
/** DLNA服务数据模型 */
@property (nonatomic, strong) LEBUPnPDevice *upnpDevice;
/** 公网服务数据模型 */
@property (nonatomic, strong) LBIMServiceModel *imDevice;
/** fp服务数据模型 */
@property (nonatomic, strong) LBInnerFairplayDeviceModel *fairplayDevice;

@property (nonatomic, weak) id lelinkConnection;
@property (nonatomic, weak) id lelinkPlayer;

//lelink检测无效次数，0为有效
@property (nonatomic, assign, readonly) NSInteger leinkCheckCounter;
//dlna检测无效次数，0为有效
@property (nonatomic, assign, readonly) NSInteger dlnaCheckCounter;
//是否支持多通道切换
@property (nonatomic, assign, getter=isMultiTunnels, readonly) BOOL multiTunnels;
/// 是否支持企业版
@property (nonatomic, assign, getter=isSupportWr, readonly) BOOL supportWr;
/// 商用端的标记。 YES：是商用端；NO： 不是商用端
@property (nonatomic, assign, getter=isCommerceSource, readonly) BOOL commerceSource;

/** 原始名称 */
@property (nonatomic, copy) NSString *originalName;
/**
 比较两个LelinkService是否是同一个

 @param object 被比较的对象
 @return YES：代表相同，NO：代表不相同
 */
- (BOOL)isEqualToLelinkService:(LBLelinkService *)object;

/**
 model转NSDictionary
 */
- (NSDictionary *)dict;

/**
 NSDictionary转model
 */
+ (LBLelinkService *)lelinkServiceWithDict:(NSDictionary *)dict;

/**
 检查设备的在线状态
 */
- (void)checkOnlineStatus;

/**
 *  设置设备可用性
 */
- (void)setServiceAvailable:(int)serviceAvailable;

/**
 * 获取接收端渠道是否支持引流的字段 一个32位的无符号int值总共可以表示32个开关，目前开关固定从低位到高位开始
 *  1 的时候就知道目前接收端渠道引流 如：00000000 000000000 00000000 00000001
 */
- (NSString *)getserviceDrainage;

/// 获取乐联局域网模型
/// @param imService 传入公网模型
/// @param resultBlock 回调
- (void)getLelinkService:(LBLelinkService *)imService
             resultBlock:(void(^_Nullable)(LBLelinkService * _Nullable resultServer ,NSError * _Nullable error))resultBlock;

@end
