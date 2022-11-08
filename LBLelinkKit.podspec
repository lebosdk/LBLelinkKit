Pod::Spec.new do |s|

# Root specification
  s.name         = "LBLelinkKit"
  s.version      = "31310"
  s.author            = {'lebosdk' => 'cm@hpplay.cn' }
  s.license      = 'MIT'
 # s.homepage     = 'https://github.com/lebosdk/LBLelinkKit'
  s.homepage     = 'https://github.com/lebosdk/LBLelinkKit'
  s.summary      = 'lebo ios framework LBLelinkKit'

  s.description      = <<-DESC
  It is marquee view used on iOS, which implement by Objective-C.
  DESC
  s.source       = { :git => "https://github.com/lebosdk/LBLelinkKit.git", :tag => "v#{s.version}" }

# Platform
  s.platform     = :ios, "9.0"

# Build settings
  s.requires_arc = true
  s.ios.libraries = 'xml2','resolv.9'
  s.xcconfig = { 'HEADER_SEARCH_PATHS' => '$(SDKROOT)/usr/include/libxml2' }
  s.xcconfig = { 'HEADER_SEARCH_PATHS' => '$(SDKROOT)/usr/include/libxml2' }

# File patterns
  #s.public_header_files = 'LBLelinkKit.framework/*.h'
  s.ios.vendored_frameworks = 'LBLelinkKit.framework'

end
