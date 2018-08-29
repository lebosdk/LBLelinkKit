//
//  LBVideoPlayerViewController.m
//  LBLelinkKitSample
//
//  Created by 刘明星 on 2018/5/14.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import "LBVideoPlayerViewController.h"

@interface LBVideoPlayerViewController ()

@end

@implementation LBVideoPlayerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

// 是否支持设备自动旋转
- (BOOL)shouldAutorotate {
    return YES;
}

// 支持屏幕显示方向
- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight;
}

@end
