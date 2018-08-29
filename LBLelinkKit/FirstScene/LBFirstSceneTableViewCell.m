//
//  LBFirstSceneTableViewCell.m
//  LBLelinkKitSample
//
//  Created by 刘明星 on 2018/5/15.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import "LBFirstSceneTableViewCell.h"
#import "LBFirstSceneTableViewCellModel.h"

@interface LBFirstSceneTableViewCell ()

@property (nonatomic, strong) UIView *bgView;
@property (nonatomic, strong) UIImageView * bgImageView;
@property (nonatomic, strong) UIView *coverView;
@property (nonatomic, strong) UILabel *nameLabel;

@end

@implementation LBFirstSceneTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        [self add];
        self.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    [self setUI];
}

#pragma mark - private

- (void)add {
    [self.bgView addSubview:self.bgImageView];
    [self.bgView addSubview:self.coverView];
    [self.bgView addSubview:self.nameLabel];
    
    [self.contentView addSubview:self.bgView];
}

- (void)setUI {
    
    CGFloat width = self.contentView.frame.size.width;
    CGFloat height = self.contentView.frame.size.height;
    
    self.bgView.frame = CGRectMake(17.5, 5, width - 17.5 * 2, height - 35);
    self.bgImageView.frame = self.bgView.bounds;
    
    self.coverView.frame = CGRectMake(0, self.bgView.frame.size.height - 35, self.bgView.frame.size.width, 35);
    self.nameLabel.frame = CGRectMake(10, self.bgView.frame.size.height - 35, self.bgView.frame.size.width - 10, 35);
    
    
    self.bgView.layer.shadowColor = [UIColor blackColor].CGColor;
    self.bgView.layer.shadowOpacity = 0.3;
    self.bgView.layer.shadowOffset = CGSizeMake(0, 7);
    self.bgView.layer.shadowRadius = 12;
}

#pragma mark - getter & setter

- (UIView *)bgView{
    if (_bgView == nil) {
        _bgView = [[UIView alloc] init];
        _bgView.layer.cornerRadius = 2;
    }
    return _bgView;
}

- (UIImageView *)bgImageView{
    if (_bgImageView == nil) {
        _bgImageView = [[UIImageView alloc] init];
    }
    return _bgImageView;
}

- (UIView *)coverView{
    if (_coverView == nil) {
        _coverView = [[UIView alloc] init];
        _coverView.backgroundColor = [UIColor blackColor];
        _coverView.alpha = 0.3;
    }
    return _coverView;
}

- (UILabel *)nameLabel{
    if (_nameLabel == nil) {
        _nameLabel = [[UILabel alloc] init];
        _nameLabel.font = [UIFont systemFontOfSize:13];
        _nameLabel.textColor = [UIColor whiteColor];
    }
    return _nameLabel;
}

- (void)setModel:(LBFirstSceneTableViewCellModel *)model {
    _model = model;
    
    self.bgImageView.image = [UIImage imageNamed:model.imageName];
    self.nameLabel.text = model.name;
}

- (void)setHighlighted:(BOOL)highlighted {
    
}

@end
