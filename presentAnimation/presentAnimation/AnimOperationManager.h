//
//  AnimOperationManager.h
//  presentAnimation
//
//  Created by 许博 on 16/7/28.
//  Copyright © 2016年 许博. All rights reserved.
//  新增动画管理类



#import <UIKit/UIKit.h>
#import "GiftModel.h"

@interface AnimOperationManager : NSObject
+ (instancetype)sharedManager;
@property (nonatomic,strong) UIView *parentView;
@property (nonatomic,strong) GiftModel *model;
/// 动画操作 : 需要UserID和回调
- (void)animWithUserID:(NSString *)userID model:(GiftModel *)model finishedBlock:(void(^)(BOOL result))finishedBlock;

/// 取消上一次的动画操作
- (void)cancelOperationWithLastUserID:(NSString *)userID;
@end
