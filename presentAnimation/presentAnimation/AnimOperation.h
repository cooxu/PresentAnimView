//
//  AnimOperation.h
//  presentAnimation
//
//  Created by 许博 on 16/7/15.
//  Copyright © 2016年 许博. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PresentView.h"
#import "GiftModel.h"

@interface AnimOperation : NSOperation
@property (nonatomic,strong) PresentView *presentView;
@property (nonatomic,strong) UIView *listView;
@property (nonatomic,strong) GiftModel *model;
@property (nonatomic,assign) NSInteger index;
@property (nonatomic,copy) NSString *userID; // 新增用户唯一标示，记录礼物信息

// 回调参数增加了结束时礼物累计数 
+ (instancetype)animOperationWithUserID:(NSString *)userID model:(GiftModel *)model finishedBlock:(void(^)(BOOL result,NSInteger finishCount))finishedBlock;

@end
