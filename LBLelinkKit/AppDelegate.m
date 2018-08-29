//
//  AppDelegate.m
//  LBLelinkKitSample
//
//  Created by 刘明星 on 2018/5/12.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import "AppDelegate.h"
#import "LBHomeViewController.h"
/**
 step 1: 导入头文件
 */
#import <LBLelinkKit/LBLelinkKit.h>

/**
 step 2: 到乐播官网注册账号，并添加APP，获取APPid和密钥
 */
NSString * const LBAPPID = @"20";
NSString * const LBSECRETKEY = @"a20b4b19e6da15f95464af0e4aa59564";

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    /**
     step 3: 是否打开log，默认是关闭的
     */
    [LBLelinkKit enableLog:YES];
    
    /**
     step 4: 使用APP id 和密钥授权授权SDK
     注意：（1）需要在Info.plist中设置ATS；（2）可以异步执行，不影响APP的启动
     */
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSError * error = nil;
        BOOL result = [LBLelinkKit authWithAppid:LBAPPID secretKey:LBSECRETKEY error:&error];
        if (result) {
            NSLog(@"授权成功");
        }else{
            NSLog(@"授权失败：error = %@",error);
        }
    });
    
    
    
    LBHomeViewController * homeVc = [[LBHomeViewController alloc] init];
    UINavigationController * nav = [[UINavigationController alloc] initWithRootViewController:homeVc];
    self.window = [[UIWindow alloc] init];
    self.window.rootViewController = nav;
    [self.window makeKeyAndVisible];
    
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
