//
//  AnimOperation.m
//  presentAnimation
//
//  Created by 许博 on 16/7/15.
//  Copyright © 2016年 许博. All rights reserved.
//

#import "AnimOperation.h"
#define KScreenWidth [[UIScreen mainScreen] bounds].size.width

@interface AnimOperation ()
@property (nonatomic, getter = isFinished)  BOOL finished;
@property (nonatomic, getter = isExecuting) BOOL executing;
@end


@implementation AnimOperation

@synthesize finished = _finished;
@synthesize executing = _executing;

- (instancetype)init
{
    self = [super init];
    if (self) {
        _executing = NO;
        _finished  = NO;
        
        
    }
    return self;
}

- (void)start {
    // 添加到队列时调用
//    if (如果半天没消息或者取消了操作) { 
//        return
//    }
//    self.executing = YES;
//    [[NSOperationQueue mainQueue] addOperationWithBlock:^{
//        执行动画；
//        } completion:^(BOOL finished) {
//            self.finished = YES;
//            self.executing = NO;
//        }];
//    }];
    
    if ([self isCancelled]) {
        self.finished = YES;
        return;
    }
    self.executing = YES;
    
    [[NSOperationQueue mainQueue] addOperationWithBlock:^{
        
        _presentView = [[PresentView alloc] init];
        _presentView.model = _model;
        // i ％ 2 控制最多允许出现几行
        _presentView.frame = CGRectMake(-self.listView.frame.size.width / 2, 300 - (_index % 2) * 70, self.listView.frame.size.width / 2, 40);
        _presentView.originFrame = _presentView.frame;
        [self.listView addSubview:_presentView];
    
        [self.presentView animateWithCompleteBlock:^(BOOL finished) {
            self.finished = finished;
        }];

    }];
    
}

#pragma mark -  手动触发 KVO
- (void)setExecuting:(BOOL)executing
{
    [self willChangeValueForKey:@"isExecuting"];
    _executing = executing;
    [self didChangeValueForKey:@"isExecuting"];
}

- (void)setFinished:(BOOL)finished
{
    [self willChangeValueForKey:@"isFinished"];
    _finished = finished;
    [self didChangeValueForKey:@"isFinished"];
}

@end
