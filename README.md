# PresentAnimView
## iOS 动画队列-仿映客刷礼物效果

基础使用Demo：参考控制其中的代码

一、 将IM消息解析成礼物消息，拼出礼物 model

```
// 礼物模型
    GiftModel *giftModel = [[GiftModel alloc] init];
    giftModel.headImage = [UIImage imageNamed:@"luffy"];
    giftModel.name = msg.senderName;
    giftModel.giftImage = [UIImage imageNamed:@"flower"];
    giftModel.giftName = msg.text;
    giftModel.giftCount = 1;

``` 


二、 创建礼物管理类，设置礼物父视图

```
// 单例
AnimOperationManager *manager = [AnimOperationManager sharedManager];
manager.parentView = self.view;


```


三、 开始动画

```

// 用用户唯一标识 msg.senderChatID 存礼物信息,model 传入礼物模型
[manager animWithUserID:[NSString stringWithFormat:@"%@",msg.senderChatID] model:giftModel finishedBlock:^(BOOL result) {     
    }];        
    
```

![Demo模拟了n个人同时送礼物](http://upload-images.jianshu.io/upload_images/1441100-9d0691e21ef0fcaf.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

思路： [iOS 动画队列-仿映客刷礼物效果](http://www.jianshu.com/p/119532a53dbd)

完善思路： [iOS 基于 IM 实现仿映客刷礼物连击效果](http://www.jianshu.com/p/714fb05d6fa5)

