Gem::Specification.new do |spec|
  spec.name              = 'fastlz'
  spec.version           = '0.1.0'
  spec.summary           = 'Ruby bindings for FastLZ.'
  spec.files             = Dir.glob('ext/*') + %w(README)
  spec.author            = 'winebarrel'
  spec.email             = 'sgwr_dts@yahoo.co.jp'
  spec.homepage          = 'https://bitbucket.org/winebarrel/fastlz-ruby'
  spec.extensions        = 'ext/extconf.rb'
  spec.has_rdoc          = true
  spec.extra_rdoc_files  = %w(README ext/fastlz-ruby.c)
end
