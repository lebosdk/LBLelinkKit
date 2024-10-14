//
//  LBDefine.h
//  Pods
//
//  Created by wangzhijun on 2021/11/5.
//

#ifndef LBDefine_h
#define LBDefine_h

// 支持Airplay投屏
#define LCLINKFP 0
// 不采集IDFA，0:采集，1:不采集，默认0
#define NOTUSEADID 0
// 儿童类应用配置，不采集设备信息，0:非儿童应用，1:儿童应用，采集设备信息，默认0
#define CHILDRENAPP 0
// 海外域名，0:非海外，1:海外，默认0
#define OVERSEAS 0
// 使用超声波 0:不启用超声波，1:启用超声波，默认0
#define ULTRASOUND 0
// 使用蓝牙 0:不启用蓝牙，1:启用蓝牙，默认1
#define BLUETOOTH 1
// License授权限制 0:不启用License授权，1:启用License授权，默认0
#define LICENSEAUTH 1
// 精简版SDK 0:不启用精简版代码逻辑 1:启用精简版代码逻辑，默认0
#define SIMPLIFY 0
// 云镜像模块限制，默认0
#define CLOUDMODULELIMIT 0
// 云镜像权益控制开关，1:有权益才可能云镜像 0:可直接云镜像,(云模块不限制才能生效)，默认0
#define CLOUDRIGHTSCONTROL 0
// 打开SSL双向认证，对外sdk不打开，内部APP使用，按需打开，默认0
#define OPENHTTPSSSL 0
// 反诈骗开关，内部APP使用，按需打开，默认0
#define OPENANTIFRAUD 0

#endif /* LBDefine_h */
