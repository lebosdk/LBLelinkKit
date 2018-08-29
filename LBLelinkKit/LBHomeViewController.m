//
//  LBHomeViewController.m
//  LBLelinkKitSample
//
//  Created by 刘明星 on 2018/5/14.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import "LBHomeViewController.h"

@interface LBHomeViewController ()<UIGestureRecognizerDelegate>

@end

@implementation LBHomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationController.interactivePopGestureRecognizer.delegate = self;
}

- (void)viewWillAppear:(BOOL)animated {
    self.navigationController.navigationBar.hidden = YES;
}

- (void)viewDidDisappear:(BOOL)animated {
    self.navigationController.navigationBar.hidden = NO;
}

// 是否支持设备自动旋转
- (BOOL)shouldAutorotate {
    return NO;
}

// 支持屏幕显示方向
- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}


@end
