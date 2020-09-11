//
//  JMXOrder.h
//  JMXPay
//
//  Created by Chen Zhangli on 2020/9/8.
//  Copyright © 2020 Uniauto. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMXPrepay.h"

NS_ASSUME_NONNULL_BEGIN

@interface JMXOrder : NSObject

// 订单号
@property (nonatomic, copy) NSString *orderNO;
// 订单总金额
@property (nonatomic, copy) NSString *totalAmount;
// 预支付信息
@property (nonatomic, strong) JMXPrepay *prepay;

@end

NS_ASSUME_NONNULL_END
