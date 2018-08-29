//
//  LBHomeBaseView.h
//  LBLelinkKitSample
//
//  Created by 刘明星 on 2018/8/14.
//  Copyright © 2018 深圳乐播科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class LBHomeBaseView;

@protocol LBHomeBaseViewDelegate <NSObject>

@optional
- (void)homeBaseView:(LBHomeBaseView *)homeBaseView deviceLisetBtnClicked:(UIButton *)button;
- (void)homeBaseView:(LBHomeBaseView *)homeBaseView castScreenBtnClicked:(UIButton *)button;

- (void)homeBaseView:(LBHomeBaseView *)homeBaseView castOnlineVideoSingleBtnClicked:(UIButton *)button;
- (void)homeBaseView:(LBHomeBaseView *)homeBaseView castOnlineVideoSerialBtnClicked:(UIButton *)button;
- (void)homeBaseView:(LBHomeBaseView *)homeBaseView castOnlineAudioBtnClicked:(UIButton *)button;
- (void)homeBaseView:(LBHomeBaseView *)homeBaseView castOnlinePhotoBtnClicked:(UIButton *)button;

- (void)homeBaseView:(LBHomeBaseView *)homeBaseView castLocalVideoBtnClicked:(UIButton *)button;
- (void)homeBaseView:(LBHomeBaseView *)homeBaseView castLocalAudioBtnClicked:(UIButton *)button;
- (void)homeBaseView:(LBHomeBaseView *)homeBaseView castLocalPhotoBtnClicked:(UIButton *)button;

@end

@interface LBHomeBaseView : UIView

@property (nonatomic, weak) id<LBHomeBaseViewDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
