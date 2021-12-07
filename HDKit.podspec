

Pod::Spec.new do |s|
# 框架名
  s.name             = 'HDKit'
  s.version          = '1.0.0'
#  简要描述
  s.summary          = '个人调用工具类，播放器'
  # 描述
  s.description      = <<-DESC
  自己定义的播放器，附带3中类型的UI可选，基于FFmpeg与VLC,使用时可以自由选择
                       DESC
  # 页面链接
  s.homepage         = 'https://github.com/peisonglin/HDKit'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  #开源协议
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  #作者
  s.author           = { 'PSL' => '345455211@qq.com' }
  #定义平台
  spec.platform = :ios
  
  #支持的iOS最小版本
  spec.ios.deployment_target = '9.0'
  
  s.source           = { :git => 'https://github.com/peisonglin/HDKit.git', :tag => s.version.to_s }


  #是否启用ARC模式
  spec.requires_arc = true
  
  #是否启用静态库.framework (Podfile文件中防止使用use_frameworks!----表示强制pod集成时.a文件转framwork的动态库 )
  spec.static_framework=true

  #  告诉pod该库支持平台，默认时全部，加上这个key可以解决验证的时候 normal arm64 的问题
  #  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64 i386' }
  #  code12之后，模拟器也支持arm64架构 normal arm64 的问题
  spec.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.framework  = 'AVFoundation','UIKit'
  
  
  # HDObject.framework
     spec.subspec 'Main' do |s|
       
         s.source_files = 'HDKit/Classes/HDKit/HDKit.framework/Headers/*.h'
         s.vendored_frameworks='HDKit/Classes/HDKit/HDKit.framework'
         s.public_header_files = 'HDKit/Classes/HDKit/HDKit.framework/Headers/*.h'
#         s.framework  = 'AVFoundation','UIKit','CoreTelephony','Photos'
#         s.library   = "iconv"
     end

  #   ffmpeg 命令行库
     spec.subspec 'Base' do |s|
       
       s.source_files = 'HDKit/Classes/HDKitBase/HDKitBase.framework/Headers/*.h'
       s.vendored_frameworks='HDKit/Classes/HDKitBase/HDKitBase.framework'
       s.public_header_files = 'HDKit/Classes/HDKitBase/HDKitBase.framework/Headers/*.h'
       s.framework  ='CoreTelephony','Photos'
       s.library    = "iconv"
       
     end
     
     
     spec.subspec 'Player' do |s|
       
       s.source_files = 'HDKit/Classes/HDKitPlayer/HDKitPlayer.framework/Headers/*.h'
       s.vendored_frameworks='HDKit/Classes/HDKitPlayer/HDKitPlayer.framework'
       s.public_header_files = 'HDKit/Classes/HDKitPlayer/HDKitPlayer.framework/Headers/*.h'
       s.library   = "iconv","z","bz2"
       s.framework  = 'CoreTelephony','Photos','CoreMedia','VideoToolbox','AudioToolbox'
       #       s.resources = 'HDObject/Assets/HDFFMpeg/*.bundle'
       #  项目库中使用的其他第三方库，多个用“,”分开
       s.dependency 'HDKit/Main'
       s.dependency 'MobileVLCKit','3.3.16.3'
       s.dependency 'Masonry','~> 1.1.0'
       s.dependency 'ReactiveObjC','~> 3.1.1'
#       s.dependency 'FMDB','~> 2.7.5'
     end
     
  
  spec.default_subspecs = 'Main','Base','Player'
  
  
  
end
