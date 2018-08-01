//
//  FMBaseTableViewController.h
//  testObject
//
//  Created by Windy on 2016/10/21.
//  Copyright © 2016年 Windy. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, FMTableViewStyle) {
    FMTableViewStylePlain,          // regular table view
    FMTableViewStyleGrouped         // preferences style table view
};

//typedef NS_ENUM(NSInteger, FMControllerStyle) {
//    FMTableViewControllerStyle,
//    FMViewControllerStyle
//};

@protocol BaseTableViewDelegate <NSObject>
/** 一直拖拽时的y计算返回 */
- (void)tableViewContentOffset:(CGFloat)tableViewY withTableView:(UITableView *)tableView;
/** 惯性滑动停止的y计算 */
- (void)tableViewDidEndDragging:(UITableView *)tableView withContentOffset:(CGFloat)offsetY;
- (CGFloat)tableViewContentInsetOfTopWith:(UITableView *)tableView;
/** tableView最终停止滑动 */
- (void)tableViewDidEndDecelerating:(UITableView *)tableView;
@end

@interface FMBaseTableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>
/** tableView */
@property (nonatomic, strong) UITableView *tableView;
/** tableView Style */
@property (nonatomic, assign)  FMTableViewStyle tableViewStyle;
/** controller Style */
//@property (nonatomic, assign) FMControllerStyle controllerStyle;
@property (nonatomic, weak) id <BaseTableViewDelegate> delegate;

- (instancetype)initWithTableViewStyle:(FMTableViewStyle)tableViewStyle;

@end