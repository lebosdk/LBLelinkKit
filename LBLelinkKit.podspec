Pod::Spec.new do |s|
  s.name         = "LBLelinkKit"
  s.version      = "1.0.7"
  s.summary      = "lebo ios framework LBLelinkKit"
  s.homepage     = "https://github.com/lebo123/LBLelinkKit"
  s.license      = "MIT"
  s.authors            = { "lebosdk" => "cm@hpplay.cn" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/lebo123/LBLelinkKit.git", :tag => "#{s.version}" }
  s.source_files  ='LBLelinkKit.framework/**/*' 
  s.requires_arc = true
  s.vendored_frameworks = 'Frameworks/MyFramework.framework'
  s.libraries	 = 'libxml2.tbd'
end
