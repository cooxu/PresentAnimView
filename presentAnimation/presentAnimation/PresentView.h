//
//  PresentView.h
//  presentAnimation
//
//  Created by 许博 on 16/7/14.
//  Copyright © 2016年 许博. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ShakeLabel.h"
#import "GiftModel.h"

typedef NS_ENUM(NSInteger,PresentViewGiftType) {
    // 送鲜花
    PresentViewGiftTypeFlower,
    // 送蘑菇
    PresentViewGiftTypeMogu,
    // 送房子
    PresentViewGiftTypeHouse
};
typedef void(^completeBlock)(BOOL finished);

@interface PresentView : UIView
@property (nonatomic,strong) GiftModel *model;
@property (nonatomic,strong) UIImageView *headImageView; // 头像
@property (nonatomic,strong) UIImageView *giftImageView; // 礼物
@property (nonatomic,strong) UILabel *nameLabel; // 送礼物者
@property (nonatomic,strong) UILabel *giftLabel; // 礼物名称
@property (nonatomic,assign) NSInteger giftCount; // 礼物个数

@property (nonatomic,strong) ShakeLabel *skLabel;
@property (nonatomic,assign) NSInteger animCount; // 动画执行到了第几次
@property (nonatomic,assign) CGRect originFrame; // 记录原始坐标
@property (nonatomic,assign,getter=isFinished) BOOL finished;
- (void)animateWithCompleteBlock:(completeBlock)completed;


@end
