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
@end
