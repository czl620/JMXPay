//
//  JMXPrepay.h
//  JMXPay
//
//  Created by Chen Zhangli on 2020/9/8.
//  Copyright © 2020 Uniauto. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JMXPrepay : NSObject

- (instancetype)initWithScheme:(NSString *)scheme;

@property (nonatomic, copy) NSString *prepayInfo;

@property (nonatomic, copy) NSString *scheme;

@property (nonatomic, copy) NSString *package;
@property (nonatomic, copy) NSString *openID;
@property (nonatomic, copy) NSString *partnerId;
@property (nonatomic, copy) NSString *nonceStr;
@property (nonatomic, assign) UInt32 timeStamp;
@property (nonatomic, copy) NSString *sign;

@end

NS_ASSUME_NONNULL_END
