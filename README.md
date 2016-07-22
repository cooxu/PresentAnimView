# PresentAnimView
## iOS 动画队列-仿映客刷礼物效果

基础使用Demo：参考控制其中的代码

一、 2个全局队列，也就是将来想显示的列数

```
    NSOperationQueue *queue1 = [[NSOperationQueue alloc] init];
    queue1.maxConcurrentOperationCount = 1; // 队列分发
    _queue1 = queue1;
    
    NSOperationQueue *queue2 = [[NSOperationQueue alloc] init];
    queue2.maxConcurrentOperationCount = 1; // 队列分发
    _queue2 = queue2;

``` 


二、 在收到礼物消息的回调中遍历数据源，给自定义 AnimOperation 赋值

```
// 模拟收到礼物消息的回调
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    for (int i = 0; i < self.giftInfos.count; i++) {
        @autoreleasepool {
            
            NSLog(@"%@",[self.giftInfos[i] name]);

            AnimOperation *op = [[AnimOperation alloc] init]; // 初始化操作
            op.listView = self.view;
            
            if (i % 2) {
                op.model = self.giftInfos[i];
                op.index = i;
                if (op.model.giftCount != 0) {
                    [_queue1 addOperation:op];
                }
            }else {
                op.index = i;
                op.model = self.giftInfos[i];
                if (op.model.giftCount != 0) {
                    [_queue2 addOperation:op];
                }
            }
 
        }
    }
  
}

```

三、 控制列数和每个动画 view 位置的可以在 AnimOperation.m 中修改
```

        // i ％ 2 控制最多允许出现几行
        if (_index % 2) {
            _presentView.frame = CGRectMake(-self.listView.frame.size.width / 2, 300, self.listView.frame.size.width / 2, 40);
        }else {
            _presentView.frame = CGRectMake(-self.listView.frame.size.width / 2, 230, self.listView.frame.size.width / 2, 40);
        }
        
```

![图片描述](http://upload-images.jianshu.io/upload_images/1441100-4103d8f46952ecf8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

思路： [简书](http://www.jianshu.com/p/119532a53dbd)

