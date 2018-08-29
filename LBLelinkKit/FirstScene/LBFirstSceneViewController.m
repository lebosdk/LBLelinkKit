//
//  LBFirstSceneViewController.m
//  LBLelinkKitSample
//
//  Created by 刘明星 on 2018/5/14.
//  Copyright © 2018年 深圳乐播科技有限公司. All rights reserved.
//

#import "LBFirstSceneViewController.h"
#import "LBFirstSceneTableViewCell.h"
#import "LBFirstSceneTableViewCellModel.h"
#import "LBVideoPlayerViewController.h"

NSString * const LBFirstSceneTableViewCellID = @"LBFirstSceneTableViewCellID";

@interface LBFirstSceneViewController ()<UITableViewDelegate, UITableViewDataSource>

@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (nonatomic, strong) NSArray *models;


@end

@implementation LBFirstSceneViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.titleLabel.text = @"先连接，浏览内容，再投屏";
    [self.tableView registerClass:[LBFirstSceneTableViewCell class] forCellReuseIdentifier:LBFirstSceneTableViewCellID];
    self.tableView.tableFooterView = [[UIView alloc] init];
    self.tableView.contentInset = UIEdgeInsetsMake(16, 0, 0, 0);
}

- (IBAction)backBtnClicked:(UIButton *)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.models.count;
}

- (LBFirstSceneTableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    LBFirstSceneTableViewCell * cell = (LBFirstSceneTableViewCell *)[tableView dequeueReusableCellWithIdentifier:LBFirstSceneTableViewCellID forIndexPath:indexPath];
    
    LBFirstSceneTableViewCellModel * model = self.models[indexPath.row];
    cell.model = model;
    
    return cell;
}

#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 218.5;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
    return 35;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section {
    UILabel * sectionHeader = [[UILabel alloc] init];
    sectionHeader.textColor = [UIColor blackColor];
    /*
     UIFontDescriptorFamilyAttribute：设置字体家族名
     UIFontDescriptorNameAttribute  ：设置字体的字体名
     UIFontDescriptorSizeAttribute  ：设置字体尺寸
     */
    UIFontDescriptor *attributeFontDescriptor = [UIFontDescriptor fontDescriptorWithFontAttributes:
                                                 @{UIFontDescriptorFamilyAttribute: @"PingFangSC",
                                                   UIFontDescriptorNameAttribute:@"PingFangSC-Medium",
                                                   UIFontDescriptorSizeAttribute: @25.0
                                                   }];
    sectionHeader.font = [UIFont fontWithDescriptor:attributeFontDescriptor size:0.0];
    sectionHeader.text = @"  单个视频推送";
    return sectionHeader;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
}

#pragma mark - setter & getter

- (NSArray *)models{
    if (_models == nil) {
        LBFirstSceneTableViewCellModel * model1 = [[LBFirstSceneTableViewCellModel alloc] init];
        model1.imageName = @"Group Copy";
        model1.name = @"天赋异禀.avi";
        LBFirstSceneTableViewCellModel * model2 = [[LBFirstSceneTableViewCellModel alloc] init];
        model2.imageName = @"Group Copy 2";
        model2.name = @"神奇女侠.avi";
        _models = @[model1,model2];
    }
    return _models;
}

@end
