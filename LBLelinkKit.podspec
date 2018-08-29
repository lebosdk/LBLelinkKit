Pod::Spec.new do |s|
  s.name         = "LBLelinkKit"
  s.version      = "1.0.1"
  s.summary      = "lebo ios framework LBLelinkKit"
  s.homepage     = "https://github.com/lebo123/LBLelinkKit"
  s.license      = "MIT"
  s.authors            = { "lebo123" => "cm@hpplay.cn" }
  s.platform     = :ios, "5.0"
  s.source       = { :git => "https://github.com/lebo123/LBLelinkKit.git", :tag => "#{s.version}" }
  s.source_files  ='LBLelinkKit.framework/**/*' 
  s.requires_arc = true
end
