//
//  LBLelinkBrowserViewController.h
//  sdkUI
//
//  Created by 涂清文 on 2021/7/5.
//

#import <UIKit/UIKit.h>
@class LBLelinkBrowserViewController ;
@class LBLelinkService ;
@class LBLelinkPlayer;
@class LBLelinkConnection;
@class LBLelinkPlayerItem ;

@protocol LBLelinkBrowserViewControllerDelegate <NSObject>

/// 将投屏到一个设备上的服务,返回NO将取消投屏,YES或未实现将投屏
/// @param browserViewController 投屏选择控制器
/// @param service 服务
@optional
- (BOOL)browserViewController:(LBLelinkBrowserViewController*)browserViewController willCastToService:(LBLelinkService*)service ;

/// 投屏成功
/// @param browserViewController 投屏选择控制器
/// @param player 投屏成功后返回的播控类，设置deleagte接收播放进度和状态等
- (void)browserViewController:(LBLelinkBrowserViewController*)browserViewController didCastToServiceWithPlayer:(LBLelinkPlayer*)player ;

/// 投屏过程中出现错误,不实现或返回NO 将显示SDK内部错误弹框,YES将由app处理具体错误
/// @param browserViewController 投屏选择控制器
/// @param error 错误信息
- (BOOL)browserViewController:(LBLelinkBrowserViewController*)browserViewController willDisplayError:(NSError *)error;

/// 没有网络权限的回调,不实现或返回NO 将显示SDK内部错误弹框,YES将由app处理具体错误
/// @param browserViewController 投屏选择控制器
- (BOOL)localNetworkPermissionsPolicyDeniedFromeBrowserViewController:(LBLelinkBrowserViewController*)browserViewController ;

/// UI 将返回上级页面,返回NO将阻止返回
/// @param browserViewController ...
- (BOOL)willBackBrowserViewController:(LBLelinkBrowserViewController*)browserViewController;

@end


@interface LBLelinkBrowserViewController : UIViewController

/// 投屏代理
@property (nonatomic,weak)id<LBLelinkBrowserViewControllerDelegate> delegate ;


/// 使用delegate进行回调和处理
/// @param delelgate 选择控制器delegate
/// @param item 播放源
-(instancetype)initWithDelegate:(id<LBLelinkBrowserViewControllerDelegate>)delelgate playItem:(LBLelinkPlayerItem*)item;


/// 不使用投屏代理,其他逻辑由sdk内部自动处理,投屏成功后通过block返回 播控类,取消 player 为 nil,
/// 便利方式,无其他特殊需求可使用,有其他更高定制需求或状态需求可以使用delegate
/// @param item 投屏的SDK
/// @param completer 投屏回调，player 投屏成功后返回的播控类，设置deleagte接收播放进度和状态等
+ (instancetype)playItem:(LBLelinkPlayerItem*)item completer:(void(^)(LBLelinkPlayer *player))completer ;

@end


