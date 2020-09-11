Pod::Spec.new do |s|

#名称
s.name         = 'JMXPay'

#版本号
s.version      = '0.0.2'

#许可证
s.license      = { :type => 'MIT' }

#项目主页地址
s.homepage     = 'https://github.com/czl620/JMXPay'

#作者
s.authors      = { 'czl620' => '893419255@qq.com' }

#简介
s.summary      = 'A Pay framework for iOS.'

#项目的地址 （注意这里的tag位置，可以自己写也可以直接用s.version，但是与s.version一定要统一）
s.source       = { :git => 'https://github.com/czl620/JMXPay.git', :tag => s.version }

#支持最小系统版本
s.platform     = :ios, '8.0'

#需要包含的源文件
s.source_files = 'JMXPay/JMXPay.framework/Headers/*.{h}'

#你的SDK路径
s.vendored_frameworks = 'JMXPay/JMXPay.framework'

#SDK头文件路径
s.public_header_files = 'JMXPay/JMXPay.framework/Headers/JMXPay.h'


#依赖库
s.frameworks   = 'UIKit','Foundation'

#s.default_subspecs = 'Alipay', 'Wechat'

s.pod_target_xcconfig = { 'VALID_ARCHS[sdk=iphonesimulator*]' => ''

#支付宝
s.subspec 'Alipay' do |ss|

   ss.source_files = 'JMXPay/Vendors/Alipay/AlipaySDK.framework/Headers/*.h'
   ss.public_header_files = 'JMXPay/Vendors/Alipay/AlipaySDK.framework/Headers/*.h'
   ss.resources = 'JMXPay/Vendors/Alipay/AlipaySDK.bundle'
   ss.vendored_frameworks =  'JMXPay/Vendors/Alipay/AlipaySDK.framework'

   ss.frameworks = 'CFNetwork', 'CoreMotion', 'CoreGraphics', 'CoreTelephony', 'CoreText', 'Foundation', 'UIKit', 'SystemConfiguration',  'WebKit'
   ss.libraries = 'z', 'c++'

 end


#微信
 s.subspec 'Wechat' do |ss|

   ss.source_files = 'JMXPay/Vendors/Wechat/*.h'
   ss.public_header_files = 'JMXPay/Vendors/Wechat/*.h'


   ss.frameworks = 'Foundation', 'UIKit', 'SystemConfiguration', 'Security', 'CoreTelephony', 'CFNetwork'
   ss.libraries = 'z', 'sqlite3.0', 'c++'

   ss.requires_arc = true
   ss.vendored_libraries = 'JMXPay/Vendors/Wechat/libWeChatSDK.a'

 end

end
