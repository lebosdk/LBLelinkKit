//
//  UIButton+LBUIButton.m
//  LBLelinkKitSample
//
//  Created by 刘明星 on 2018/8/14.
//  Copyright © 2018 深圳乐播科技有限公司. All rights reserved.
//

#import "UIButton+LBUIButton.h"

@implementation UIButton (LBUIButton)

+ (instancetype)buttonWithTitle:(nullable NSString *)title target:(nullable id)target action:(SEL)action {
    UIButton * btn = [[UIButton alloc] init];
    
    btn.backgroundColor = [UIColor colorWithRed:15.0 / 255.0 green:131.0 / 255.0 blue:1.0 alpha:1.0];
    [btn setTitle:title forState:UIControlStateNormal];
    btn.layer.cornerRadius = 4;
    btn.clipsToBounds = YES;
    [btn addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    
    return btn;
}

+ (instancetype)buttonWithTitle:(nullable NSString *)title target:(nullable id)target action:(SEL)action imageName:(nonnull NSString *)imageName {
    UIButton * btn = [[UIButton alloc] init];
    [btn setImage:[UIImage imageNamed:imageName] forState:UIControlStateNormal];
    [btn setTitle:title forState:UIControlStateNormal];
    btn.titleLabel.font = [UIFont systemFontOfSize:16];
    [btn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [btn addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    return btn;
}

@end
