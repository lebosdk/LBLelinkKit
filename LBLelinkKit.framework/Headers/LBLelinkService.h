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

@interface LBLelinkService : NSObject

/** 服务类型，即使用的服务协议支持乐联、DLNA、公网，以及三者的组合 */
@property (nonatomic, assign) LBLelinkServiceType serviceType;

/**
 服务基本信息
 */
/** 服务名称，即搜索到的接收端的名称 */
@property (nonatomic, copy) NSString *lelinkServiceName;
/** 接收端的唯一标识，公网连接使用 */
@property (nonatomic, copy) NSString *tvUID;
/** 接收端的IP地址 */
@property (nonatomic, copy) NSString *ipAddress;
/** 接收端包名 TV端乐播投屏apk的包名为com.hpplay.happyplay.aw，可在设备列表中判断receviverPackageName是否等于此包名，UI上可以加上推荐二字，用户的投屏体验更好*/
@property (nonatomic, copy) NSString *receviverPackageName;
/** 接收端是否有可升级的新版本 此属性是搜到TV端乐播投屏apk有新版可更新时，可提示用户升级接收端，体验更好*/
@property (nonatomic, assign) BOOL hasNewVersion;
/**（非必要的）别名，开发者可开放出来供用户修改服务名称的别名，方便用户自己识别和区分自己的服务 */
@property (nonatomic, copy) NSString *alias;
/**（非必要的）是否为常用 */
@property (nonatomic, assign, readonly, getter=isFrequentlyUsed) BOOL frequentlyUsed;
/** (非必要的)曾经连接过的服务 */
@property (nonatomic, assign, readonly, getter=isOnceConnected) BOOL onceConnected;
/** (非必要的)上次连接过的服务 */
@property (nonatomic, assign, readonly, getter=isLastTimeConnected) BOOL lastTimeConnected;
/** 是否从二维码获得的设备 */
@property (nonatomic, assign, readonly, getter=isFromQRCode) BOOL fromQRCode;

/**
 服务可用状态
 */
@property (nonatomic, assign, getter=isLelinkServiceAvailable,readonly) BOOL lelinkServiceAvailable;
@property (nonatomic, assign, getter=isInnerLelinkServiceAvailable, readonly) BOOL innerLelinkServiceAvailable;
@property (nonatomic, assign, getter=isUpnpServiceAvailable, readonly) BOOL upnpServiceAvailable;
@property (nonatomic, assign, getter=isImServiceAvailable, readonly) BOOL imServiceAvailable;

/**
 各类服务数据模型
 */
@property (nonatomic, strong) LBInnerLelinkDeviceModel *innerLelinkDevice;
@property (nonatomic, strong) LEBUPnPDevice *upnpDevice;
@property (nonatomic, strong) LBIMServiceModel *imDevice;


/**
 比较两个LelinkService是否是同一个

 @param object 被比较的对象
 @return YES：代表相同，NO：代表不相同
 */
- (BOOL)isEqualToLelinkService:(LBLelinkService *)object;

@end
