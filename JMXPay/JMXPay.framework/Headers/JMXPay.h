//
//  JMXPay.h
//  JMXPay
//
//  Created by Chen Zhangli on 2020/9/8.
//  Copyright © 2020 Uniauto. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JMXPay/JMXOrder.h>
#import <JMXPay/JMXPrepay.h>

NS_ASSUME_NONNULL_BEGIN

/**
 支付平台

 - JMXPayPlatformAlipay:   支付宝(15.5.0)
 - JMXPayPlatformWechat:   微信(1.8.1)
 */
typedef NS_ENUM(NSUInteger, JMXPayPlatform) {
    JMXPayPlatformAlipay = 0,
    JMXPayPlatformWechat
};

/**
 支付结果

 - JMXPayResultSuccess: 支付成功
 - JMXPayResultFailure: 支付失败
 - JMXPayResultCancel:  用户取消
 */
typedef NS_ENUM(NSUInteger, JMXPayResult) {
    JMXPayResultSuccess = 0,
    JMXPayResultFailure,
    JMXPayResultCancel,
};


/**
 获取预支付信息

 @param prepay 预支付信息
 */
typedef void (^JMXFetchPrepayCallBack)(JMXPrepay * _Nullable prepay, NSError * _Nullable error);

/**
 预支付回调

 @param callback 获取预支付回调
 */
typedef void (^JMXPrepayCallback)(JMXFetchPrepayCallBack callback);


/**
 支付回调

 @param error  回调错误
 */
typedef void (^JMXPayResultCallback)(NSError *error);

@interface JMXPay : NSObject

+ (JMXPay *)defaultPay;

/**
 订单支付

 @param order                      订单信息
 @param platform                支付平台
 @param viewController   视图控制器
 @param prepayCallback    预支付处理
 @param completion            支付结果回调
 */
- (void)payOrder:(JMXOrder *)order
      onPlatform:(JMXPayPlatform)platform
  viewController:(UIViewController *)viewController
          prepay:(JMXPrepayCallback)prepayCallback
      completion:(JMXPayResultCallback)completion;

/**
 处理第三方应用

 @param url 处理地址
 */
- (void)handleOpenURL:(NSURL *)url;


/**
 SDK版本
*/
+ (NSString *)version;

@end

NS_ASSUME_NONNULL_END
