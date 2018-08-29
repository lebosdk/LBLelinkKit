//
//  LBNavigationViewController.m
//  LBLelinkKitSample
//
//  Created by 刘明星 on 2018/5/14.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import "LBNavigationViewController.h"

@interface LBNavigationViewController ()

@end

@implementation LBNavigationViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

// 是否支持设备自动旋转
- (BOOL)shouldAutorotate {
    return self.topViewController.shouldAutorotate;
}

// 支持屏幕显示方向
- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return [self.topViewController supportedInterfaceOrientations];
}

@end
