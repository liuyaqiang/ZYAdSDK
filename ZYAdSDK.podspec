

Pod::Spec.new do |s|
s.name             = "ZYAdSDK"
s.version          = "1.5.2"
s.summary          = "ZYAdSDK"

s.description      = <<-DESC
AdSDK for ZY
DESC

s.homepage         = "https://github.com/liuyaqiang/ZYAdSDK.git"
s.license      = { :type => "MIT", :file => "LICENSE" }
s.author       = { "liuyaqiang" => "344257448@qq.com" }


s.platform     = :ios, '9.0'
s.source           = { :git => "https://github.com/liuyaqiang/ZYAdSDK.git", :tag => "#{s.version}" }
s.vendored_frameworks = 'ZYAdSDK.framework'
s.resource     = 'ZYAdSDK.bundle'
s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
s.dependency 'ZYCoreKit'
end
