# PresentAnimView
## iOS 动画队列-仿映客刷礼物效果

基础使用Demo：参考控制其中的代码

1. 一个全局的队列，设置队列并发数，也就是将来想显示的列数

```
    NSOperationQueue *queue = [[NSOperationQueue alloc] init];
    queue.maxConcurrentOperationCount = 2; // 队列分发
    _queue = queue;

``` 

2. 在收到礼物消息的回调中遍历数据源，给自定义 AnimOperation 赋值

```
// 模拟收到礼物消息的回调
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    for (int i = 0; i < self.giftInfos.count; i++) {
        @autoreleasepool {
            
            NSLog(@"%@",[self.giftInfos[i] name]);
            
            AnimOperation *op = [[AnimOperation alloc] init]; // 初始化操作
            op.index = i; // 设置操作的 index
            op.listView = self.view; // 要添加到的父视图
            op.model = self.giftInfos[i]; // 数据源
            [_queue addOperation:op];
         
        }
    }
    
}

```

3. 控制列数和每个动画 view 位置的可以在 AnimOperation.m 中修改
```
_presentView.frame = CGRectMake(-self.listView.frame.size.width / 2, 300 - (_index % 2) * 70, self.listView.frame.size.width / 2, 40);
```
