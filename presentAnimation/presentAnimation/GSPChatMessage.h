//
//  GSPChatMessage.h
//  presentAnimation
//
//  Created by 潘涯 on 16/7/28.
//  Copyright © 2016年 许博. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GSPChatMessage : NSObject

@property (nonatomic,retain) NSString *senderName;
@property (nonatomic,retain) NSString *text;
@property (nonatomic,retain) NSString *senderChatID;

@end
